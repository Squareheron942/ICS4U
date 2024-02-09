#include "fraction.h"
#include <iostream>
#include <string>

int main() {
    fraction f1(3, 2);
    fraction f2(4, 18);

    std::cout << (std::string)f1 << std::endl;
    std::cout << (std::string)f2 << std::endl;

    f1 *= f2;

    fraction f3 = f1 / f2;

    fraction f4 = f3 * (fraction)2;

    fraction f5 = f4 + f2;

    fraction f6 = f4 - f1;

    std::cout << (std::string)f1 << std::endl;
    std::cout << (std::string)f2 << std::endl;
    std::cout << (std::string)f3 << std::endl;
    std::cout << (std::string)f4 << std::endl;
    std::cout << (std::string)f5 << std::endl;
    std::cout << (std::string)f6 << std::endl;
}