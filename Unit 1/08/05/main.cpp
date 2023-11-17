#include <iostream>
#include <stdio.h>

#define FOR(iter, func) for (int i = 0; i < iter; i++) {func}

float r_avg(const int n, int* items, int idx = 0) {
    if (idx == n) return 0;
    return *items / (float)n + r_avg(n, ++items, ++idx);
}

int main() {
    int n;
    std::cin >> n;
    int* items = new int[n];

    FOR(n, std::cin >> items[i];)

    printf("%.1f", r_avg(3, items));
}