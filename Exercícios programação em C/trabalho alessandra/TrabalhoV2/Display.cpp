#include "Display.h"
#include "Conteudo.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Laser.h"


#include <iostream>
#include <vector>

Display::Display()
{
    //init();
}


Display::~Display()
{

}

bool Display::init()
{
    bool sucesso = true;
    //Initialize SDL Video
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        sucesso = false;
        printf("Inicializacao de video falhou!.", SDL_GetError());
    }
    else
    {
        //Create Window
        janela = SDL_CreateWindow("Batalha campal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, TELA_LARGURA, TELA_ALTURA, SDL_WINDOW_SHOWN);
        if (janela == nullptr)
        {
            sucesso = false;
            printf("Falha ao criar a janela.", SDL_GetError());
        }
        else
        {
            //Get the window surface
            superficieJanela = SDL_GetWindowSurface(janela);
            if (superficieJanela == nullptr)
            {
                sucesso = false;
                printf("Falha ao pegar a superficie da tela.", SDL_GetError());
            }
            else
            {
                //Create the renderer
                renderer = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
                if (renderer == nullptr)
                {
                    sucesso = false;
                    printf("Falha ao criar render.", SDL_GetError());
                }
            }
        }
    }
    return sucesso;
}

void Display::render(Conteudo & conteudo, Jogador & jogador, std::vector<Inimigo>& inimigos, std::vector<Laser>& jogadorLasers, std::vector<Laser>& inimigoLasers)
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

    //Render player
    SDL_RenderCopy(renderer, conteudo.getJogadorTexture(), nullptr, &jogador.getPosition());

    //Render enemies
    for (auto &i : inimigos)
    {
        SDL_RenderCopy(renderer, conteudo.getInimigoTexture(), nullptr, &i.m_pos);
    }

    //Render Player Lasers
    for (auto &i : jogadorLasers)
    {
        SDL_RenderCopy(renderer, conteudo.getLaserTexture(), nullptr, &i.m_pos);
    }

    for (auto &i : inimigoLasers)
    {
        SDL_RenderCopy(renderer, conteudo.getLaserTexture(), nullptr, &i.m_pos);
    }

    SDL_RenderPresent(renderer);
}