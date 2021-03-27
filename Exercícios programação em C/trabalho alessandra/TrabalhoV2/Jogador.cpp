#include "Jogador.h"
#include "Laser.h"


Jogador::Jogador()
{
    init();
}

Jogador::~Jogador()
{
}

void Jogador::movimento(SDL_Event& e)
{
    switch (e.key.keysym.sym)
    {
        //Move right
    case SDLK_d: m_pos.x += MOVIMENTO_VELOCIDADE;
        break;
        //Move left
    case SDLK_a: m_pos.x -= MOVIMENTO_VELOCIDADE;
        break;

    }
}

void Jogador::movimentoBounds()
{
    if (m_pos.x <= xMinDistancia) {
        m_pos.x = xMinDistancia;
    }
    if (m_pos.x >= xMaxDistancia) {
        m_pos.x = xMaxDistancia;
    }
}

void Jogador::init()
{
    //Size of player
    m_pos.h = SIZE_LARGURA;
    m_pos.w = SIZE_ALTURA;
    //starting position
    m_pos.x = START_XPOS;
    m_pos.y = START_YPOS;
}

void Jogador::tiro(std::vector<Laser>& jogadorLasers)
{
    int startXPos = m_pos.x + 10;
    int startYPos = m_pos.y - 35;
    int movimentoVelocidade = 8;
    int sizeLargura = 25;
    int sizeAltura = 50;
    MoverDirecao dir = MoverDirecao::UP;

    jogadorLasers.push_back(Laser({ startXPos, startYPos, sizeLargura, sizeAltura }, moverVelocidade, dir));
}