#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_pixels.h>

#include <stdint.h>

typedef struct {
    uint32_t* framebuffer;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
} RenderTarget;

int initRenderTarget(RenderTarget*);
int displayRenderTarget(RenderTarget*);

#endif // GRAPHICS_H