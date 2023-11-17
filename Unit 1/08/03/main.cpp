#include <string>
#include <iostream>
#include <algorithm>

std::string reverse(std::string str) { return str.empty() ? "" : reverse(str.substr(1)) + str[0]; }

bool isPalindrome(std::string str) {
    std::cout << reverse(str) << std::endl;

    std::transform(str.begin(), str.end(), str.begin(), [](char c){ return tolower(c); }); // make all characters lowercase
    
    str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char x) { return std::isspace(x); }), str.end()); // remove from string if character is space, then resize string to fit

    return str == reverse(str);
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << (isPalindrome(str) ? "true" : "false");
    return 0;
}