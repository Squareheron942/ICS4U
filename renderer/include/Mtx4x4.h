#pragma once
#include "vector.h"
typedef float4 __Mtx4x4[4];

struct Mtx4x4 {
    __Mtx4x4 el;

    float4 inline operator[](int i) { return el[i]; }
    inline float4 operator*(float4 b) { return (float4){*(vector*)&el[0] * *(vector*)&b, *(vector*)&el[1] * *(vector*)&b, *(vector*)&el[2] * *(vector*)&b, *(vector*)&el[3] * *(vector*)&b}; }
    inline vector operator*(vector b) { return (vector){{*(vector*)&el[0] * b, *(vector*)&el[1] * b, *(vector*)&el[2] * b, *(vector*)&el[3] * b}}; }
    inline Mtx4x4 operator*(Mtx4x4 b) { 
        return (Mtx4x4){{
            {*(vector*)&el[0] * (vector){b[0][0], b[1][0], b[2][0], b[3][0]}, *(vector*)&el[1] * (vector){b[0][0], b[1][0], b[2][0], b[3][0]}, *(vector*)&el[2] * (vector){b[0][0], b[1][0], b[2][0], b[3][0]}, *(vector*)&el[3] * (vector){b[0][0], b[1][0], b[2][0], b[3][0]}},
            {*(vector*)&el[0] * (vector){b[0][1], b[1][1], b[2][1], b[3][1]}, *(vector*)&el[1] * (vector){b[0][1], b[1][1], b[2][1], b[3][1]}, *(vector*)&el[2] * (vector){b[0][1], b[1][1], b[2][1], b[3][1]}, *(vector*)&el[3] * (vector){b[0][1], b[1][1], b[2][1], b[3][1]}},
            {*(vector*)&el[0] * (vector){b[0][2], b[1][2], b[2][2], b[3][2]}, *(vector*)&el[1] * (vector){b[0][2], b[1][2], b[2][2], b[3][2]}, *(vector*)&el[2] * (vector){b[0][2], b[1][2], b[2][2], b[3][2]}, *(vector*)&el[3] * (vector){b[0][2], b[1][2], b[2][2], b[3][2]}},
            {*(vector*)&el[0] * (vector){b[0][3], b[1][3], b[2][3], b[3][3]}, *(vector*)&el[1] * (vector){b[0][3], b[1][3], b[2][3], b[3][3]}, *(vector*)&el[2] * (vector){b[0][3], b[1][3], b[2][3], b[3][3]}, *(vector*)&el[3] * (vector){b[0][3], b[1][3], b[2][3], b[3][3]}},
        }}; 
    }
};