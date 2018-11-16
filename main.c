#include "graphics.h"

#include <SDL2/SDL.h>

#include <stdbool.h>

int mainLoop();
int initSDL();

int main(int argc, char *argv[])
{
    initSDL();
    mainLoop();
    return 0;
}

int initSDL()
{
    int status = SDL_Init(SDL_INIT_VIDEO);
    return status;
}

int mainLoop()
{
    // set up render
    RenderTarget target;
    initRenderTarget(&target);

    for (int i = 0; i < 720000; ++i) {
        if (i % 50 < 25)
            target.framebuffer[i] = 0x0000FFFF;
        else
            target.framebuffer[i] = 0xFFFF0000;
    }
    
    while (1) {
        displayRenderTarget(&target);
    }
}