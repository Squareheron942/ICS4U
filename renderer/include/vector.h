#pragma once
#include <smmintrin.h>
#include <memory>

typedef float float4 __attribute__((vector_size(16)));

struct vector { 
    // __attribute__((aligned(16))) float f[4];
    float4 f;
    vector operator+(vector other) { return {this->f + other.f}; }
    vector operator-(vector other) { return {this->f - other.f}; }
    vector operator*(float factor) { return (vector){factor * f}; };
    float operator*(vector other) { return _mm_dp_ps(*(__m128*)(this), *(__m128*)(&other), 0xF1)[0]; }
    inline float operator[](int i) { return f[i]; }

    vector lerp(vector b, float factor) { return *this + (b - *this) * factor; }
    // vector(float4 f) : f(f) {}
    // vector(float x = 0, float y = 0, float z = 0, float w = 0) : f((float4){x, y, z, w}) {}
};

//_mm_set_ps(this->x, this->y, this->z, this->w)_mm_set_ps(other.x, other.y, other.z, other.w)