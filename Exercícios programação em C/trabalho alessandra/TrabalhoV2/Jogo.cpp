#include "Jogo.h"
#include "Display.h"
#include "Conteudo.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Mover.h"
#include "Laser.h"

#include <iostream>

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::start(Display& display, Conteudo& conteudo, Jogador& jogador)
{
    //Initialize SDL
    if (!display.init())
    {
        printf("Falha ao inicializar.", SDL_GetError());
    }
    else
    {
        //Load all media
        if (!conteudo.load(display))
        {
            printf("Conteudo", SDL_GetError());
        }
        else
        {
            SDL_Event e; 

            std::vector<Inimigo> inimigos; //Holds all enemies
            std::vector<Laser> jogadorLasers; //Holds all of player lasers
            std::vector<Laser> inimigoLasers;

            addInimigo(inimigos); //Adds enemies to the game
            //Begin game loop
            while (!sair)
            {
                //Event management
                while (SDL_PollEvent(&e) != 0)
                {
                    if(e.type == SDL_KEYDOWN)
                    { 
                        jogador.movimento(e);
                    }
                    if (e.type == SDL_MOUSEBUTTONDOWN)
                    {
                       jogador.shoot(jogadorLasers);
                    }
                }

                //Shoot
                inimigoTiro(inimigos, inimigoLasers);

                //Movement
                jogador.movimentoBounds();
                moverLasers(jogadorLasers, inimigoLasers);
                moverInimigos(inimigos);

                //Collision detection
                checkColisoes(jogador, inimigos, jogadorLasers, inimigoLasers);

                //Check game over

				sair = checkGameOver(inimigos);
                //Render
                display.render(conteudo, jogador, inimigos, jogadorLasers, inimigoLasers);



                //Simulate 60 fps - Read on tutorial, not entirely sure if this is ok. 
                SDL_Delay(16);
            }
        }
    }
}

void Jogo::addInimigo(std::vector<Inimigo>& inimigos)
{
    int nascXPos = 100;
    int novoNascXPos = 100; 
    int nascYPos = 150;
    int inimigoLargura = 50;
    int inimigoAltura = 50;
    int numInimigos = 6;
    int moverVelocidade = 3;

    for (int i = 0; i < numInimigos; i++)
    {
        inimigos.push_back(Inimigo({ nascXPos, nascYPos, inimigoLargura, inimigoAltura }, moverVelocidade, MoverDirecao::LEFT));
        nascXPos += novoNascXPos; //Spawns enemies along a row
    }
}

void Jogo::moverInimigos(std::vector<Inimigo>& inimigos)
{
    int novoYPos = 20; //Move enemies down everytime they hit a wall
    for (auto &inimigo : inimigos)
    {
        //Move Left
        if (inimigo.m_dir == MoverDirecao::LEFT)
        {
            inimigo.m_pos.x -= inimigo.m_movimentoVelocidade;
            //If an enemy has exceeded allowed bounds, change direction
            if (inimigo.m_pos.x < inimigo.MIN_X_POS)
            {
                for (auto &i : inimigos)
                {
                    i.m_dir = MoverDirecao::DIREITA;
                    i.m_pos.y += novoYPos;
                }

            }
        }
        //Move Right
        if (inimigo.m_dir == MoverDirecao::RIGHT)
        {
            inimigo.m_pos.x += inimigos.moverVelocidade;
            //If enemy exceeds allowed bounds, change direction
            if (inimigos.m_pos.x > inimigos.MAX_X_POS)
            {
                for(auto &i : inimigo)
                { 
                    i.m_dir = MoverDirecao::LEFT;
                    i.m_pos.y += novoYPos;
                }
            }
        }
    }
}

void Jogo::moverLasers(std::vector<Laser>& jogadorLasers, std::vector<Laser>& inimigosLasers)
{
    //Movement of player lasers
    for (auto &jogadorLaser : jogadorLasers)
    {
        if (jogadorLaser.m_dir == MoverDirecao::UP)
        {
            jogadorLaser.m_pos.y -= jogadorLaser.m_moverVelocidade;
        }
    }
    //Movement of enemy lasers
    for (auto &InimigoLaser : inimigosLasers)
    {
        if (inimigoLaser.m_dir == MoverDirecao::BAIXO)
        {
            inimigoLaser.m_pos.y += inimigoLaser.m_moverVelocidade;
        }
    }
}

void Jogo::checkColisoes(Jogador& jogador, std::vector<Inimigo>& inimigos, std::vector<Laser>& jogadorLasers, std::vector<Laser>& inimigosLasers)
{
    //checkCollisions(player, enemies, playerLasers, enemyLasers);
    //Check for playerLaser/Enemy collision
    for (int jogadorLaser = 0; jogadorLaser < jogadorLasers.size(); jogadorLaser++)
    {
        for (int inimigo = 0; inimigo < inimigos.size(); inimigo++)
        {
            //If collision has been detected, delete both playerLaser and Enemy
            if (achaJogadorLaserColisoes(jogadorLasers[jogadorLaser], inimigos[inimigo]))
            {
                printf("Colisoes");
                jogadorLasers.erase(jogadorLasers.begin() + jogadorLaser);
                inimigos.erase(inimigos.begin() + inimigo);

                return;
            }
        }
    }
    for (int inimigoLaser = 0; inimigoLaser < inimigosLasers.size(); inimigoLaser++)
    {
        if (achaInimigoLaserColisoes(inimigosLasers[inimigoLaser], jogador))
        {
            printf("Colisoes do jogador");
            inimigosLasers.erase(inimigosLasers.begin() + inimigoLaser);
            return;
        }
    }

    //No collisions detected
}

bool Jogo::achaJogadorLaserColisoes(Laser& jogadorLaser, Inimigo& inimigo)
{
    //Player laser collisions
    int jogadorLaserEsquerda = jogadorLaser.m_pos.x;
    int jogadorLaserDireita = jogadorLaser.m_pos.x + jogadorLaser.m_pos.w;
    int jogadorLaserCima = jogadorLaser.m_pos.y;
    int jogadorLaserBaixo = jogadorLaser.m_pos.y + jogadorLaser.m_pos.h;

    //Enemy collisions
    int inimigoEsquerda = inimigo.m_pos.x;
    int inimigoDireita = inimigo.m_pos.x + inimigo.m_pos.w;
    int inimigoCima = inimigo.m_pos.y;
    int inimigoBaixo = inimigo.m_pos.y + inimigo.m_pos.h;

    //Check for collisions
    if (jogadorLaserDireita < inimigoEsquerda) {
        return false;
    }
    if (jogadorLaserEsquerda > inimigoDireita) {
        return false;
    }
    if (jogadorLaserCima > inimigoBaixo) {
        return false;
    }
    if (jogadorLaserBaixo < inimigoCima) {
        return false;
    }

    //If collision
    return true;
}

bool Jogo::achaInimigoLaserColisoes(Laser & laser, Jogador & jogador)
{

    //Player Collisions
    int jogadorEsquerda = jogador.getPositionX();
    int jogadorDireita = jogador.getPositionX() + jogador.getWidth();
    int jogadorCima = jogador.getPositionY();
    int jogadorBaixo = jogador.getPositionY() + jogador.getHeight();

    //EnemyLaser Collision
    int laserEsquerda = laser.m_pos.x;
    int laserDireita = laser.m_pos.x + laser.m_pos.w;
    int laserCima = laser.m_pos.y;
    int laserBaixo = laser.m_pos.y + laser.m_pos.h;

    //Detect collisions
    if (jogadorEsquerda > laserDireita) {
        return false;
    }
    if (jogadorDireita < laserEsquerda) {
        return false;
    }
    if (jogadorCima > laserBaixo) {
        return false;
    }
    if (jogadorBaixo < laserCima) {
        return false;
    }
    //Collision
    return true;
}



bool Jogo::checkGameOver(std::vector<Inimigo>& inimigos)
{
    if (inimigos.size() == 0)
    {
        printf("Game Over!");
        return true;
    }
    return false;
}

void Jogo::inimigoTiro(std::vector<Inimigo>& inimigos, std::vector<Laser>& inimigosLasers)
{
    //If any enemies are alive.
    if (inimigos.size() > 0)
    {
        Uint32 startTime = SDL_GetTicks();
        int randInimigo = rand() % inimigos.size();

        //Starting position of laser
        int startXPos = inimigos[randInimigo].m_pos.x;
        int startYPos = inimigos[randInimigo].m_pos.y;
        //Size of laser
        int sizeLargura = 25;
        int sizeAltura = 50;
        //Movement speed of laser
        int movementSpeed = 8;
        //Direction of laser
        MoverDirecao dir = MoverDirecao::BAIXO;

        if (startTime % 125 == 0)
        {
            inimigosLasers.push_back(Laser({ startXPos, startYPos, sizeWidth, sizeHeight }, moverVelocidade, dir));
        }
    }
}