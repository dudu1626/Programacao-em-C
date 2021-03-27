#include "Conteudo.h"
#include "Display.h"


Conteudo::Conteudo()
{
}


Conteudo::~Conteudo()
{
}

bool Conteudo::load(Display & display)
{
    bool sucesso = true;

    laser = loadTexture(display, "imagens/tiro.bmp");
    if (laser == nullptr)
    {
        printf("Falha ao carregar o laser !.", SDL_GetError());
        sucesso = false;
    }

    jogador = loadTexture(display, "imagens/jogador.bmp");
    if (jogador == nullptr)
    {
        printf("Falha ao carregar jogador", SDL_GetError());
        sucesso = false;
    }

    inimigo = loadTexture(display, "imagens/inimigo.bmp");
    if (inimigo == nullptr)
    {
        printf("Falha ao carregar o inimigo", SDL_GetError());
        sucesso = false;
    }
    return sucesso;
}

SDL_Surface * Conteudo::loadSurface(Display& display, std::string path)
{
        SDL_Surface* superficieOtimizada = nullptr;
        SDL_Surface* superficie = SDL_LoadBMP(path.c_str());
        if(superficie == nullptr)
        {
            printf("Impossivel carregar !", path.c_str(), SDL_GetError());
        }
        else
        {
            superficieOtimizada = SDL_ConvertSurface(superficie, display.getWindowSurface()->format, 0);
        }
        SDL_FreeSurface(superficie);
        return superficieOtimizada;
}

SDL_Texture * Conteudo::loadTexture(Display& display, std::string path)
{
    SDL_Texture* textura = SDL_CreateTextureFromSurface(display.getRenderer(), loadSurface(display, path.c_str()));
    if (textura == nullptr)
    {
        printf("Falha ao carregar textura.", SDL_GetError());
    }
    return textura;
}