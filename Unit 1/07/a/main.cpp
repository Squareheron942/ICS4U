#include <iostream>

int power(int, int);

int main() {
    int a = 0, b = 0;
    std::cin >> a;
    std::cin >> b;
    std::cout << power(a, b) << std::endl;
    return 0;
}

int power(int a, int b) {
    return b == 0 ? 1 : b > 1 ? a * power(a, --b) : a;
}