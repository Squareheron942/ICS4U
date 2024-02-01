#include <iostream>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; } // follows formula for gcd

int main() {
    int a, b;
    std::cin >> a;
    std::cin >> b;
    std::cout << gcd(a, b);
    return 0;
}