#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <vector>

struct Laser;
struct Inimigo;
class Jogador;
class Conteudo;

class Display
{
public:
    Display();
    ~Display();

    bool init();
    void render(Conteudo& conteudo, Jogador& jogador, std::vector<Inimigo>& inimigos, std::vector<Laser>& jogadorLasers, std::vector<Laser>& inimigoLasers);

    SDL_Surface* getWindowSurface() { return superficieJanela; }
    SDL_Renderer* getRenderer() { return renderer; }
protected:


private:
    
	SDL_Window* janela = nullptr;
    SDL_Surface* superficieJanela = nullptr;
    SDL_Renderer* renderer = nullptr;

    //Screen resolution
    const int TELA_LARGURA = 800;
    const int TELA_ALTURA = 800;


};
