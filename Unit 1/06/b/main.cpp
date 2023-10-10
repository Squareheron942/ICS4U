#include <iostream>
#include <math.h>

char* format(int);

int main() {
    int *fbuf;
    int x, y;
    std::cin >> x;
    std::cin >> y;

    double r_delta = sqrt(y - x);

    int WIDTH = fmax(1, floor(r_delta)), HEIGHT = fmax(1, ceil(r_delta));

    fbuf = new int[WIDTH * HEIGHT];

    for (int i = x, sw_flag = 0, length = 0, v_x = (WIDTH - 1) >> 1, v_y = (HEIGHT - 1) >> 1; i <= y;) {
        for (int j = 0; j <= length && i <= y; j++, i++) {
            fbuf[v_y * WIDTH + v_x] = (i == 0 ? 100 : i); // replace 0 with 100 to replace it back when formatting
            (sw_flag & 1) ? (sw_flag & 2) ? v_x-- : v_x++ : (sw_flag & 2) ? v_y-- : v_y++;
        }
        sw_flag++;
        length += ~sw_flag & 1;
    }
    for (int l = 0; l < HEIGHT; l++) {for (int m = 0; m < WIDTH - 1; m++) std::cout << format(fbuf[l * WIDTH + m]) << " ";std::cout << format(fbuf[(l + 1) * WIDTH - 1]) << std::endl;} 

    delete[] fbuf;

    return 0;
}
char n_t[3] = {0};
char* format(int n) {
    n_t[0] = 0;
    n_t[1] = 0;
    n_t[2] = 0;
    sprintf(n_t, "%*u", 2, n == 100 ? 0 : n);
    if (n==0 || n > 100) sprintf(n_t, "  ");
    return n_t;
}