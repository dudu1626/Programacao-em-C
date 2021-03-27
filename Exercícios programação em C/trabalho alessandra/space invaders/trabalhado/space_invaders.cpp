/* 
		Para compilar:
		g++ -o main space_invaders.cpp -lSDLmain -lSDL -lGL
		Para executar:
		./main
*/


#include <stdio.h> // biblioteca do c para entrada e saida de dados mais amigavel (printf)
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#define  LIN_INVADERS     4
#define  COL_INVADERS  20

#define  VAZIO    '.'
#define  WIN       'a'

#define  VELOCIDADE_CAN    3
#define  VELOCIDADE_BALA    6
#define  VELOCIDADE_INVA    2

#define  LARGURA 800
#define  ALTURA 600
#define  BPP 16
#define  FLAGS (SDL_SWSURFACE | SDL_HWSURFACE | SDL_ANYFORMAT | SDL_SRCCOLORKEY | SDL_DOUBLEBUF)
#define  DELAY 15

SDL_Surface *screen, *nave, *INVADER, *bala, *espaco;
SDL_Rect destino, projetil;

int atirar = 0, velo_invaders = 2;
int move_hor = 2, move_ver = 0;    //move os invaders horizontal e verticalmente

char mapa_invaders[LIN_INVADERS][COL_INVADERS] = { {"a a a a a a a a a a"}, {"a a a a a a a a a a"}, {"a a a a a a a a a a"}, {"a a a a a a a a a a"} };

void Controla_FPS(int tempo)
{
  tempo = SDL_GetTicks() - tempo;
   if(tempo < DELAY)
       SDL_Delay(DELAY - tempo);
}

//converte imagens no formato do screen
SDL_Surface * FuncLoad(const char *loc_file)
{
  SDL_Surface *tmp, *surf;
  tmp   =  SDL_LoadBMP(loc_file);
  if(!tmp)
     {
       printf("ERROR: %s\n",SDL_GetError());
       return NULL;
     }
  surf  =  SDL_DisplayFormat(tmp);
  SDL_FreeSurface(tmp);

  SDL_SetColorKey(surf, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(surf->format, 0,0,0));

  return  surf;
}

void FuncUnload(void)
{
//descarrega imagens
  SDL_FreeSurface(INVADER);
  SDL_FreeSurface(nave);
  SDL_FreeSurface(bala);

//finaliza a SDL
  SDL_Quit();
}

//Função retirada da SDL_collid
int Colisao(SDL_Rect *a, SDL_Rect *b)
   {
    if(a->x > b->x + b->w) return 0;
    if(a->x + a->w < b->x) return 0;

    if(b->y > a->y + a->h) return 0;
    if(b->y + b->h < a->y) return 0;
    return 1;
   }

void BlitInvaders(SDL_Surface *img, int y, int x, int desloc_hor, int desloc_ver)
{
   SDL_Rect posi;

   posi.y = img->h*y + desloc_ver;
   posi.x = img->w*x + desloc_hor;

   SDL_BlitSurface(img, NULL, screen, &posi);
}

void MoveInvaders(void) {
  int linha, coluna;

//  muda a direção dos invaders e move eles sobre o screen
  if(move_hor < 0)
     {
       velo_invaders   =  VELOCIDADE_INVA;
       move_ver =  move_ver + INVADER->h/2;
     }
  else if(move_hor > (LARGURA - COL_INVADERS*INVADER->w))
          {
            velo_invaders   =  -VELOCIDADE_INVA;
            move_ver =  move_ver + INVADER->h/2;
          }

  move_hor = move_hor + velo_invaders;

//blit dos invaders junto com o deslocamento vertical e horizontal
  for(linha = 0; linha < LIN_INVADERS; linha++) {
        for(coluna = 0; coluna < COL_INVADERS; coluna++) {
              switch(mapa_invaders[linha][coluna]) {
                       case VAZIO:
                            break;

                       case WIN:
                            BlitInvaders(INVADER, linha, coluna, move_hor, move_ver);
                            break;
              }
         }
   }
}


//usar quando atirar for verdadeiro
void DestroiInvaders(void) {
  SDL_Rect posicao;
  int linha, coluna;

  if(projetil.y - VELOCIDADE_BALA < 0)
     atirar = 0;
     
  for(linha = 0; linha < LIN_INVADERS; linha++) {
        posicao.y = INVADER->h*linha   +  move_ver;
        for(coluna = 0; coluna < COL_INVADERS; coluna++) {
              posicao.x = INVADER->w*coluna  +  move_hor;
              switch(mapa_invaders[linha][coluna]) {
                       case VAZIO:
                            break;

                       case WIN:
                            posicao.w = INVADER->w - 4;
                            posicao.h = INVADER->h - 2;
                            if(Colisao(&projetil, &posicao))
                               {
                                 mapa_invaders[linha][coluna] = VAZIO;
                                 atirar = 0;
                               }
                            break;
               }
         }
   }
}

int ControlaCanha(int *x) {
  Uint8 *keyboard;
  SDL_PumpEvents();
  keyboard = SDL_GetKeyState(0);

/* Se user apertar seta Direita a velocidade do canhao eh positiva. */
  if(keyboard[SDLK_RIGHT]) {
       *x  =   VELOCIDADE_CAN;
     }

/* Se user apertar seta Esquerda a velocidade do canhao eh negativa */
  if(keyboard[SDLK_LEFT]) {
       *x  =  -VELOCIDADE_CAN;
     }

/* Se user apertar Barra de ESPAÇO e atirar for falso(nulo)... */
  if((keyboard[SDLK_SPACE]) && (!atirar)) {
/* ...Então faça, posicione a bala de acordo com a posição da nave e faça atirar verdadeiro(isso evita que ela
      desapareça do nada quando apertar mais de uma vez a Barra de espaço)
 */
       projetil.y = destino.y + bala->h/2;
       projetil.x = destino.x + bala->w/2;

       atirar = 1;
     }

  return  keyboard[SDLK_ESCAPE];
}

//Função de scrolling, falta ajustar
void FuncScroll(int x, int y)
{
  SDL_Rect fonte;

  fonte.x = x;
  fonte.y = y;

  SDL_BlitSurface(espaco, NULL, screen, &fonte);
}


void MainLoop(void)
{
  int fim = 0;
  int velocidade; //controle de velocidade da nave
  int scroll_x = 0, scroll_y = 0;

  int tempo_agora;
  SDL_WM_SetCaption("Space_Invaders", NULL);

  SDL_Event evento;
  while(!fim)
     {
      tempo_agora = SDL_GetTicks();
    //para poder usar o botão fechar da janela, sem isso não funcionaria
      while(SDL_PollEvent(&evento))
          if(evento.type == SDL_QUIT)
              fim = 1;
	  //se user não estiver apertando esquerda ou direita, a velocidade será sempre 0
     //ou seja a canhão estará parado
       velocidade = 0;

    //ControleNave() retorna 0 se tecla ESC não for precionada, caso contrario retorna não nulo
       fim = ControlaCanha(&velocidade);

      //move nave
       destino.x = destino.x + velocidade;

     //pinta o screen de preto, é meio inútil mas é necessário
       SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,0,0,0));
     
	//põe o fundo na tela e move ele
       scroll_y = scroll_y + 2;
       if(scroll_y >= espaco->h)
          {
            scroll_y = 0;
          }
       FuncScroll(scroll_x, scroll_y - espaco->h);
       FuncScroll(scroll_x, scroll_y);

     //move as imagens dos invaders
       MoveInvaders();

       if(atirar)
          {
            projetil.y = projetil.y - VELOCIDADE_BALA;
            SDL_BlitSurface(bala, NULL, screen, &projetil);
            DestroiInvaders();  //verifica se a bala acertou em algum dos invaders
          }

       SDL_BlitSurface(nave, NULL, screen, &destino);

       SDL_Flip(screen);
       Controla_FPS( tempo_agora );
     }
}


int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);

//configura o video
  screen    =  SDL_SetVideoMode(LARGURA, ALTURA, BPP, FLAGS);
  if(!screen)
     {
       printf("\nERROR: %s\n",SDL_GetError());
       SDL_Quit();
       return 1;
     }

//carrega as imagens
  nave        =  FuncLoad("nave.bmp");
  INVADER     =  FuncLoad("invader.bmp");
  espaco      =  FuncLoad("espaco.bmp");
  bala        =  FuncLoad("bala.bmp");

//posicionando a nave na tela, posição inicial
  destino.x = (screen->w - nave->w/2)/2;
  destino.y = (screen->h - nave->h*2);

//Loop principal
  MainLoop();

//Descarregar as imagens e finalizar a SDL
  FuncUnload();

  return 0;
}

