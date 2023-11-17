#include <string>
#include <iostream>

std::string decimalToBinary(int n) {
    return (n > 1 ? decimalToBinary(n >> 1) + std::to_string(n % 2) : std::to_string(n % 2));
}

int main() {
    int n;
    std::cin >> n;
    std::cout << decimalToBinary(n);
    return 0;
}