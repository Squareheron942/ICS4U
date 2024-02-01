#include <iostream>
#include <stdio.h>

#define FOR(iter, func) for (int i = 0; i < iter; i++) {func}

float r_avg(const int n, int* items, int idx = 0) {
    if (idx == n) return 0;
    // adds item / number of items to the average
    return *items / (float)n + r_avg(n, ++items, ++idx);
}

int main() {
    int n;
    std::cin >> n;
    int* items = new int[n];

    // shorthand for loop with a macro
    FOR(n, std::cin >> items[i];)

    // prints the average rounded to 1 decimal
    printf("%.1f", r_avg(n, items));
}