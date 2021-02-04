/*
 * game.h
 *
 *  Created on: 4 февр. 2021 г.
 *      Author: Paper
 */

#ifndef GAME_H_
#define GAME_H_
#include "constant.h"
#include "sdl.h"
struct length {
	int snake_l;
} len;
struct pos {
	int posx[max];
	int posy[max];
} p;

struct food {
	int foodx;
	int foody;
	int score;
} f;

void gamestatus(SDL_Renderer *renderer);

void gamewindow(SDL_Renderer *renderer);

int eventcontrol(SDL_Window *window);


#endif /* GAME_H_ */
