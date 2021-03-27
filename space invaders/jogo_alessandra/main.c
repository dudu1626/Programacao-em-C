//bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>

//dimensoes da tela
#define TELA_LARGURA 800
#define TELA_ALTURA 600

//definições padroes de objetos
#define E_LARGURA 30
#define LARGURA 600
#define ALTURA 600
#define E_LARGURA 30
#define E_ALTURA 29
#define P_LARGURA 30
#define P_ALTURA 30
#define B_LARGURA 5
#define B_ALTURA 15
#define P_MUNICAO 1
#define E_MUNICAO 3
#define BASE 4
#define BASE_LARGURA 60
#define BASE_ALTURA 40


//estruturas
enum cor {cinza};
enum direcao {esquerda, direita, stationary};
enum estado {menu, options, game, game_over, pause};
enum ck {magenta, lime};

struct ponto { // pontuacao ainda nao tem na tela

	unsigned int tiros;
	unsigned int pontos;
	unsigned int nivel;
};

struct inimigo { // estrutura dos inimigos para usar no tanques

	SDL_Rect danoBox;
	enum cor cor;
	unsigned int vivo;
	unsigned int pontos;
};

struct tanques { // inimigos

	struct inimigo inimigo[5][10];
	enum direcao direcao;
	unsigned int morto;
	int velocidade;
	int estado;
	int estado_velocidade;
	Uint32 estado_tempo;
};

struct base { // bases de defesa

	SDL_Rect danoBox;
};

struct jogador{ // jogador

	SDL_Rect danoBox;
	int vidas;
};

struct municao { // tiro

	SDL_Rect danoBox;
	unsigned int vivo;
};

//Variaveis globais.
static SDL_Surface *tela;
static SDL_Surface *titulo_tela;
static SDL_Surface *cmap;
static SDL_Surface *tanquesmap;
static SDL_Surface *jogador_img;
static SDL_Surface *base_img[4];
static SDL_Surface *dano_img;
static SDL_Surface *dano_top_img;
static SDL_Surface *game_over_img;
struct ponto ponto;
struct tanques tanques;
struct base base[BASE];
struct jogador jogador;
struct municao municao[P_MUNICAO];
struct municao e_municao[E_MUNICAO];
unsigned int pause_len;
Uint32 pause_tempo;
enum estado estado;
Uint32 titulo_tempo;

//desenho de polinomios com o OPENGL
void desenha_frase(char s[], int x, int y);
void pause_for(unsigned int len);

//carregador de imagem
int load_image(char filename[], SDL_Surface **superficie, enum ck colour_key);

// funcao para inicializar a estrutura de pontuacao
void init_ponto() {

	ponto.tiros = 0;
	ponto.pontos = 0;
	ponto.nivel = 1;
}

// funcao para inicializar os inimigos (posicao, direcao, velocidade)
void init_tanques() {
//ações dos tanques
	tanques.direcao = direita;
	tanques.velocidade = 1;
	tanques.estado = 0;
	tanques.morto = 0;
	tanques.estado_velocidade = 1000;
	tanques.estado_tempo = SDL_GetTicks();

	int i,j;
	int x = 0;
	int y = 30;

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 10; j++) {

			tanques.inimigo[i][j].vivo = 1;
			tanques.inimigo[i][j].danoBox.x = x;
			tanques.inimigo[i][j].danoBox.y = y;
			tanques.inimigo[i][j].danoBox.w = E_LARGURA;
			tanques.inimigo[i][j].danoBox.h = E_ALTURA;

			x += E_LARGURA + 15; // tamanho da lacuna entre os invaders

			if (i == 0) {

				tanques.inimigo[i][j].cor = cinza;
				tanques.inimigo[i][j].pontos = 30;

			} else if (i >= 1 && i < 3) {

				tanques.inimigo[i][j].cor = cinza;
				tanques.inimigo[i][j].pontos = 20;

			} else {

				tanques.inimigo[i][j].cor = cinza;
				tanques.inimigo[i][j].pontos = 10;
			}
		}

		x = 0; //reseta a linha
		y += E_LARGURA + 15;
	}
}

//funcao para inicializar o jogador (posicao e dimensao)
void init_jogador() {

	jogador.danoBox.x = (LARGURA / 2) - (P_LARGURA / 2);
	jogador.danoBox.y = ALTURA - (P_ALTURA + 10);
	jogador.danoBox.w = P_LARGURA;
	jogador.danoBox.h = P_ALTURA;
	jogador.vidas = 3;
}

//funcao para inicializar as bases (posicao e dimensao)
void init_bases() {

	int i;
	int base_total = BASE_LARGURA * 4;
	int espaco_esquerda = LARGURA - base_total;
	int even_espaco = espaco_esquerda / 5; // 5 espacos
	int x = even_espaco;
	int y = 500;

	for (i = 0; i < BASE; i++) {

		base[i].danoBox.x = x;
		base[i].danoBox.y = y;
		base[i].danoBox.w = BASE_LARGURA;
		base[i].danoBox.h = BASE_ALTURA;

		x += BASE_LARGURA + even_espaco; //distanciamento
	}

	load_image("base.bmp", &base_img[0], magenta);
	load_image("base.bmp", &base_img[1], magenta);
	load_image("base.bmp", &base_img[2], magenta);
	load_image("base.bmp", &base_img[3], magenta);
}

//funcao para inicializar os tiros do jogador
void init_municao(struct municao b[], int max) {

	int i;

	for (i = 0; i < max; i++) {

		b[i].vivo = 0;
		b[i].danoBox.x = 0;
		b[i].danoBox.y = 0;
		b[i].danoBox.w = B_LARGURA;
		b[i].danoBox.h = B_ALTURA;
	}
}

//funcao para desenhar o background
void desenha_fundo () {

	SDL_Rect src;

	src.x = 0;
	src.y = 0;
	src.w = tela->w;
	src.h = tela->h;

	SDL_FillRect(tela,&src,0);
}

//funcao para desenhar o HUD ----não sei direito o que e isso mas não está funcionando
void desenha_hud() {

	SDL_Rect r;

	r.x = LARGURA;
	r.y = 0;
	r.w = TELA_LARGURA - LARGURA;
	r.h = TELA_LARGURA;

	SDL_FillRect(tela, &r, 41);

	char ponto_tela[] = "Pontos";
	desenha_frase(ponto_tela, LARGURA, 0);

	char ponto_num[10];
	snprintf(ponto_num, 10, "%d", ponto.pontos);
	desenha_frase(ponto_num, LARGURA, 20);

	char nivel[] = "Nivel";
	desenha_frase(nivel, LARGURA, 60);

	char nivel_num[2];
	snprintf(nivel_num, 2, "%d", ponto.nivel);
	desenha_frase(nivel_num, LARGURA, 80);

	char vidas[] = "Vidas";
	desenha_frase(vidas, LARGURA, 120);

	char vidas_num[2];
	snprintf(vidas_num, 2, "%d", jogador.vidas);
	desenha_frase(vidas_num, LARGURA, 140);

	char autor[] = "Feito por";
	desenha_frase(autor, LARGURA, 540);

	char nome[] = "\nGrupo do Jogo - \nBruno, Eduardo e Octavio";
	desenha_frase(nome, LARGURA, 560);
}

//funcao para desenhar a tela de titulo
void desenha_titulo_tela() {

	SDL_Rect src;
	SDL_Rect dest;

	src.x = 0;
	src.y = 0;
	src.w = titulo_tela->w;
	src.h = titulo_tela->h;

	dest.x = (TELA_LARGURA / 2) - (titulo_tela->w / 2);
	dest.y = 0;
	dest.w = titulo_tela->w;
	dest.h = titulo_tela->h;

	SDL_BlitSurface(titulo_tela, &src, tela, &dest);
}

//funcao para desenhar os tanques se estiverem vivos
void desenha_tanques() {

	SDL_Rect src, dest;
	int i,j;

	src.w = E_LARGURA;
	src.h = E_ALTURA;

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 10; j++) {

			if (tanques.inimigo[i][j].vivo == 1) {


				if(i == 0) {

					if (tanques.estado == 0) {

						src.x = 0;
						src.y = 0;

					} else {

						src.x = 30;
						src.y = 0;
					}


				} else if (i > 0 && i < 3) {

					if (tanques.estado == 0) {

						src.x = 0;
						src.y = E_LARGURA;

					} else {

						src.x = 30;
						src.y = E_ALTURA;
					}


				} else {

					if (tanques.estado == 0) {

						src.x = 0;
						src.y = E_ALTURA * 2;

					} else {

						src.x = 30;
						src.y = E_ALTURA * 2;
					}
				}

				dest.x = tanques.inimigo[i][j].danoBox.x;
				dest.y = tanques.inimigo[i][j].danoBox.y;
				dest.w = tanques.inimigo[i][j].danoBox.w;
				dest.h = tanques.inimigo[i][j].danoBox.h;

				SDL_BlitSurface(tanquesmap, &src, tela, &dest);
			}
		}
	}
}

void desenha_bases() {

	SDL_Rect src;

	src.x = 0;
	src.y = 0;
	src.w = BASE_LARGURA;
	src.h = BASE_ALTURA;

	int i;

	for(i = 0; i < BASE; i++) {

		SDL_BlitSurface(base_img[i], &src, tela, &base[i].danoBox);
	}
}

//desenha jogador
void desenha_jogador() {

	SDL_Rect src;

	src.x = 0;
	src.y = 0;
	src.w = P_LARGURA;
	src.h = P_ALTURA;

	SDL_BlitSurface(jogador_img, &src, tela, &jogador.danoBox);
}

//desenha os tiros tanto dos inimigos quanto do jogador
void desenha_tiros(struct municao b[], int max) {

	//Uint8 c = SDL_MapRGB(screen->format, 255, 255, 255);
	int i;


	for (i = 0; i < max; i++) {

		if (b[i].vivo == 1) {

			SDL_FillRect(tela, &b[i].danoBox, 255);
		}
	}
}

//desenha personagem
int desenha_Char(char c, int x, int y) {

	SDL_Rect src;
	SDL_Rect dest;
	int i,j;
	char *map[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
			"abcdefghijklmnopqrstuvwxyz",
			"!@#$%^&*()_+{}|:\"<>?,.;'-=",
			"0123456789"};
//localização e destino
	src.x = 0;
	src.y = 0;
	src.w = 20;
	src.h = 20;

	dest.x = x;
	dest.y = y;
	dest.w = 20;
	dest.h = 20;

	for (i = 0; i < 4; i++) {

		for(j = 0; j < strlen(map[i]); j++) {

			if (c == map[i][j]) {

				SDL_BlitSurface(cmap, &src, tela, &dest);
				return 0;
			}

			src.x += 20;
		}

		src.y += 20;//move para baixo na proxima linha
		src.x = 0; //reseta e inicia a linha
	}

	return 0;
}

//desenha uma string de personagens
void desenha_frase(char s[], int x, int y) {

	int i;

	for (i = 0; i < strlen(s); i++) {

		desenha_Char(s[i],x,y);
		x += 20;
	}
}

//Desenha a tela de game over
void desenha_game_over() {

	SDL_Rect src;
	SDL_Rect dest;

	src.x = 0;
	src.y = 0;
	src.w = game_over_img->w;
	src.h = game_over_img->h;

	dest.x = (LARGURA / 2) - (game_over_img->w / 2);
	dest.y = (ALTURA / 2) - (game_over_img->h / 2);
	dest.w = game_over_img->w;
	dest.h = game_over_img->h;

	SDL_BlitSurface(game_over_img, &src, tela, &dest);
}

//Velocidade dos tanques
void set_tanques_velocidade() {

	switch (tanques.morto) {

		case 10:

			tanques.velocidade = 2;
			tanques.estado_velocidade = 800;
			break;

		case 20:

			tanques.velocidade = 4;
			tanques.estado_velocidade = 600;
			break;

		case 30:

			tanques.velocidade = 8;
			tanques.estado_velocidade = 200;
			break;

		case 40:

			tanques.velocidade = 16;
			tanques.estado_velocidade = 0;
			break;
	}
}

//Move os tiros de ambos os lados pela tela
int move_municao(struct municao b[], int max, int velocidade) {

	int i;

	for(i = 0; i < max; i++) {

		if (b[i].vivo == 1) {

			b[i].danoBox.y += velocidade;

			if (b[i].danoBox.y <= 0) {

				b[i].vivo = 0;
			}

			if (b[i].danoBox.y + b[i].danoBox.h >= ALTURA) {

				b[i].vivo = 0;
			}
		}
	}

	return 0;
}

//Move os tanques em direcao ao jogador
void move_tanques_baixo() {

	int i,j;

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 10; j++) {

			tanques.inimigo[i][j].danoBox.y += 15;
		}
	}
}

//Move os tanques de acordo com sua posição atual
int move_tanques(int velocidade) {

	set_tanques_velocidade();

	int i,j;

	switch (tanques.direcao) {

		case esquerda:

			for (i = 0; i < 10; i++) {

				for (j = 0; j < 5; j++) {

					if (tanques.inimigo[j][i].vivo == 1) {

						if (tanques.inimigo[j][i].danoBox.x <= 0) {

							tanques.direcao = direita;
							move_tanques_baixo();
							return 0;
						}

						if (tanques.estado_tempo + tanques.estado_velocidade < SDL_GetTicks()) {

							tanques.estado_tempo = SDL_GetTicks();

							if (tanques.estado == 1) {

								tanques.estado = 0;

							} else {

								tanques.estado = 1;
							}
						}

						//Velocidade de movimento
						tanques.inimigo[j][i].danoBox.x -= tanques.velocidade;
					}
				}
			}

			break;

		case direita:

			for (i = 9; i >= 0; i--) {

				for (j = 0; j < 5; j++) {

					if (tanques.inimigo[j][i].vivo == 1) {

						if (tanques.inimigo[j][i].danoBox.x + E_LARGURA >= LARGURA) {

							tanques.direcao = esquerda;
							move_tanques_baixo();
							return 0;
						}

						if (tanques.estado_tempo + tanques.estado_velocidade < SDL_GetTicks()) {

							tanques.estado_tempo = SDL_GetTicks();

							if (tanques.estado == 1) {

								tanques.estado = 0;

							} else {

								tanques.estado = 1;
							}
						}

						tanques.inimigo[j][i].danoBox.x += tanques.velocidade;
					}
				}
			}

			break;

		default:
			break;

	}

	return 0;
}

//Move o jogador esquerda / direita
void move_jogador(enum direcao direcao) {

	if (direcao == esquerda) {

		if (jogador.danoBox.x > 0) {

			jogador.danoBox.x -= 10;
		}

	} else if (direcao == direita) {

		if (jogador.danoBox.x + jogador.danoBox.w < LARGURA){

			jogador.danoBox.x += 10;
		}
	}
}

//Detecta as colisoes
int colisao(SDL_Rect a, SDL_Rect b) {

	if (a.y + a.h < b.y) {

		return 0;
	}

	if (a.y > b.y + b.h) {

		return 0;
	}

	if (a.x > b.x + b.w) {

		return 0;
	}

	if (a.x + a.w < b.x) {

		return 0;
	}

	return 1;
}

//Destruidor de base
void municao_base_dano(struct base *base, int b_num, struct municao *municao, int l) {

	int i;
	int x,y;
	SDL_Rect src;
	SDL_Rect dest;

	SDL_LockSurface(base_img[b_num]);
	Uint8 *raw_pixels;

	raw_pixels = (Uint8 *) base_img[b_num]->pixels;

	int pix_offset;


	if (l == 0) {

		//Destroi esquerda
		x = (municao->danoBox.x + 3) - base->danoBox.x;

		//Destruição por baixo
		y = base->danoBox.h - 1;

		for(i = 0; i < base->danoBox.h; i++) {

			//Define limite de pixels
			if (x >= BASE_LARGURA) {
				x = BASE_LARGURA - 1;
			}

			pix_offset = y * base_img[b_num]->pitch  + x;


			if (raw_pixels[pix_offset] != 227) {

				municao->vivo = 0;

				src.x = 0;
				src.y = 0;
				src.w = 11;
				src.h = 15;

				dest.x = x - 3;
				dest.y = y - 14;
				dest.w = 11;
				dest.h = 15;

				SDL_UnlockSurface(base_img[b_num]);
				SDL_BlitSurface(dano_img, &src, base_img[b_num], &dest);

				break;
			}

			y--;
		}
	}


	if (l == 1) {


		x = (municao->danoBox.x + 3) - base->danoBox.x;


		y = 0;

		for(i = 0; i < base->danoBox.h; i++) {

			//limitador de pixels
			if (x >= BASE_LARGURA) {
				x = BASE_LARGURA - 1;
			}

			pix_offset = y * base_img[b_num]->pitch  + x;


			if (raw_pixels[pix_offset] != 227) {

				municao->vivo = 0;

				src.x = 0;
				src.y = 0;
				src.w = 11;
				src.h = 15;

				dest.x = x - 3;
				dest.y = y;
				dest.w = 11;
				dest.h = 15;

				SDL_UnlockSurface(base_img[b_num]);
				SDL_BlitSurface(dano_top_img, &src, base_img[b_num], &dest);

				break;
			}

			y++;
		}
	}

	SDL_UnlockSurface(base_img[b_num]);
}

//funcao para criar dano nas bases coma colisao com os inimigos
void inimigo_base_dano(struct inimigo *inimigo, struct base *base, int index) {

	int x,y;
	SDL_Rect dest;

	/*O x é o ponto tirado da parte superior esquerda do sprite com a velocidade em pixels
	adicionado adiante no caso de o inimigo escapar dos últimos pixels do sprite e
	a colisão não é mais detectada. Velocidade em pixels é subtraída se viajar para a esquerda*/

	if (tanques.direcao == direita) {

		x = (inimigo->danoBox.x + tanques.velocidade) - base->danoBox.x;
		y = inimigo->danoBox.y - base->danoBox.y;

		if (x > 0) {

			dest.x = 0;
			dest.y = y;
			dest.w = x;
			dest.h = inimigo->danoBox.h;

			SDL_FillRect(base_img[index], &dest, 227);
		}

	} else if (tanques.direcao == esquerda){

		x = (inimigo->danoBox.x + (inimigo->danoBox.w - 1)) - tanques.velocidade;
		x = x - base->danoBox.x;
		y = inimigo->danoBox.y - base->danoBox.y;

		if (x < base->danoBox.w) {

			dest.x = x;
			dest.y = y;
			dest.w = base->danoBox.w - 1;
			dest.h = inimigo->danoBox.h;

			SDL_FillRect(base_img[index], &dest, 227);
		}
	}
}

//funcao para colisao entre o inimigo e base rectangles
void inimigo_base_colisao() {

	int i,j,k,c;

	for (i = 0; i < 5; i++) {

		for (j = 0;  j < 10; j++) {

			for (k = 0;  k < BASE; k++) {

				if (tanques.inimigo[i][j].vivo == 1) {

					c = colisao(tanques.inimigo[i][j].danoBox,base[k].danoBox);

					if (c == 1) {

						inimigo_base_dano(&tanques.inimigo[i][j], &base[k], k);
					}
				}
			}
		}
	}
}

//funcao para a colisao entre o tiro do jogador e os tanques
void inimigo_hit_colisao() {

	int i,j,k,c;

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 10; j++) {

			if (tanques.inimigo[i][j].vivo == 1) {

				for (k = 0; k < P_MUNICAO; k++) {

					if (municao[k].vivo == 1) {

						c = colisao(municao[k].danoBox, tanques.inimigo[i][j].danoBox);

						if (c == 1) {

							tanques.inimigo[i][j].vivo = 0;
							municao[k].vivo = 0;
							municao[k].danoBox.x = 0;
							municao[k].danoBox.y = 0;
							tanques.morto++;
							ponto.pontos += tanques.inimigo[i][j].pontos;
						}
					}
				}
			}
		}
	}
}

//funcao para colisao entre o tiro inimigo e o jogador
void jogador_hit_colisao() {

	int i,c;

	for(i = 0; i < E_MUNICAO; i++) {

		if (e_municao[i].vivo == 1) {

			c = colisao(e_municao[i].danoBox, jogador.danoBox);

			if (c == 1) {

				if (jogador.vidas >= 0) {

					jogador.vidas--;
					pause_for(500);
				}
			}
		}
	}
}

//funcao para colisoes entre invader (inimigos) e o jogador
int inimigo_jogador_colisao() {

	int i,j,c;

	for(i = 0; i < 5; i++) {

		for(j = 0; j < 10; j++) {

			if (tanques.inimigo[i][j].vivo == 1) {

				c = colisao(jogador.danoBox, tanques.inimigo[i][j].danoBox);

				if (c == 1) {

					jogador.vidas--;
					pause_for(500);
					init_tanques();
					init_bases();
					return 1;
				}
			}
		}
	}

	return 0;
}

//Funcao para a colisao das balas nas bases de defesa
void municao_base_colisao(struct municao b[], int max, int l) {

	int i,j,c;

	for (i = 0; i < max; i++) {

		for (j = 0; j < BASE; j++) {

			if (b[i].vivo == 1) {

				c = colisao(b[i].danoBox, base[j].danoBox);

				if (c == 1) {

					municao_base_dano(&base[j], j, &b[i],l);
				}
			}
		}
	}
}

//funcao para Determinar o GAME OVER
void game_over_ai() {

	if (jogador.vidas < 0) {

		estado = game_over;
	}
}

//funcao para os tiros do jogador
void jogador_tiro() {

	int i;

	for (i = 0; i < P_MUNICAO; i++) {

		if (municao[i].vivo == 0) {

			//contador de tiros efetuados
			ponto.tiros++;

			municao[i].danoBox.x = jogador.danoBox.x + (P_LARGURA / 2);
			//-5 no final os tiros perto do topo da tela por causa da velocidade 30px
			municao[i].danoBox.y = jogador.danoBox.y - (municao[i].danoBox.h + 10);
			municao[i].vivo = 1;
			break;
		}
	}
}

//funcao para Determinar o nivel do jogo conforme mata os inimigos
void calcula_nivel() {

	if (tanques.morto != 0 && tanques.morto % 50 == 0) {

		ponto.nivel++;
		init_tanques();
		init_bases();
		pause_for(500);
	}
}

//funcao para Determinar quando os tanques devem atirar
void inimigo_ai() {

	int i, j, k;

	for (i = 0; i < 10; i++) {

		for (j = 4; j >= 0; j--) {

			if (tanques.inimigo[j][i].vivo == 1) {

				//jogador
				int med_ponto = jogador.danoBox.x + (jogador.danoBox.w / 2);

				//inimigo
				int start = tanques.inimigo[j][i].danoBox.x;
				int fim = tanques.inimigo[j][i].danoBox.x + tanques.inimigo[j][i].danoBox.w;

				if (med_ponto > start && med_ponto < fim) {

					//dispara se for possivel
					for (k = 0; k < E_MUNICAO; k++) {

						if (e_municao[k].vivo == 0) {

							int r = rand() % 30;

							if (r == 1) {
								e_municao[k].danoBox.x = start + (E_LARGURA / 2) ;
								e_municao[k].danoBox.y = tanques.inimigo[j][i].danoBox.y;
								e_municao[k].vivo = 1;
							}

							break;
						}
					}
				}

				// inimigo vivo inverte a grade inimiga e não verifica o resto da coluna
				break;
			}
		}
	}
}

//funcao para determinar quando pausar o jogo e por quanto tempo
void pause_game() {

	if (SDL_GetTicks() > pause_tempo + pause_len) {

		estado = game;
	}
}

// funcao para definir um tempo para pausar o jogo
void pause_for(unsigned int len) {

	estado = pause;
	pause_tempo = SDL_GetTicks();
	pause_len = len;
}

//funcao para Ler os arquivos de imagem
int load_image(char filename[], SDL_Surface **superficie, enum ck colour_key) {

	SDL_Surface *temp;

	//ler a imagem
	temp = SDL_LoadBMP(filename);

	if (temp == NULL) {

		printf("nao foi possivel carregar a imagem %s.\n", filename);
		return 1;
	}

	Uint32 colourkey;

	/* define as cores de imagem */
	if (colour_key == magenta) {

		colourkey = SDL_MapRGB(temp->format, 255, 0, 255);

	} else if (colour_key == lime) {

		colourkey = SDL_MapRGB(temp->format, 0, 255, 0);
	}

	SDL_SetColorKey(temp, SDL_SRCCOLORKEY, colourkey);

	//converte a imagem surface para o mesmo tipo da tela
	(*superficie) = SDL_DisplayFormat(temp);

	if ((*superficie) == NULL) {

		printf("Unable to convert bitmap.\n");
		return 1;
	}

	SDL_FreeSurface(temp);

	return 0;
}

		// MAIN
int main( int argc, char* argv[]) {

	/* Inicializa o vídeo do SDL e checa por erros */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {

		printf("Nao foi possivel inicializar SDL: %s\n", SDL_GetError());
		return 1;
	}

	/* garantir que o SDL_Quit funcione quando o programa acabar */
	atexit(SDL_Quit);

	/*Titulo na janela*/
	SDL_WM_SetCaption("Batalha campal", "P");

	/* Define o tamanho do video 800x600 (conforme include) com 8 bit de cor */
	tela = SDL_SetVideoMode(TELA_LARGURA, TELA_ALTURA, 8, SDL_DOUBLEBUF );

	if (tela == NULL) {

		printf("Nao foi possivel configurar o video: %s\n", SDL_GetError());
		return 1;
	}

	//ler as imagens
	load_image("titulo.bmp", &titulo_tela, magenta);
	load_image("cmap.bmp", &cmap, magenta);
	load_image("tanques.bmp", &tanquesmap, magenta);
	load_image("jogador.bmp", &jogador_img, magenta);
	load_image("gameover.bmp", &game_over_img, magenta);
	load_image("tiro.bmp", &dano_img, lime);
	load_image("tirocima.bmp", &dano_top_img, lime);

	Uint32 next_game_tick = SDL_GetTicks();
	int dorme = 0;
	Uint8 *keystate = 0;
	int sair = 0;
	SDL_Event event;

	init_ponto();
	init_tanques();
	init_bases();
	init_jogador();
	init_municao(municao, P_MUNICAO);
	init_municao(e_municao, E_MUNICAO);
	estado = menu;
	titulo_tempo = SDL_GetTicks();

	/* loop do jogo */
	while (sair == 0) {

		/* pegar a leitura do teclado. */
		keystate = SDL_GetKeyState(NULL);

		while (SDL_PollEvent(&event)) {

			switch(event.type) {

				case SDL_KEYDOWN:

					switch( event.key.keysym.sym ) {

						//sair do jogo de o esc for pressionado
						case SDLK_ESCAPE:

							sair = 1;
						break;

						case SDLK_SPACE:	// apertar espaco para comecar

							if (estado == menu) {

								estado = game;

							} else if (estado == game){ // espaco para atirar

								jogador_tiro();


							} else if (estado == game_over) {

								init_tanques();
								init_bases();
								init_ponto();
								init_jogador();
								estado = game;
							}
						break;

						default:
						break;
					}
				break;
			}
		}

		desenha_fundo(); // tela de fundo

		if (estado == menu) {

			char s[] = "Aperte a barra de ESPACO para comecar"; // mensagem de inicio
			SDL_Rect src[60];

			int i;

			if (titulo_tempo + 2000 < SDL_GetTicks())  {

				src[0].x = 180;
				src[0].y = 40;
				src[0].w = 440;
				src[0].h = 230;

				SDL_FillRect(tela, &src[0], 248);

			} else {

				int y = 0;

				for (i = 0; i < 60; i++) {

					src[i].x = 0;
					src[i].y = y;
					src[i].w = TELA_LARGURA;
					src[i].h = 10;

					SDL_FillRect(tela, &src[i], 227);

					y += 10;
				}

				for (i = 0; i < 60; i++) {

					SDL_FillRect(tela, &src[i], rand() % 255);

				}
			}

			desenha_titulo_tela();
			desenha_frase(s, (TELA_LARGURA / 2) - (strlen(s) * 10), 500);

		} else if (estado == game) {

			//movimento do jogador
			if (keystate[SDLK_LEFT]) {

				move_jogador(esquerda);
			}

			if (keystate[SDLK_RIGHT]) {

				move_jogador(direita);
			}

			desenha_hud();
			desenha_jogador();
			desenha_bases();
			desenha_tanques();
			desenha_tiros(municao, P_MUNICAO);
			desenha_tiros(e_municao, E_MUNICAO);
			inimigo_hit_colisao();
			jogador_hit_colisao();
			inimigo_base_colisao();
			municao_base_colisao(e_municao, E_MUNICAO, 1);
			municao_base_colisao(municao, P_MUNICAO, 0);
			inimigo_jogador_colisao();
			move_tanques(tanques.velocidade);
			move_municao(municao, P_MUNICAO, -30);
			move_municao(e_municao, E_MUNICAO, 15);
			calcula_nivel();
			inimigo_ai();
			game_over_ai();
			pause_game();

		} else if (estado == game_over) {

			desenha_hud();
			desenha_jogador();
			desenha_bases();
			desenha_tanques();
			desenha_tiros(municao, P_MUNICAO);
			desenha_tiros(e_municao, E_MUNICAO);
			desenha_game_over();

		} else if (estado == pause) {

			desenha_hud();
			desenha_jogador();
			desenha_bases();
			desenha_tanques();
			desenha_tiros(municao, P_MUNICAO);
			desenha_tiros(e_municao, E_MUNICAO);
			pause_game();
		}

		/* pede para a SDL atualizar a tela. */
		SDL_Flip(tela);

		next_game_tick += 1000 / 30;
		dorme = next_game_tick - SDL_GetTicks();

		if( dorme >= 0 ) {

            		SDL_Delay(dorme);
        	}
	}

	return 0;
}


