// tutorial video you tube canal CJ

#include <SDL.h> // no linux seria #include <SDL/SDL.h>
#include "SDL_opengl.h"
#include <stdio.h> // biblioteca do c para entrada e saida de dados mais amigavel

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
	SDL_SetVideoMode(600,400,32, SDL_OPENGL); // 32 bits por pixel , "SDL_OPENGL" -> tipo de janela

	// cor inicial
	glClearColor(1,1,1,1); // sao as cores red, green, blue e alpha tudo 1 branco e 0 preto


	// area exibida
	glViewport(0,0,600,400); // coordenadas de abertura da janela 0,0 no inicio e 600,400 no final

	// sombra
	glShadeModel (GL_SMOOTH);

	// 2D
	glMatrixMode(GL_PROJECTION); //aplicar a projeção na matriz atual
	glLoadIdentity(); // trabalhar com desenho geometrico

	//3D desabilitado
	glDisable(GL_DEPTH_TEST);

	//variaveis
	bool executando = true;
	SDL_Event eventos; // para uso do mouse

	//loop do jogo
	while(executando){

        // eventos

		while(SDL_PollEvent(&eventos)){

			// fechar a janela no x
			if(eventos.type == SDL_QUIT)
				executando = false;
			// fechar com esc
			if(eventos.type == SDL_KEYUP && eventos.key.keysym.sym == SDLK_ESCAPE) //keyup soltar o botão
				executando = false;
		}

        // logica

        // RENDERIZAÇÃO
        glClear(GL_COLOR_BUFFER_BIT); // limpa o buffer

        //inicia a matriz
        glPushMatrix();

        //dimensoes da matriz
        glOrtho(0,600,400,0,-1,1); // definir o tamanho da matriz para desenhar

        // COR DESENHO
        // maneira 1 -> glColor3d(1,1,1); números 1 ou zero
        // maneira 2 -> glColor3f(1.0,1.0,1.0); números float para cor
        // maneira 3 -> glColor3ub(R,G,B); os paramentros são em bytes de 0 a 255
        // maneira 4 -> glColor4ub(R,G,B,A); os paramentros são em bytes de 0 a 255

        glColor4ub(255,0,0,255); // vermelho

        //iniciar desenho
        glBegin(GL_LINES); // GL_POINTS, GL_LINES, GL_LINES_LOOP, GL_QUADS, GL_TRIANGLES, GL_POLIGON

        glVertex2f(50,50); // coordenadas do ponto 1 em 2D
        glVertex2f(550,350); // coordenadas do ponto 2 em 2D


        //fecha o desenho
        glEnd();


        //fecha a atriz
        glPopMatrix();





        // animação
        SDL_GL_SwapBuffers();

	}


	// LOGICA







	// SDL_Delay(5000); //delay de 5000 milisegundos (5 segundos)



    glDisable(GL_BLEND); // somente no windows

    SDL_Quit();

return 0;
}
