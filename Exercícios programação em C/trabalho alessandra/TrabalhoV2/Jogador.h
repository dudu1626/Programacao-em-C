#pragma once

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <vector>

struct Inimigo;
struct Laser;
class Jogador
{
public:
    Jogador();
    ~Jogador();
    void movimento(SDL_Event& e);
    void movimentoBounds();
    void init(); //Initialize

    SDL_Rect getPosition() { return m_pos; }
    int getPositionY() { return m_pos.y; }
    int getPositionX() { return m_pos.x; }
    int getWidth() { return SIZE_LARGURA; }
    int getHeight() { return SIZE_ALTURA; }

    void shoot(std::vector<Laser>& jogadorLasers);

private:
    //position of player
    SDL_Rect m_pos;
    //Size of player
    const int SIZE_LARGURA = 50;
    const int SIZE_ALTURA = 50;
    //Starting position of player
    const int START_XPOS = 350;
    const int START_YPOS = 700;
    //Movement speed of player
    const int MOVIMENTO_VELOCIDADE = 10;
    //MovementBoundaries
    const int xMinDistancia = 0;
    const int xMaxDistancia = 775;

};
