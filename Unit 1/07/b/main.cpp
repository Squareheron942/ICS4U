#include <iostream>

int fibonacci(int);

int main() {
    int a = 0;
    std::cin >> a;
    std::cout << fibonacci(a) << std::endl;
    return 0;
}

int fibonacci(int n) {
    return n == 0 ? 0 : n == 1 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}