#include "renderer.h"
#include <SDL2/SDL.h>
#include "color.h"
#include "stdio.h"
#include "cube.h"
#include "test_tri.h"
#include "vector.h"
#include "Mtx4x4.h"
#include <chrono>
#include "math.h"

#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
#define COLOR(R, G, B) (0xFF000000 | ((unsigned char)(B * 255)) << 16 | ((unsigned char)(G * 255)) << 8 | (unsigned char)(R * 255)) // abgr for some reason?

#define PERS_BARY false

void findLine(SDL_Surface*, int, int, int, int);
float4 bary(float4, float4, float4, float4);

float x = 0, y = 0, angle = 0, counter = 0;

float ms, oldms;

bool print = true;

SDL_Surface* img = SDL_LoadBMP("texture.bmp");



SDL_Surface* renderer::render(SDL_Surface* fbuf) {

    int *arr;

    arr = new int[3];

    if (!img) printf("Failed to load image: %s\n", SDL_GetError());
    float zbuf[WIDTH * HEIGHT] = {0};
    SDL_Event e;
    // for (int y = 0; y < 256; y++) {for (int x = 0; x < 256; x++) printf("%u ", get_pixel(img, 0, 0));printf("\n");}
    // printf("\n");

    // oldms = ms;
    // ms = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count() / 1000.0f;

    // printf("frametime: %f\n", ms - oldms);
    angle += 0.01;
    // counter += 0.01;
    // x += 0.1;
    // y += 0.1;
    Mtx4x4 Rx = {{
        {1,           0,            0, 0},
        {0, cosf(angle), -sinf(angle), 0},
        {0, sinf(angle),  cosf(angle), 0},
        {0,           0,            0, 1}
    }};

    Mtx4x4 Ry = {{
        { cosf(angle), 0, sinf(angle), 0},
        {           0, 1,           0, 0},
        {-sinf(angle), 0, cosf(angle), 0},
        {           0, 0,           0, 1}
    }};

    Mtx4x4 Rz = {{
        {cosf(angle), -sinf(angle), 0, 0},
        {sinf(angle), cosf(angle), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    }};

    const float fov = 1.7320508075f;
    const int far = 1000;
    const int near = 0;

    float nearVal = 1 / (far - near);

    // Mtx4x4 proj = {{
    //     {fov,  0,   0, 0},
    //     { 0, fov,   0, 0},
    //     { 0,   0,  -1, 0},
    //     { 0,   0,   0, 0}
    // }};
    Mtx4x4 proj = {{
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    }};

    float px = 0, py = 0, pz = -300,
    sx = 1.5 + sinf(2 * counter), sy = 1, sz = 1;

    Mtx4x4 translation = {{
        {1, 0, 0, px},
        {0, 1, 0, py},
        {0, 0, 1, pz},
        {0, 0, 0,  1}
    }};

    Mtx4x4 scale = {{
        {sx,  0,  0, 0},
        { 0, sy,  0, 0},
        { 0,  0, sz, 0},
        { 0,  0,  0, 1}
    }};

    Mtx4x4 modelview = proj * translation * Rz * Rx * Ry;
    // Mtx4x4 modelview = {{
    //     {1, 0, 0, 0},
    //     {0, 1, 0, 0},
    //     {0, 0, 1, 0},
    //     {0, 0, 0, 1}
    // }};

    for (int i = 0; i < 12; i++) {

        float4 v0 = modelview * cube[i * 3 + 0].position.f;
        float4 v1 = modelview * cube[i * 3 + 1].position.f;
        float4 v2 = modelview * cube[i * 3 + 2].position.f;

        float4 u0 = cube[i * 3 + 0].texcoord0.f;
        float4 u1 = cube[i * 3 + 1].texcoord0.f;
        float4 u2 = cube[i * 3 + 2].texcoord0.f;

        if (v0[2] > 0 || v1[2] > 0 || v2[2] > 0) continue;
        
        float4 inv_z = 1.0f / (float4){v0[2], v1[2], v2[2]};

        v0 *= inv_z[0] * 100;
        v1 *= inv_z[1] * 100;
        v2 *= inv_z[2] * 100;

        const int x1 = (int)(16 * (v0[0] + WIDTH / 2));
        const int x2 = (int)(16 * (v1[0] + WIDTH / 2));
        const int x3 = (int)(16 * (v2[0] + WIDTH / 2));

        const int y1 = (int)(16 * (v0[1] + HEIGHT / 2));
        const int y2 = (int)(16 * (v1[1] + HEIGHT / 2));
        const int y3 = (int)(16 * (v2[1] + HEIGHT / 2));

        const int minX = max(0, min(x1 >> 4, min(x2 >> 4, x3 >> 4)));
        const int maxX = min(WIDTH, max(x1 >> 4, max(x2 >> 4, x3 >> 4)));
        const int minY = max(0, min(y1 >> 4, min(y2 >> 4, y3 >> 4)));
        const int maxY = min(HEIGHT, max(y1 >> 4, max(y2 >> 4, y3 >> 4)));

        const int Dx12 = x1 - x2;
        const int Dx23 = x2 - x3;
        const int Dx31 = x3 - x1;

        const int Dy12 = y1 - y2;
        const int Dy23 = y2 - y3;
        const int Dy31 = y3 - y1;

        const int FDx12 = Dx12 << 4;
        const int FDx23 = Dx23 << 4;
        const int FDx31 = Dx31 << 4;

        const int FDy12 = Dy12 << 4;
        const int FDy23 = Dy23 << 4;
        const int FDy31 = Dy31 << 4;

        int C1 = Dy12 * x1 - Dx12 * y1;
        int C2 = Dy23 * x2 - Dx23 * y2;
        int C3 = Dy31 * x3 - Dx31 * y3;

        if(Dy12 < 0 || (Dy12 == 0 && Dx12 > 0)) C1++;
        if(Dy23 < 0 || (Dy23 == 0 && Dx23 > 0)) C2++;
        if(Dy31 < 0 || (Dy31 == 0 && Dx31 > 0)) C3++;

        int Cy1 = C1 + Dx12 * (minY << 4) - Dy12 * (minX << 4);
        int Cy2 = C2 + Dx23 * (minY << 4) - Dy23 * (minX << 4);
        int Cy3 = C3 + Dx31 * (minY << 4) - Dy31 * (minX << 4);

        for (int y = minY; y <= maxY; y++) {
            int Cx1 = Cy1;
            int Cx2 = Cy2;
            int Cx3 = Cy3;
            for (int x = minX; x <= maxX; x++) {
                bool frontFace = Cx1 < 0 && Cx2 < 0 && Cx3 < 0;
                bool backFace = Cx1 > 0 && Cx2 > 0 && Cx3 > 0;

                if (frontFace) {
                    #if PERSP_BARY
                    float4 b = persp_bary(v0, v1, v2, (float4){(float)x - WIDTH / 2, (float)y - HEIGHT / 2}, inv_z);
                    #else
                    float4 b = bary(v0, v1, v2, (float4){(float)x - WIDTH / 2, (float)y - HEIGHT / 2});
                    #endif
                    float zVal = 1 - ((near - (b[0] * inv_z[0] + b[1] * inv_z[1] + b[2] * inv_z[2])) * nearVal);

                    if (zVal < 0 || zVal > 1) continue;
                    if (zbuf[y * WIDTH + x] > zVal) continue;

                    float4 uv{b[0] * u0[0] + b[1] * u1[0] + b[2] * u2[0], b[0] * u0[1] + b[1] * u1[1] + b[2] * u2[1]};
                    // int c = uv[0] * uv[1] * 255;
                    // if (uv[0] != 0) printf("uv not zero");
                    // COLOR((unsigned char)(uv[0] * 255), (unsigned char)(uv[1] * 255), 0)
                    set_pixel(fbuf, x, y, get_pixel(img, uv[0] * 255, uv[1] * 255));
                    // set_pixel(fbuf, x, y, 0xFF000000 | (unsigned char)(b[0] * 255) << 16 | (unsigned char)(b[1] * 255) << 8 | (unsigned char)(b[2] * 255));
                }
                Cx1 -= FDy12;
                Cx2 -= FDy23;
                Cx3 -= FDy31;
            }
            Cy1 += FDx12;
            Cy2 += FDx23;
            Cy3 += FDx31;
        }
        
        findLine(fbuf, x1 >> 4, y1 >> 4, x2 >> 4, y2 >> 4);
        findLine(fbuf, x2 >> 4, y2 >> 4, x3 >> 4, y3 >> 4);
        findLine(fbuf, x3 >> 4, y3 >> 4, x1 >> 4, y1 >> 4);
    }
    return fbuf;
}

// works fine, no mistake
float4 persp_bary(float4 a, float4 b, float4 c, float4 p, float4 invZ) {
    if (print) printf("%f \n", invZ[0]);

    float v0x = b[0] - a[0], v0y = b[1] - a[1], v1x = c[0] - a[0], v1y = c[1] - a[1], v2x = p[0] - a[0], v2y = p[1] - a[1];

    float den = 1 / (v0x * v1y - v1x * v0y);

    float v = (v2x * v1y - v1x * v2y) * den;
    float w = (v0x * v2y - v2x * v0y) * den;
    float u = 1.0f - v - w;

    float _u = u * invZ[0], _v = v * invZ[1], _w = w * invZ[2];

    if (print) {
        printf("\
            xy %d %d \n\
            pos %.0f %.0f %.0f  %.0f %.0f %.0f  %.0f %.0f %.0f \n\
            bary %f %f %f\n\
            \n", 
            (int)p[0], (int)p[1], 
            a[0], a[1], 1 / invZ[0], 
            b[0], b[1], 1 / invZ[1], 
            c[0], c[1], 1 / invZ[2], 
            _u / (_u + _v + _w), _v / (_u + _v + _w), _w / (_u + _v + _w)
        );
        print = false;
    }
    
    return (float4){_u, _v, _w} / (_u + _v + _w);
}

float4 bary(float4 a, float4 b, float4 c, float4 p) {
    // Vector2 v0 = new Vector2(b.x - a.x, b.y - a.y), v1 = new Vector2(c.x - a.x, c.y - a.y), v2 = new Vector2(p.x - a.x, p.y - a.y);
    float v0x = b[0] - a[0], v0y = b[1] - a[1], v1x = c[0] - a[0], v1y = c[1] - a[1], v2x = p[0] - a[0], v2y = p[1] - a[1];
    float den = 1 / (v0x * v1y - v1x * v0y);

    float v = (v2x * v1y - v1x * v2y) * den;
    float w = (v0x * v2y - v2x * v0y) * den;
    float u = 1.0f - v - w;

    return (float4){u, v, w};
}