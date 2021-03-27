// tem link especial para a imagem nas propriedades do projeto
// tutorial video you tube canal CJ

#include <SDL.h> // no linux seria #include <SDL/SDL.h>
#include "SDL_opengl.h"
#include <stdio.h> // biblioteca do c para entrada e saida de dados mais amigavel
#include "SDL_image.h"
#include "string"

#define BLOCOS 26 //quantidade de blocos

// para abrir a pasta e ler a imagem e textura
GLuint loadTexture(const std::string&fileName){
    SDL_Surface *imagem = IMG_Load(fileName.c_str()); // carrega imagem
    SDL_DisplayFormatAlpha(imagem); //formato alpha
    unsigned objetct(0); // cria a textura
    glGenTextures(1,&object); // regra de textura
    glBindTexture(GL_TEXTURE_2D, object); // tipo de textura 2D
    SDL_FreeSurface(imagem);
    return object;
}

// funcoes -> logica no final
bool colisao(float Ax, float Ay,float Acomp, float Aalt,float Bx, float By,float Bcomp, float Balt);

struct Bloco{
    float x;
    float y;
    float comp;
    float alt;
    bool vida; // para poder sumir
};

int main (int argc, char* args[]){

   SDL_Init(SDL_INIT_EVERYTHING); //iniciar o sdl

	// memoria
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); // TRANSPARENCIA
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16); //PARA 3D
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// NOME NA JANELA
	SDL_WM_SetCaption(" Meu primeiro jogo com SDL", NULL); // onde tem null seria o icone

	//tamanho da janela
	SDL_SetVideoMode(800,600,32, SDL_OPENGL); // 32 bits por pixel , "SDL_OPENGL" -> tipo de janela

	// cor inicial
	glClearColor(1,1,1,1); // sao as cores red, green, blue e alpha tudo 1 branco e 0 preto

	// area exibida
	glViewport(0,0,800,600); // coordenadas de abertura da janela 0,0 no inicio e 600,400 no final

	// sombra
	glShadeModel (GL_SMOOTH);

	// 2D
	glMatrixMode(GL_PROJECTION); //aplicar a proje��o na matriz atual
	glLoadIdentity(); // trabalhar com desenho geometrico

	//3D desabilitado
	glDisable(GL_DEPTH_TEST);

	// uso da imagem
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//VARIAVEIS
	bool executando = true;
	SDL_Event eventos; // para uso do mouse

    //para o tamanho do personagem
	float personX = 325;
	float personY = 550;
	float personComp = 75;
	float personAlt = 50;

    //para o tamanho do inimigo e posi��o inicial
	float inimigoX = 50;
	float inimigoY = 60;
	float inimigoCA = 30;

	//velocidade do inimigo
	float velX = 0.07;
	float velY = 0.07;

	//para o movimento
    bool esq=false, dir=false;

    unsigned int person_textura = 0; // para a figura
    person_textura = loadTexture("Pinguim.png"); //carrega a figura

    Bloco bloco[BLOCOS]; // criar um vetor de blocos
    //cria��o dos blocos
    for(int i=0, x=4,y=10; i<BLOCOS; i++, x+=61) {// para criar o vetor
        if(x>760){
            x=4;
            y+=21; // por conta da altura 20 + 3
        }
        bloco[i].x = x;
        bloco[i].y = y;
        bloco[i].comp = 60;
        bloco[i].alt = 20;
        bloco[i].vida = true;
    }
	//loop do jogo
	while(executando){

        // eventos

		while(SDL_PollEvent(&eventos)){

			// fechar a janela no x
			if(eventos.type == SDL_QUIT)
				executando = false;
			// fechar com esc
			if(eventos.type == SDL_KEYUP && eventos.key.keysym.sym == SDLK_ESCAPE) //keyup soltar o bot�o
				executando = false;

            // andar ou n�o
            if(eventos.type == SDL_KEYDOWN) {// tecla pressionada para andar
                if(eventos.key.keysym.sym == SDLK_LEFT){
                    esq = true;
                }else if(eventos.key.keysym.sym == SDLK_RIGHT){
                    dir = true;
                }
            }
            if(eventos.type == SDL_KEYUP) { // tecla solta para parar de andar
                if(eventos.key.keysym.sym == SDLK_LEFT){
                    esq = false;
                }else if(eventos.key.keysym.sym == SDLK_RIGHT){
                    dir = false;
                }
            }

		} // fim while eventos

        // LOGICA

        // movimentos do personagem
        if (esq==true)
            personX -= 0.5; // no tutorial o cara usa 8, mas no meu 1 � muito
        if (dir==true)
            personX += 0.5;
        //barreira
        if(personX<0)
            personX = 0;
        if(personX+personComp>800)
            personX = 800 - personComp;

        // movimento do inimigo
        // movimento em diagonal
        inimigoX += velX;

        //colisao nos blocos em x
        for(int i=0;i<BLOCOS;i++){ // para os blocos
            if(bloco[i].vida == true){
                if(colisao(inimigoX,inimigoY,inimigoCA,inimigoCA,bloco[i].x,bloco[i].y,bloco[i].comp,bloco[i].alt) == true){
                    velX = -velX;
                    bloco[i].vida=false;
                }
            }
        }

        inimigoY += velY;

        // colis�o dos blocos em y
        for(int i=0;i<BLOCOS;i++){ // para os blocos
            if(bloco[i].vida == true){
                if(colisao(inimigoX,inimigoY,inimigoCA,inimigoCA,bloco[i].x,bloco[i].y,bloco[i].comp,bloco[i].alt) == true){
                    velY = -velY;
                    bloco[i].vida=false;
                }
            }
        }


        //logica inimigo para n�o bater na tela
        if(inimigoX<0)
            velX = -velX;
        if(inimigoX+inimigoCA>800)
            velX = -velX;
        if(inimigoY<0)
            velY = -velY;
        if(inimigoY+inimigoCA>600)
            velY = -velY;
            // se quiser para quando bater no chao perder, p�r
            // executando = false;

        if(colisao(inimigoX,inimigoY,inimigoCA,inimigoCA,personX,personY,personComp,personAlt) == true)
        {
            velY = -velY;
            velX = -velX;
        }
        // RENDERIZA��O
        glClear(GL_COLOR_BUFFER_BIT); // limpa o buffer

        //inicia a matriz
        glPushMatrix();

        //dimensoes da matriz
        glOrtho(0,800,600,0,-1,1); // definir o tamanho da matriz para desenhar

        // COR DESENHO
        // maneira 1 -> glColor3d(1,1,1); n�meros 1 ou zero
        // maneira 2 -> glColor3f(1.0,1.0,1.0); n�meros float para cor
        // maneira 3 -> glColor3ub(R,G,B); os paramentros s�o em bytes de 0 a 255
        // maneira 4 -> glColor4ub(R,G,B,A); os paramentros s�o em bytes de 0 a 255

        glColor4ub(255,255,255,255); // branco para n�o alterar a cor

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, person_textura);

        //iniciar desenho personagem
        glBegin(GL_QUADS); // GL_POINTS, GL_LINES, GL_LINES_LOOP, GL_QUADS, GL_TRIANGLES, GL_POLIGON

        glTexCoord2d(0,0); // faz com que a imagem caiba dentro dos parametros do quadrado
        glVertex2f(personX,personY); // coordenadas do ponto 1 em 2D
        glTexCoord2d(1,0);// faz com que a imagem caiba dentro dos parametros do quadrado
        glVertex2f(personX+personComp,personY); // coordenadas do ponto 2 em 2D
        glTexCoord2d(1,1);// faz com que a imagem caiba dentro dos parametros do quadrado
        glVertex2f(personX+personComp,personY+personAlt); // coordenadas do ponto 3 em 2D
        glTexCoord2d(0,1);// faz com que a imagem caiba dentro dos parametros do quadrado
        glVertex2f(personX,personY+personAlt); // coordenadas do ponto 4 em 2D

        //fecha o desenho
        glEnd();

        glDisable(GL_TEXTURE_2D);

        glColor4ub(0,0,255,255); // cor inimigo
        // desenho do inimigo
        glBegin(GL_QUADS); // GL_POINTS, GL_LINES, GL_LINES_LOOP, GL_QUADS, GL_TRIANGLES, GL_POLIGON

        glVertex2f(inimigoX,inimigoY); // coordenadas do ponto 1 em 2D
        glVertex2f(inimigoX+inimigoCA,inimigoY); // coordenadas do ponto 2 em 2D
        glVertex2f(inimigoX+inimigoCA,inimigoY+inimigoCA); // coordenadas do ponto 3 em 2D
        glVertex2f(inimigoX,inimigoY+inimigoCA); // coordenadas do ponto 4 em 2D

        //fecha o desenho
        glEnd();

         glColor4ub(0,255,0,255); // cor bloco
        // desenho dos blocos
        glBegin(GL_QUADS); // GL_POINTS, GL_LINES, GL_LINES_LOOP, GL_QUADS, GL_TRIANGLES, GL_POLIGON

        for(int i=0; i<BLOCOS;i++){
            if(bloco[i].vida==true){ // condi��o para desenhar o bloco
                glVertex2f(bloco[i].x,bloco[i].y); // coordenadas do ponto 1 em 2D
                glVertex2f(bloco[i].x+bloco[i].comp,bloco[i].y); // coordenadas do ponto 2 em 2D
                glVertex2f(bloco[i].x+bloco[i].comp,bloco[i].y+bloco[i].alt); // coordenadas do ponto 3 em 2D
                glVertex2f(bloco[i].x,bloco[i].y+bloco[i].alt); // coordenadas do ponto 4 em 2D
            }
        }
        //fecha o desenho
        glEnd();


        //fecha a atriz
        glPopMatrix();

        // anima��o
        SDL_GL_SwapBuffers();

	}


	// LOGICA


	// SDL_Delay(5000); //delay de 5000 milisegundos (5 segundos)

    glDisable(GL_BLEND); // somente no windows

    SDL_Quit();

return 0;
}

bool colisao(float Ax, float Ay,float Acomp, float Aalt,float Bx, float By,float Bcomp, float Balt){
    // A -> inimigo -- B-> personagem
    if(Ay+Aalt<By) return false;
    if(Ay>By+Balt) return false;
    if(Ax+Acomp<Bx) return false;
    if(Ax>Bx+Bcomp) return false;

    return true; // quando � igual tem a colis�o
}

