#include <iostream>

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) { return b ? gcd(b, a % b) : a; }
unsigned long long int lcm(unsigned long long int a, unsigned long long int b) { return a * b / gcd(a, b); }

unsigned long long int recurs_f(int n) {
    if (n == 1) return 1;
    else return lcm(n, recurs_f(n - 1));
}

int main() {
    int n;
    std::cin >> n;
    std::cout << recurs_f(n) << std::endl;

    return 0;
}