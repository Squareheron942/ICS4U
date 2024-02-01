#include <string>
#include <iostream>

std::string decimalToBinary(int n) {
    // adds a 0 or 1 to the output string based on the remainder of division
    return (n > 1 ? decimalToBinary(n >> 1) + std::to_string(n % 2) : std::to_string(n));
}

int main() {
    int n;
    std::cin >> n;
    std::cout << decimalToBinary(n);
    return 0;
}