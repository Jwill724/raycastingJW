#include "include/raycaster.h"
#include <SDL2/SDL.h>
#include <string.h>
#include <stdio.h>

State state;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: %s\n", SDL_GetError());
        return 1;
    }
    state.window = SDL_CreateWindow("Raycaster", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!state.window){
        printf("Error: Failed to open window\nSDL Error: %s\n", SDL_GetError());
    }
    state.renderer = SDL_CreateRenderer(state.window, -1, SDL_RENDERER_ACCELERATED);
    if (!state.renderer){
        printf("Error: Failed to create render\nSDL Error: %s\n", SDL_GetError());
    }

    state.texture = SDL_CreateTexture(state.renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

    // position controllers
    state.pos = (v2){20.0f, 20.0f};
    state.dir = (v2){-1.0f, 0.0f};
    state.plane = (v2){0.0f, 0.60f};
    state.quit = false;

    while(!state.quit){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    state.quit = true;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE){
                        state.quit = true;
                    }
                    break;
            }
        }
/*
        // time of current and previous frame
        f64 curTime = 0;
        f64 oldTime = 0;

        oldTime = curTime;
        curTime = SDL_GetTicks();
        f64 fps = (curTime - oldTime) / 1000.0;
        printf("%lf\n", fps);
*/
        const f32 
            rotspeed = 2.0f * 0.016f, 
            movespeed = 2.0f * 0.016f;

        const u8 *keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_A]) {
            rotate(&state, +rotspeed);
        }

        if (keystate[SDL_SCANCODE_D]) {
            rotate(&state, -rotspeed);
        }

        if (keystate[SDL_SCANCODE_W]) {
            state.pos.x += state.dir.x * movespeed;
            state.pos.y += state.dir.y * movespeed;
        }

        if (keystate[SDL_SCANCODE_S]) {
            state.pos.x -= state.dir.x * movespeed;
            state.pos.y -= state.dir.y * movespeed;
        }
        memset(state.pixels, 0, sizeof(state.pixels));
        render(&state);


        SDL_UpdateTexture(state.texture, NULL, state.pixels, SCREEN_WIDTH * sizeof(u32));
        SDL_RenderClear(state.renderer);
        SDL_RenderCopy(state.renderer, state.texture, NULL, NULL);
        SDL_RenderPresent(state.renderer);
    }

    SDL_DestroyTexture(state.texture);
    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.window);
    SDL_Quit();

    return 0;
}