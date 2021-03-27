#include "Display.h"
#include "Jogo.h"
#include "Conteudo.h"
#include "Jogador.h"

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <iostream>

int main(int argc, char* args[])
{
    Display display;
    Jogo jogo;
    Conteudo conteudo;
    Jogador jogador;


    jogo.start(display, conteudo, jogador);

    printf("\n\n\nVoce venceu!");
    SDL_Delay(3000);

    return 0;
}
