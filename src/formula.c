/*
 * formula.c
 *
 *  Created on: 4 февр. 2021 г.
 *      Author: Paper
 */
#include "formula.h"

void generategrid(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect field = {
        start_cell_x * cell_size,
        start_cell_y * cell_size,
        cell_width * cell_size,
        cell_height * cell_size
    };

    SDL_RenderFillRect(renderer, &field);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i <= cell_width; i++) {
        if(i==0 || i==cell_width ){
            SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
            SDL_RenderDrawLine(renderer, i * cell_size, 0, i * cell_size, cell_height * cell_size);
        }
    }
    for (int i = 0; i <= cell_height; i++) {
        if(i==0 || i==cell_height ){
            SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
            SDL_RenderDrawLine(renderer, 0, i * cell_size, cell_width * cell_size, i * cell_size);
        }
    }
}
