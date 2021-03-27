#pragma once

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include "Mover.h"

struct Inimigo
{
    Inimigo(SDL_Rect pos, int movimentoVelocidade, MoverDirecao dir)
    {
        m_pos = pos;
        m_movimentoVelocidade = movimentoVelocidade;
        m_dir = dir;
    }

    SDL_Rect m_pos; //Position of enemy
    int m_movimentoVelocidade = 0; //Movement speed of enemy
    MoverDirecao m_dir; //Movement direction of enemy
    int MIN_X_POS = 0;
    int MAX_X_POS = 750;
};
