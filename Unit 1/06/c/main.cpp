#include <iostream>
#include <algorithm>

int mod(int, int);

int main() {
    int dim = 0, t_sum = 0;
    std::cin >> dim;
    std::cin >> t_sum;
    if (dim <= 0 || t_sum <= 0) {return 0;}
    if (dim == 1) {printf("%d", t_sum);return 0;}
    int* square = new int[dim * dim];
    for (int i = 1; i < dim*dim; i++) square[i] = 0;
    int x = dim >> 1, y = 0;
    
    const int m_const = dim * (dim * dim + 1) >> 1;
    int offset = (t_sum - m_const) / dim;

    square[x] = 1 + offset;
    for (int i = 2; i <= dim * dim; i++) {
        if (square[mod(y - 1, dim) * dim + mod(x + 1, dim)] != 0) y++; 
        else {
            x++;
            y--;
        }
        x = mod(x, dim);
        y = mod(y, dim);
        square[y * dim + x] = i + offset;
        // std::cout << std::endl << x << " " << y << std::endl << std::endl;
        // for (int y = 0; y < dim; y++) {for (int x = 0; x < dim; x++) std::cout << square[y * dim + x] << " "; std::cout << std::endl; }
    }
    for (int y = 0; y < dim; y++) {for (int x = 0; x < dim; x++) std::cout << square[y * dim + x] << " "; std::cout << std::endl; }
}

inline __attribute__((always_inline)) int mod(int a, int b) {
    return (a%b + b)%b;
}