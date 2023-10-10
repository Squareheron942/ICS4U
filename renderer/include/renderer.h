#pragma once

#include <SDL2/SDL.h>
#include "vector.h"

#define WIDTH  640
#define HEIGHT 480

class renderer {
    public:
    static SDL_Surface* render(SDL_Surface*);
};

float4 persp_bary(float4 a, float4 b, float4 c, float4 p, float4 invZ); // is good, no mistake

inline void set_pixel(SDL_Surface* surface, int x, int y, Uint32 pixel)
{
  Uint32 * const target_pixel = (Uint32 *) ((Uint8 *) surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel);
  *target_pixel = pixel;
}

inline Uint32 get_pixel(SDL_Surface* surface, int x, int y)
{
  return *(Uint16 *)((Uint8 *) surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel);
}

inline
float edgeFunction(const float4 &a, const float4 &b, const float4 &c)
{ return (c[0] - a[0]) * (b[1] - a[1]) - (c[1] - a[1]) * (b[0] - a[0]); }

inline void findLine(SDL_Surface* fbuf, int x1, int y1, int x2, int y2)
{
    long maxSize = 800;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = x1 < x2 ? 1 : -1; // works with negative directions
    int sy = y1 < y2 ? 1 : -1; 

    int err = dx - dy;
    int e2;
    int i = 0;
    while (true && ++i) 
    {
        if (x1 >= 0 && x1 < WIDTH && y1 >= 0 && y1 < HEIGHT) set_pixel(fbuf, x1, y1, 0xFFFFFFFF);

        if (abs(x2 - x1) < 2 && abs(y2 - y1) < 2 || i > maxSize) break; // if positions are the same stop

        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}