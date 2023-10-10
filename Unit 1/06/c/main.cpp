#include <iostream>
#include <algorithm>

int mod(int, int);

int main() {
    int dim = 0, t_sum = 0;
    std::cin >> dim;
    std::cin >> t_sum;
    int* square = new int[dim * dim];
    for (int i = 0; i < dim * dim; i++) square[i] = 0;
    int x = dim >> 1, y = 0;
    square[x] = 1;
    for (int i = 2; i <= dim * dim; i++) {
        if (square[mod(y - 1, dim) * dim + mod(x + 1, dim)] != 0) y++; 
        else {
            x++;
            y--;
        }
        x = mod(x, dim);
        y = mod(y, dim);
        square[y * dim + x] = i;
        std::cout << std::endl << x << " " << y << std::endl << std::endl;
        for (int y = 0; y < dim; y++) {for (int x = 0; x < dim; x++) std::cout << square[y * dim + x] << " "; std::cout << std::endl; }
    }
    for (int y = 0; y < dim; y++) {for (int x = 0; x < dim; x++) std::cout << square[y * dim + x] << " "; std::cout << std::endl; }
}

int mod(int a, int b) {
    return (a%b + b)%b;
}