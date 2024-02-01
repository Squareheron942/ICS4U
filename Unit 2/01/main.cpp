#include <iostream>

int seq1(int n, int num = 3) { return n ? seq1(--n, num) - 2 : num + 2; }
int seq2(int n, int num = -1) { return n - 1 ? seq2(--n, num << 1) : num; }

int main() {
    int n;
    std::cin >> n;
    std::cout << seq1(n) << std::endl;
    std::cout << seq2(n) << std::endl;
    return 0;
}