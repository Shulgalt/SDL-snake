/*
 * food.c
 *
 *  Created on: 4 февр. 2021 г.
 *      Author: Paper
 */
#include "food.h"
#include "game.h"
int placefood(SDL_Renderer *renderer) {
    srand(time(NULL));
    f.foodx = rand() % cell_width;
    f.foody = rand() % cell_height;
    return 0;
}

void generatefood(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect rect = { f.foodx*cell_size, f.foody*cell_size, cell_size, cell_size };
    SDL_RenderFillRect(renderer, &rect);
}
