#include <string>
#include <iostream>
#include <algorithm>

/**
 * @brief Reverses a string by recursively moving the first letter in the string to the end until none is left
 * 
 * @param str The input string
 * @return The reversed string
 */
std::string reverse(std::string str) { return str.empty() ? "" : reverse(str.substr(1)) + str[0]; }

bool isPalindrome(std::string str) {
    std::cout << reverse(str) << std::endl;

    // remove all the formatting to ignore cases and whitespace

    // std::transform runs the callback function for each iterable element, so in this case converts the string fully to lowercase character by character
    std::transform(str.begin(), str.end(), str.begin(), [](char c){ return tolower(c); }); // make all characters lowercase
    
    // this erases each character from the string that is a space
    str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char x) { return std::isspace(x); }), str.end()); // remove from string if character is space, then resize string to fit

    // checks whether the reversed string is the same as the original
    return str == reverse(str);
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << (isPalindrome(str) ? "true" : "false");
    return 0;
}