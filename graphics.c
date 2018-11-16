#include "graphics.h"

int initRenderTarget(RenderTarget* target)
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_CreateWindowAndRenderer(600, 600, SDL_WINDOW_BORDERLESS, &window, &renderer);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 600, 600);
    target->framebuffer = malloc(600*600*sizeof(uint32_t*));
    target->texture = texture;
    target->renderer = renderer;
}

int displayRenderTarget(RenderTarget * target)
{
    SDL_UpdateTexture(target->texture, NULL, target->framebuffer, 600 * sizeof(uint32_t*));

    SDL_RenderClear(target->renderer);
    SDL_RenderCopy(target->renderer, target->texture, NULL, NULL);
    SDL_RenderPresent(target->renderer);
}