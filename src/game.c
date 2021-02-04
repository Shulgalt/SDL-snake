/*
 * game.c
 *
 *  Created on: 4 февр. 2021 г.
 *      Author: Paper
 */
#include "game.h"
#include "sdl.h"
int dir = 6;
void gamestatus(SDL_Renderer *renderer){
	len.snake_l=5;
    if(p.posy[0]==0-cell_size || p.posy[0]==(scr_width) || p.posx[0]==0-cell_size || p.posx[0]==(scr_height)){
    printf("\nGame over \n\nyour score: %d\n\n", f.score);
    exit(0);
    }
    int fx = f.foodx*cell_size;
    int fy = f.foody*cell_size;
    if(p.posx[0]==fx && p.posy[0]==fy){
        placefood(renderer);
        generatefood(renderer);
        f.score++;
        len.snake_l++;
    }
    for(int i=2; i<len.snake_l; i++){
    	len.snake_l =5;
        if(p.posx[0]==p.posx[i] && p.posy[0]==p.posy[i]){
            printf("\nGame over \n\nyour score: %d\n\n", f.score);
            exit(0);
        }
    }
}

void gamewindow(SDL_Renderer *renderer) {
	generategrid(renderer);
	generatefood(renderer);
    gamestatus(renderer);
    generatesnake(renderer);
}

int eventcontrol(SDL_Window *window){
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE || event.type == SDL_QUIT)
        {
            dir = 1;
        }
        else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP && dir!=2){
            dir = 8;
        }
        else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN && dir!=8){
            dir = 2;
        }
        else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT && dir!=6){
            dir = 4;
        }
        else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT && dir!=4){
            dir = 6;
        }
    }
    return dir;
}

