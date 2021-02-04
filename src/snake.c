/*
 * snake.c
 *
 *  Created on: 4 февр. 2021 г.
 *      Author: Paper
 */
#include "snake.h"
#include "game.h"
void generatesnake(SDL_Renderer *renderer) {
    for(int i = len.snake_l-1; i>0; i--){
        p.posx[i] = p.posx[i-1];
        p.posy[i] = p.posy[i-1];
    }
    for(int i = 0; i<len.snake_l; i++){
        if(i==0 || i==1){
            SDL_SetRenderDrawColor(renderer, 148, 0, 211, 255);
        }
        else{
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        }
        SDL_Rect sn = { p.posx[i], p.posy[i], cell_size, cell_size };
        SDL_RenderFillRect(renderer, &sn);
    }
}
