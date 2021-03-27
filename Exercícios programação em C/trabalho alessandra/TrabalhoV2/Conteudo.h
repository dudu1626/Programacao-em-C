#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <string>


class Display;
class Conteudo
{
public:
    Conteudo();
    ~Conteudo();

    bool load(Display& display);
    SDL_Texture* getJogadorTexture() { return jogador; }
    SDL_Texture* getInimigoTexture() { return inimigo; }
    SDL_Texture* getLaserTexture() { return laser; }
protected:


private:
    SDL_Surface* loadSurface(Display& display, std::string path);
    SDL_Texture* loadTexture(Display& display, std::string path);

    SDL_Texture* laser = nullptr;
    SDL_Texture* jogador = nullptr;
    SDL_Texture* inimigo = nullptr;


};
