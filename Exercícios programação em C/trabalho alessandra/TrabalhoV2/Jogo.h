#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <vector>

struct Laser;
struct Inimigo;
class Jogador;
class Conteudo;
class Display;
class Jogo
{
public:
    Jogo();
    ~Jogo();

    void start(Display& display, Conteudo& conteudo, Jogador& jogador);

private:
    bool sair = false;
    void addInimigo(std::vector<Inimigo>& inimigos);
    void moverInimigos(std::vector<Inimigo>& inimigos);
    void moverLasers(std::vector<Laser>& jogadorLasers, std::vector<Laser>& inimigosLasers);

    void checkColisoes(Jogador& jogador, std::vector<Inimigo>& inimigos, std::vector<Laser>& jogadorLasers, std::vector<Laser>& inimigoLasers);
    bool achaJogadorLaserColisoes(Laser& laser, Inimigo& inimigo);
    bool achaInimigoLaserColisoes(Laser& laser, Jogador& jogador);
    bool checkGameOver(std::vector<Inimigo>& inimigos);
    void inimigoTiro(std::vector<Inimigo>& inimigos, std::vector<Laser>& inimigoLasers);

};
