#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "constant.h"
#include "sdl.h"
#include "formula.h"
#include "time.h"
#include "food.h"
#include "game.h"
#include "snake.h"
#include <time.h>

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    printf("gcc version: %d.%d.%d\n",__GNUC__,__GNUC_MINOR__,__GNUC_PATCHLEVEL__);
    SDL_Window *window = SDL_CreateWindow("snakev game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, scr_height+1, scr_width+1, SDL_WINDOW_OPENGL);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    int framestart;
    int frametime;
    generatefood(renderer);
    placefood(renderer);
    int quit = 0;
    while(!quit)
    {
        framestart = SDL_GetTicks();
        frametime = SDL_GetTicks() - framestart;
        if(framedelay > frametime){
            SDL_Delay(framedelay - frametime);
        }
        int keypress = eventcontrol(window);
        if(keypress==1){ quit=1; }
        if(keypress==6){p.posx[0]+=cell_size;}
        if(keypress==8){p.posy[0]-=cell_size;}
        if(keypress==4){p.posx[0]-=cell_size;}
        if(keypress==2){p.posy[0]+=cell_size;}
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        gamewindow(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
