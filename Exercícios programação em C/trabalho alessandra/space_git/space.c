/* 
		Para compilar:
		gcc -o main space_invaders.cpp -lSDLmain -lSDL -lGL
		Para executar:
		./main

 */

#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_opengl.h>

#define SCREEN_WIDTH 800 
#define SCREEN_HEIGHT 600
#define E_WIDTH 30
#define WIDTH 600 
#define HEIGHT 600
#define E_WIDTH 30
#define E_HEIGHT 30
#define P_WIDTH 30
#define P_HEIGHT 10
#define B_WIDTH 5
#define B_HEIGHT 15
#define P_BULLETS 1
#define E_BULLETS 3
#define BASE 4
#define BASE_WIDTH 60
#define BASE_HEIGHT 40

/* ainda faltam mais comentarios para fazer
*/

enum colour_t {red, green, purple};
enum direction_t {left, right, stationary};
enum state_t {menu, options, game, game_over, pause};
enum ck_t {magenta, lime};

struct score_t { // pontuacao ainda nao tem na tela

	unsigned int shots;
	unsigned int points;
	unsigned int level;
};

struct saucer_t { //disco voador que aparece bonus
	
	SDL_Rect hitbox;
	unsigned int alive;
	enum direction_t direction;
};

struct enemy_t { // estrutura dos inimigos para usar no invaders

	SDL_Rect hitbox;
	enum colour_t colour;
	unsigned int alive;
	unsigned int points;
};

struct invaders_t { // invaders

	struct enemy_t enemy[5][10];
	enum direction_t direction;
	unsigned int killed;
	int speed;
	int state;
	int state_speed;
	Uint32 state_time;
};

struct base_t { // bases de defesa

	SDL_Rect hitbox;
};

struct player_t { // jogador

	SDL_Rect hitbox;
	int lives;
};

struct bullet_t { // tiro
	
	SDL_Rect hitbox;
	unsigned int alive;
};

//Variaveis globais.
static SDL_Surface *screen;
static SDL_Surface *title_screen;
static SDL_Surface *cmap;
static SDL_Surface *invadersmap;
static SDL_Surface *player_img;
static SDL_Surface *saucer_img;
static SDL_Surface *base_img[4];
static SDL_Surface *damage_img;
static SDL_Surface *damage_top_img;
static SDL_Surface *game_over_img;
struct score_t score;
struct invaders_t invaders;
struct saucer_t saucer;
struct base_t base[BASE];
struct player_t player;
struct bullet_t bullets[P_BULLETS];
struct bullet_t e_bullets[E_BULLETS];
unsigned int pause_len;
Uint32 pause_time;
enum state_t state;
Uint32 title_time;

void draw_string(char s[], int x, int y);
void pause_for(unsigned int len);

int load_image(char filename[], SDL_Surface **surface, enum ck_t colour_key);

// funcao para inicializar a estrutura de pontuacao
void init_score() {

	score.shots = 0;
	score.points = 0;
	score.level = 1;
}

// funcao para inicializar os inimigos (posicao, direcao, velocidade)
void init_invaders() {
	
	invaders.direction = right;
	invaders.speed = 1;
	invaders.state = 0;
	invaders.killed = 0;
	invaders.state_speed = 1000;
	invaders.state_time = SDL_GetTicks();

	int i,j;
	int x = 0;
	int y = 30;
	
	for (i = 0; i < 5; i++) {
	
		for (j = 0; j < 10; j++) {
		
			invaders.enemy[i][j].alive = 1;
			invaders.enemy[i][j].hitbox.x = x;
			invaders.enemy[i][j].hitbox.y = y;
			invaders.enemy[i][j].hitbox.w = E_WIDTH;
			invaders.enemy[i][j].hitbox.h = E_HEIGHT;
			
			x += E_WIDTH + 15; // tamanho da lacuna entre os invaders
			
			if (i == 0) {
				
				invaders.enemy[i][j].colour = purple;
				invaders.enemy[i][j].points = 30;
	
			} else if (i >= 1 && i < 3) {
			
				invaders.enemy[i][j].colour = green;
				invaders.enemy[i][j].points = 20;
		
			} else {
		
				invaders.enemy[i][j].colour = red;
				invaders.enemy[i][j].points = 10;
			}
		}
		
		x = 0; //reseta a linha
		y += E_HEIGHT + 15;
	}
}

//funcao para inicializar o jogador (posicao e dimensao)
void init_player() {

	player.hitbox.x = (WIDTH / 2) - (P_WIDTH / 2);
	player.hitbox.y = HEIGHT - (P_HEIGHT + 10);
	player.hitbox.w = P_WIDTH;
	player.hitbox.h = P_HEIGHT;
	player.lives = 3;
}

//funcao para inicializar as bases (posicao e dimensao)
void init_bases() {

	int i;
	int base_total = BASE_WIDTH * 4;
	int space_left = WIDTH - base_total;
	int even_space = space_left / 5; // 5 espacos
	int x = even_space;
	int y = 500;

	for (i = 0; i < BASE; i++) {
		
		base[i].hitbox.x = x;
		base[i].hitbox.y = y;
		base[i].hitbox.w = BASE_WIDTH;
		base[i].hitbox.h = BASE_HEIGHT;
		
		x += BASE_WIDTH + even_space; //distanciamento
	}

	load_image("base.bmp", &base_img[0], magenta);
	load_image("base.bmp", &base_img[1], magenta);
	load_image("base.bmp", &base_img[2], magenta);
	load_image("base.bmp", &base_img[3], magenta);
}

//funcao para inicializar os tiros do jogador
void init_bullets(struct bullet_t b[], int max) {

	int i;

	for (i = 0; i < max; i++) {
	
		b[i].alive = 0;
		b[i].hitbox.x = 0;
		b[i].hitbox.y = 0;
		b[i].hitbox.w = B_WIDTH;
		b[i].hitbox.h = B_HEIGHT;
	}
}

//funcao para inicializar o saucer (disco voador)
void init_saucer() {

	saucer.hitbox.x = 0;	
	saucer.hitbox.y	= 0;
	saucer.hitbox.w	= 30;
	saucer.hitbox.h = 20;
	saucer.alive = 0;
	saucer.direction = right;
}

//funcao para desenhar o background
void draw_background () {

	SDL_Rect src;

	src.x = 0;
	src.y = 0;
	src.w = screen->w;
	src.h = screen->h;
	
	SDL_FillRect(screen,&src,0);
}

//funcao para desenhar o HUD ----não sei direito o que e isso mas não está funcionando 
void draw_hud() {
	
	SDL_Rect r;
	
	r.x = WIDTH;
	r.y = 0;
	r.w = SCREEN_WIDTH - WIDTH;
	r.h = SCREEN_HEIGHT;

	SDL_FillRect(screen, &r, 41);
	
	char score_label[] = "Score";
	draw_string(score_label, WIDTH, 0);
	
	char score_num[10];
	snprintf(score_num, 10, "%d", score.points);
	draw_string(score_num, WIDTH, 20);

	char level[] = "Level";
	draw_string(level, WIDTH, 60);
	
	char level_num[2];
	snprintf(level_num, 2, "%d", score.level);
	draw_string(level_num, WIDTH, 80);
	
	char lives[] = "Lives";
	draw_string(lives, WIDTH, 120);
	
	char lives_num[2];
	snprintf(lives_num, 2, "%d", player.lives);
	draw_string(lives_num, WIDTH, 140);
	
	char author[] = "Feito por";
	draw_string(author, WIDTH, 540);
	
	char name[] = "Grupo do Jogo - Bruno, Eduardo e Octavio";
	draw_string(name, WIDTH, 560);
}

//funcao para desenhar a tela de titulo
void draw_title_screen() {
	
	SDL_Rect src;
	SDL_Rect dest;

	src.x = 0;
	src.y = 0;
	src.w = title_screen->w;
	src.h = title_screen->h;

	dest.x = (SCREEN_WIDTH / 2) - (title_screen->w / 2);
	dest.y = 0;
	dest.w = title_screen->w;
	dest.h = title_screen->h;
	
	SDL_BlitSurface(title_screen, &src, screen, &dest);
}

// funcao para desenhar o saucer se estiver vivo
void draw_saucer() {

	SDL_Rect src;
	
	src.x = 0;
	src.y = 0;
	src.w = 30;
	src.h = 20;
	
	if (saucer.alive == 1) {
		
		SDL_BlitSurface(saucer_img, &src, screen, &saucer.hitbox);
	}
}

//funcao para desenhar os invaders se estiverem vivos
void draw_invaders() {

	SDL_Rect src, dest;
	int i,j;
	
	src.w = E_WIDTH;
	src.h = E_HEIGHT;
	
	for (i = 0; i < 5; i++) {
		
		for (j = 0; j < 10; j++) {
			
			if (invaders.enemy[i][j].alive == 1) {
				
				//roxo
				if(i == 0) {	
					
					if (invaders.state == 0) {
						
						src.x = 0;
						src.y = 0;
					
					} else {
						
						src.x = 30;
						src.y = 0;				
					}
				
				//verde
				} else if (i > 0 && i < 3) {
					
					if (invaders.state == 0) {
						
						src.x = 0;
						src.y = E_HEIGHT;

					} else {
						
						src.x = 30;
						src.y = E_HEIGHT;
					}

				//vermelho
				} else {
					
					if (invaders.state == 0) {
					
						src.x = 0;
						src.y = E_HEIGHT * 2;
					
					} else {
					
						src.x = 30;
						src.y = E_HEIGHT * 2;	
					}
				}

				dest.x = invaders.enemy[i][j].hitbox.x;
				dest.y = invaders.enemy[i][j].hitbox.y;
				dest.w = invaders.enemy[i][j].hitbox.w;
				dest.h = invaders.enemy[i][j].hitbox.h;
				
				SDL_BlitSurface(invadersmap, &src, screen, &dest);
			}
		}
	}
}

//funcao para desenhar as bases
void draw_bases() {

	SDL_Rect src;

	src.x = 0;
	src.y = 0;
	src.w = BASE_WIDTH;
	src.h = BASE_HEIGHT;

	int i;

	for(i = 0; i < BASE; i++) {
		
		SDL_BlitSurface(base_img[i], &src, screen, &base[i].hitbox);
	}
}

//Draw the player
void draw_player() {

	SDL_Rect src;

	src.x = 0;
	src.y = 0;
	src.w = P_WIDTH;
	src.h = P_HEIGHT;

	SDL_BlitSurface(player_img, &src, screen, &player.hitbox);
}

//Draw both the enemy and the players bullets if there alive
void draw_bullets(struct bullet_t b[], int max) {

	//Uint8 c = SDL_MapRGB(screen->format, 255, 255, 255);
	int i;


	for (i = 0; i < max; i++) {
	
		if (b[i].alive == 1) {
		
			SDL_FillRect(screen, &b[i].hitbox, 255);
		}
	}
}

//Draw a char
int draw_char(char c, int x, int y) {

	SDL_Rect src;
	SDL_Rect dest;
	int i,j;
	char *map[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
			"abcdefghijklmnopqrstuvwxyz",
			"!@#$%^&*()_+{}|:\"<>?,.;'-=",
			"0123456789"};

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
			
				SDL_BlitSurface(cmap, &src, screen, &dest);
				return 0;
			}

			src.x += 20;
		}
	
		src.y += 20;//move down one line on the image file
		src.x = 0; //reset to start of line
	}

	return 0;
}

//Draw a string of chars
void draw_string(char s[], int x, int y) {

	int i;

	for (i = 0; i < strlen(s); i++) {
	
		draw_char(s[i],x,y);
		x += 20;
	}
}

//Draw Game Over message
void draw_game_over() {
		
	SDL_Rect src;
	SDL_Rect dest;

	src.x = 0;
	src.y = 0;
	src.w = game_over_img->w;
	src.h = game_over_img->h;

	dest.x = (WIDTH / 2) - (game_over_img->w / 2);
	dest.y = (HEIGHT / 2) - (game_over_img->h / 2);
	dest.w = game_over_img->w;
	dest.h = game_over_img->h;
	
	SDL_BlitSurface(game_over_img, &src, screen, &dest);
}

//Set invader movment speed
void set_invaders_speed() {

	switch (invaders.killed) {
		
		case 10:

			invaders.speed = 2;
			invaders.state_speed = 800;
			break;
		
		case 20:

			invaders.speed = 4;
			invaders.state_speed = 600;
			break;
		
		case 30:

			invaders.speed = 8;
			invaders.state_speed = 200;
			break;
		
		case 40:

			invaders.speed = 16;
			invaders.state_speed = 0;
			break;
	}
}

//Move positions of both enemy and player bullets on screen
int move_bullets(struct bullet_t b[], int max, int speed) {
	
	int i;

	for(i = 0; i < max; i++) {
	
		if (b[i].alive == 1) {
			
			b[i].hitbox.y += speed;
			
			if (b[i].hitbox.y <= 0) {
		
				b[i].alive = 0;	
			}
			
			if (b[i].hitbox.y + b[i].hitbox.h >= HEIGHT) {
		
				b[i].alive = 0;	
			}
		}
	}

	return 0;
}

//Move invaders down one space once the reach the edge
void move_invaders_down() {

	int i,j;

	for (i = 0; i < 5; i++) {
		
		for (j = 0; j < 10; j++) {
		
			invaders.enemy[i][j].hitbox.y += 15;
		}
	}
}

//Move invaders based on there current direction
int move_invaders(int speed) {
	
	set_invaders_speed();
	
	int i,j;

	switch (invaders.direction) {
		
		case left:
		
			for (i = 0; i < 10; i++) {
			
				for (j = 0; j < 5; j++) {
				
					if (invaders.enemy[j][i].alive == 1) {
		
						if (invaders.enemy[j][i].hitbox.x <= 0) {
						
							invaders.direction = right;
							move_invaders_down();
							return 0;
						}
						
						if (invaders.state_time + invaders.state_speed < SDL_GetTicks()) {
						
							invaders.state_time = SDL_GetTicks();
							
							if (invaders.state == 1) {
								
								invaders.state = 0;

							} else {
								
								invaders.state = 1;
							}
						}
						
						//move invader speed number of pixels
						invaders.enemy[j][i].hitbox.x -= invaders.speed;
					}
				}
			}

			break;

		case right:
			
			for (i = 9; i >= 0; i--) {
			
				for (j = 0; j < 5; j++) {
				
					if (invaders.enemy[j][i].alive == 1) {
					
						if (invaders.enemy[j][i].hitbox.x + E_WIDTH >= WIDTH) {
					
							invaders.direction = left;
							move_invaders_down();
							return 0;
						}
		
						if (invaders.state_time + invaders.state_speed < SDL_GetTicks()) {
						
							invaders.state_time = SDL_GetTicks();

							if (invaders.state == 1) {
								
								invaders.state = 0;

							} else {
								
								invaders.state = 1;
							}
						}
						
						invaders.enemy[j][i].hitbox.x += invaders.speed;
					}
				}
			}

			break;

		default:
			break;

	}

	return 0;
}

//Move player left or right
void move_player(enum direction_t direction) {

	if (direction == left) {
			
		if (player.hitbox.x > 0) {
			
			player.hitbox.x -= 10;
		}

	} else if (direction == right) {

		if (player.hitbox.x + player.hitbox.w < WIDTH){

			player.hitbox.x += 10;
		}
	}
}

//Move saucer based on there current direction
void move_saucer() {

	if (saucer.alive == 1) {

		if (saucer.direction == left) {
		
			saucer.hitbox.x -= 5;

			if (saucer.hitbox.x < 0) {
				
				saucer.alive = 0;
				saucer.hitbox.x = 0;
				saucer.direction = right;
			}
		}

		if (saucer.direction == right) {
		
			saucer.hitbox.x += 5;

			if (saucer.hitbox.x + saucer.hitbox.w > WIDTH) {
			
				saucer.alive = 0;
				saucer.hitbox.x = WIDTH - saucer.hitbox.w;
				saucer.direction = left;
			}
		}
	}
}

//Detect any collision between any two non rotated rectangles
int collision(SDL_Rect a, SDL_Rect b) {

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

//Create damage to the base sprite for player and enemy bullet collisions
void bullet_base_damage(struct base_t *base, int b_num, struct bullet_t *bullet, int l) {

	int i;
	int x,y;
	SDL_Rect src;
	SDL_Rect dest;
				
	SDL_LockSurface(base_img[b_num]);
	Uint8 *raw_pixels;

	raw_pixels = (Uint8 *) base_img[b_num]->pixels;
	
	int pix_offset;

	//bottom
	if (l == 0) {
	
		//how far from the left did the bullet hit the base sprite
		x = (bullet->hitbox.x + 3) - base->hitbox.x;

		//start from bottom of the base sprite
		y = base->hitbox.h - 1;

		for(i = 0; i < base->hitbox.h; i++) {
		
			//the x calculation can get us to pixel column 60 when 59 is the maximum (0 - 59 is 60 pixels)
			if (x >= BASE_WIDTH) {
				x = BASE_WIDTH - 1;
			}

			pix_offset = y * base_img[b_num]->pitch  + x;	

			//found part part of the base sprite that is NOT magenta(index)
			//searching from the bottom up
			if (raw_pixels[pix_offset] != 227) {
					
				bullet->alive = 0;
				
				src.x = 0;
				src.y = 0;
				src.w = 11;
				src.h = 15;

				dest.x = x - 3;
				dest.y = y - 14;
				dest.w = 11;
				dest.h = 15;
				
				SDL_UnlockSurface(base_img[b_num]);
				SDL_BlitSurface(damage_img, &src, base_img[b_num], &dest);
				
				break;
			}
			
			y--;
		}
	}
	
	//top
	if (l == 1) {

		//how far from the left did the bullet hit the base sprite
		x = (bullet->hitbox.x + 3) - base->hitbox.x;

		//start from top of the base sprite
		y = 0;
		
		for(i = 0; i < base->hitbox.h; i++) {
			
			//the x calculation can get us to pixel column 60 when 59 is the maximum (0 - 59 is 60 pixels)
			if (x >= BASE_WIDTH) {
				x = BASE_WIDTH - 1;
			}

			pix_offset = y * base_img[b_num]->pitch  + x;	
		
			//found part part of the base sprite that is NOT magenta(index)
			//searching from the top down
			if (raw_pixels[pix_offset] != 227) {
					
				bullet->alive = 0;
			
				src.x = 0;
				src.y = 0;
				src.w = 11;
				src.h = 15;

				dest.x = x - 3;
				dest.y = y;
				dest.w = 11;
				dest.h = 15;
				
				SDL_UnlockSurface(base_img[b_num]);
				SDL_BlitSurface(damage_top_img, &src, base_img[b_num], &dest);
				
				break;
			}
			
			y++;
		}
	}

	SDL_UnlockSurface(base_img[b_num]);
}

//funcao para criar dano nas bases coma colisao com os inimigos
void enemy_base_damage(struct enemy_t *enemy, struct base_t *base, int index) {
	
	int x,y;
	SDL_Rect dest;

	/*O x é o ponto tirado da parte superior esquerda do sprite com a velocidade em pixels
	adicionado adiante no caso de o inimigo escapar dos últimos pixels do sprite e
	a colisão não é mais detectada. Velocidade em pixels é subtraída se viajar para a esquerda*/
	
	if (invaders.direction == right) {
	
		x = (enemy->hitbox.x + invaders.speed) - base->hitbox.x;
		y = enemy->hitbox.y - base->hitbox.y;
		
		if (x > 0) {
			
			dest.x = 0;
			dest.y = y;
			dest.w = x;
			dest.h = enemy->hitbox.h;
		
			SDL_FillRect(base_img[index], &dest, 227);
		}
	
	} else if (invaders.direction == left){
		
		x = (enemy->hitbox.x + (enemy->hitbox.w - 1)) - invaders.speed;
		x = x - base->hitbox.x;
		y = enemy->hitbox.y - base->hitbox.y;

		if (x < base->hitbox.w) {
		
			dest.x = x;
			dest.y = y;
			dest.w = base->hitbox.w - 1;
			dest.h = enemy->hitbox.h;
		
			SDL_FillRect(base_img[index], &dest, 227);
		}
	}		
}

//funcao para colisao entre o inimigo e base rectangles
void enemy_base_collision() {

	int i,j,k,c;

	for (i = 0; i < 5; i++) {

		for (j = 0;  j < 10; j++) {
		
			for (k = 0;  k < BASE; k++) {
			
				if (invaders.enemy[i][j].alive == 1) {
				
					c = collision(invaders.enemy[i][j].hitbox,base[k].hitbox);		
					
					if (c == 1) {
						
						enemy_base_damage(&invaders.enemy[i][j], &base[k], k);
					}
				}
			}
		}
	}
}

//funcao para a colisao entre o tiro do jogador e os invaders (inimigos)
void enemy_hit_collision() {

	int i,j,k,c;
	
	for (i = 0; i < 5; i++) {
		
		for (j = 0; j < 10; j++) {
			
			if (invaders.enemy[i][j].alive == 1) {
			
				for (k = 0; k < P_BULLETS; k++) {
			
					if (bullets[k].alive == 1) {
						
						c = collision(bullets[k].hitbox, invaders.enemy[i][j].hitbox);
				
						if (c == 1) {
				
							invaders.enemy[i][j].alive = 0;
							bullets[k].alive = 0;
							bullets[k].hitbox.x = 0;
							bullets[k].hitbox.y = 0;
							invaders.killed++;
							score.points += invaders.enemy[i][j].points;
						}
					}
				}
			}
		}
	}
}

//funcao para colisao entre o tiro inimigo e o jogador
void player_hit_collision() {

	int i,c;

	for(i = 0; i < E_BULLETS; i++) {
	
		if (e_bullets[i].alive == 1) {

			c = collision(e_bullets[i].hitbox, player.hitbox);

			if (c == 1) {
				
				if (player.lives >= 0) {
				
					player.lives--;
					pause_for(500);
				}
			}
		}
	}
}

//funcao para as colisoes nos tiros do jogador com saucer
void saucer_hit_collision() {

	int i,c;

	if (saucer.alive == 1) {
	
		for(i = 0; i < P_BULLETS; i++) {
	
			if (bullets[i].alive == 1) {
			
				c = collision(bullets[i].hitbox, saucer.hitbox);
	
				if (c == 1) {
				
					int r = rand() % 3;
					
					switch (r) {
			
						case 0:
							score.points += 50;
							break;
	
						case 1:
							score.points += 150;
							break;
	
						case 2:
							score.points += 300;
							break;
	
						default:
							break;
					}
					
					//saucer (disco voador) foi atingido reseta para a proxima
					saucer.alive = 0;
					
					if (saucer.direction == left) {
						
						saucer.hitbox.x = 0; 
						saucer.direction = right; 
	
					} else if (saucer.direction == right) {
					
						saucer.hitbox.x = WIDTH - saucer.hitbox.w; 
						saucer.direction = left; 
					}
				}
			}
		}
	}
}

//funcao para colisoes entre invader (inimigos) e o jogador
int enemy_player_collision() {

	int i,j,c;

	for(i = 0; i < 5; i++) {

		for(j = 0; j < 10; j++) {
		
			if (invaders.enemy[i][j].alive == 1) {
					
				c = collision(player.hitbox, invaders.enemy[i][j].hitbox);

				if (c == 1) {
				
					player.lives--;
					pause_for(500);
					init_invaders();
					init_bases();
					return 1;
				}
			}
		}
	}

	return 0;
}

//Funcao para a colisao das balas nas bases de defesa
void bullet_base_collision(struct bullet_t b[], int max, int l) {

	int i,j,c;

	for (i = 0; i < max; i++) {
		
		for (j = 0; j < BASE; j++) {
	
			if (b[i].alive == 1) {
			
				c = collision(b[i].hitbox, base[j].hitbox);

				if (c == 1) {
					
					bullet_base_damage(&base[j], j, &b[i],l);
				}
			}
		}
	}
}

//funcao para Determinar o GAME OVER
void game_over_ai() {
	
	if (player.lives < 0) {
		
		state = game_over;
	}
}

//funcao para os tiros do jogador
void player_shoot() {

	int i;
	
	for (i = 0; i < P_BULLETS; i++) {
				
		if (bullets[i].alive == 0) {
			
			//contador de tiros efetuados
			score.shots++;

			bullets[i].hitbox.x = player.hitbox.x + (P_WIDTH / 2);
			//-5 no final os tiros perto do topo da tela por causa da velocidade 30px
			bullets[i].hitbox.y = player.hitbox.y - (bullets[i].hitbox.h + 10);
			bullets[i].alive = 1;
			break;
		}
	}
}

//funcao para Determinar o nivel do jogo conforme mata os inimigos
void calculate_level() {

	if (invaders.killed != 0 && invaders.killed % 50 == 0) {
		
		score.level++;
		init_invaders();
		init_bases();
		init_saucer();
		pause_for(500);
	}
}

// funcao para Determinar quando o saucer (disco voador) deve aparecer
void saucer_ai() {

	//every 20 shots
	if (score.shots != 0 && score.shots % 20 == 0) {
	
		saucer.alive = 1;
	}
}

//funcao para Determinar quando os invaders devem atirar
void enemy_ai() {

	int i, j, k;

	for (i = 0; i < 10; i++) {
		
		for (j = 4; j >= 0; j--) {
			
			if (invaders.enemy[j][i].alive == 1) {
				
				//jogador
				int mid_point = player.hitbox.x + (player.hitbox.w / 2);
				
				//inimigo
				int start = invaders.enemy[j][i].hitbox.x;
				int end = invaders.enemy[j][i].hitbox.x + invaders.enemy[j][i].hitbox.w;

				if (mid_point > start && mid_point < end) {

					//dispara se for possivel
					for (k = 0; k < E_BULLETS; k++) {
			
						if (e_bullets[k].alive == 0) {
				
							int r = rand() % 30;

							if (r == 1) {
								e_bullets[k].hitbox.x = start + (E_WIDTH / 2) ;
								e_bullets[k].hitbox.y = invaders.enemy[j][i].hitbox.y;
								e_bullets[k].alive = 1;
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

	if (SDL_GetTicks() > pause_time + pause_len) {
	
		state = game;
	}
}

// funcao para definir um tempo para pausar o jogo
void pause_for(unsigned int len) {

	state = pause;
	pause_time = SDL_GetTicks();
	pause_len = len;
}

//funcao para Ler os arquivos de imagem
int load_image(char filename[], SDL_Surface **surface, enum ck_t colour_key) {
	
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
	(*surface) = SDL_DisplayFormat(temp);
	
	if ((*surface) == NULL) {
	
		printf("Unable to convert bitmap.\n");
		return 1;
	}
	
	SDL_FreeSurface(temp);

	return 0;
}

		// MAIN 
int main() {
	
	/* Inicializa o vídeo do SDL e checa por erros */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {

		printf("Nao foi possivel inicializar SDL: %s\n", SDL_GetError());
		return 1;
	}
	
	/* garantir que o SDL_Quit funcione quando o programa acabar */
	atexit(SDL_Quit);
	
	/*Titulo na janela*/
	SDL_WM_SetCaption("Space Invaders", "P");
	
	/* Define o tamanho do video 800x600 (conforme include) com 8 bit de cor */
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 8, SDL_DOUBLEBUF );
	
	if (screen == NULL) {
		
		printf("Nao foi possivel configurar o video: %s\n", SDL_GetError());
		return 1;
	}

	//ler as imagens
	load_image("titlescreen.bmp", &title_screen, magenta);
	load_image("cmap.bmp", &cmap, magenta);
	load_image("invaders.bmp", &invadersmap, magenta);
	load_image("player.bmp", &player_img, magenta);
	load_image("saucer.bmp", &saucer_img, magenta);
	load_image("gameover.bmp", &game_over_img, magenta);
	load_image("damage.bmp", &damage_img, lime);
	load_image("damagetop.bmp", &damage_top_img, lime);

	Uint32 next_game_tick = SDL_GetTicks();
	int sleep = 0;
	Uint8 *keystate = 0;
	int quit = 0;
	SDL_Event event;

	init_score();
	init_invaders();
	init_bases();
	init_player();
	init_saucer();
	init_bullets(bullets, P_BULLETS);
	init_bullets(e_bullets, E_BULLETS);
	state = menu;
	title_time = SDL_GetTicks();
		
	/* loop do jogo */
	while (quit == 0) {
		
		/* pegar a leitura do teclado. */
		keystate = SDL_GetKeyState(NULL);
		
		while (SDL_PollEvent(&event)) {

			switch(event.type) {
				
				case SDL_KEYDOWN:
					
					switch( event.key.keysym.sym ) {
					
						//sair do jogo de o esc for pressionado
						case SDLK_ESCAPE:
							
							quit = 1;
						break;
						
						case SDLK_SPACE:	// apertar espaco para comecar
						
							if (state == menu) {

								state = game;

							} else if (state == game){ // espaco para atirar
								
								player_shoot();
								saucer_ai();
							
							} else if (state == game_over) {
							
								init_invaders();
								init_bases();
								init_score();
								init_player();
								state = game;
							}
						break;
						
						default:
						break;
					}
				break;
			}
		}
	
		draw_background(); // tela de fundo

		if (state == menu) {
			
			char s[] = "Aperte a barra de ESPACO para comecar"; // mensagem de inicio
			SDL_Rect src[60];
			
			int i;

			if (title_time + 2000 < SDL_GetTicks())  {
			
				src[0].x = 180;
				src[0].y = 40;
				src[0].w = 440;
				src[0].h = 230;
			
				SDL_FillRect(screen, &src[0], 248);
			
			} else {
			
				int y = 0;

				for (i = 0; i < 60; i++) {
				
					src[i].x = 0;
					src[i].y = y;
					src[i].w = SCREEN_WIDTH;
					src[i].h = 10;

					SDL_FillRect(screen, &src[i], 227);
				
					y += 10;							
				}
			
				for (i = 0; i < 60; i++) {

					SDL_FillRect(screen, &src[i], rand() % 255);

				}
			}
			
			draw_title_screen();	
			draw_string(s, (SCREEN_WIDTH / 2) - (strlen(s) * 10), 500);

		} else if (state == game) {

			//movimento do jogador
			if (keystate[SDLK_LEFT]) {
				
				move_player(left);
			}

			if (keystate[SDLK_RIGHT]) {
				
				move_player(right);
			}

			draw_hud();
			draw_player();
			draw_bases();
			draw_invaders();
			draw_saucer();
			draw_bullets(bullets, P_BULLETS);
			draw_bullets(e_bullets, E_BULLETS);
			enemy_hit_collision();
			player_hit_collision();
			enemy_base_collision();
			saucer_hit_collision();
			bullet_base_collision(e_bullets, E_BULLETS, 1);
			bullet_base_collision(bullets, P_BULLETS, 0);
			enemy_player_collision();
			move_invaders(invaders.speed);
			move_saucer();
			move_bullets(bullets, P_BULLETS, -30);
			move_bullets(e_bullets, E_BULLETS, 15);
			calculate_level();
			enemy_ai();
			game_over_ai();
			pause_game();
		
		} else if (state == game_over) {
			
			draw_hud();
			draw_player();
			draw_bases();
			draw_invaders();
			draw_saucer();
			draw_bullets(bullets, P_BULLETS);
			draw_bullets(e_bullets, E_BULLETS);
			draw_game_over();
		
		} else if (state == pause) {
			
			draw_hud();
			draw_player();
			draw_bases();
			draw_invaders();
			draw_saucer();
			draw_bullets(bullets, P_BULLETS);
			draw_bullets(e_bullets, E_BULLETS);
			pause_game();
		}

		/* pede para a SDL atualizar a tela. */
		SDL_Flip(screen);

		next_game_tick += 1000 / 30;
		sleep = next_game_tick - SDL_GetTicks();
	
		if( sleep >= 0 ) {

            		SDL_Delay(sleep);
        	}
	}
	
	return 0;
}

