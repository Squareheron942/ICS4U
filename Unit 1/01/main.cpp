#include <iostream>
#include <time.h>
#include <type_traits>
#include <bit>
#include <concepts>
#include <chrono>

#define NUM_QUESTIONS 10
#define MAX_CHOICES 5
#define INDEX(el, arr) (&el - arr)
#define TO_INT(c) (c - 0x61)
#define TO_LETTER(c) (c + 0x61)
#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"

static const char* questions[NUM_QUESTIONS] = {
    "What is the entry method of a c++ file?",
    "Which is a correct declaration of a c-style string?",
    "How would you overload the right shift operator on a class \"T\"?",
    "Which of these is a function pointer that returns an int array, has a variadic template and can take in any number of arguments?",
    "Which of the following is not a keyword?",
    "What is a storage specifier in c++?",
    "Which has the highest operation priority?",
    "What is the most highest-precision type for decimal numbers?",
    "Which is faster?",
    "Should you write code in assembly instead of in c++?"
};

static const char* choices[NUM_QUESTIONS][MAX_CHOICES] = {
    {"int main()", "It depends on what you tell the compiler", "Whatever the first one is in the file"},
    {"char *str = NULL;", "str s = \"\";", "std::string s = \"\";"},
    {"T::operator>>(long other) {}", "T.>>(long other) {}"},
    {"int[] *function<T...>(T in...)", "template<class... T> int*(*f)(...)", "template<type T...> int[] function*(...)", "[int*](...) {}"},
    {"if", "noexcept", "co_await", "new", "not"},
    {"A number that tells the compiler how much space a variable uses", "A keyword telling the compiler how a variable should be defined, stored, and accessed"},
    {"Bitwise operations", "Ternary expressions", "Incrementations"},
    {"long", "double", "float"},
    {"++i", "i++"},
    {"Yes", "No"}
};

static const char correct[NUM_QUESTIONS] = {1, 0, 0, 1, 4, 1, 2, 1, 0, 0};
static char answers[NUM_QUESTIONS] = { 0 };
static std::string answer;

// bool getline(char* &line) { std::cin >> line;return true; }

bool askquestion(int index);
void doSomethingFun(void);

unsigned long long xorshf(unsigned long long x) {
    x ^= x >> 12; // a
    x ^= x << 25; // b
    x ^= x >> 27; // c
    return x;
}

static inline double to_double(uint64_t x) {
   const union { uint64_t i; double d; } u = {.i = UINT64_C(0x3FF) << 52 | x >> 12 };
   return u.d - 1.0;
}

namespace randnum {
    namespace {
        template<typename T>
        concept arithmetic = std::integral<T> or std::floating_point<T>;
        static unsigned long long state = 0x6ab93aeb19a953;
    }
    

    template<class T> requires arithmetic<T> T genrandom(long long seed = state) {
        unsigned long t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        // circular shift right 16 so that the smallest section (milliseconds) which changes most will make the largest changes
        // 0xAAAABBBBCCCCDDDD ==> 0xDDDDAAAABBBBCCCC
        unsigned long time = (t << 48) | (t >> 16);
        T out = 1;
        unsigned long val = xorshf(time  seed);
        if constexpr (std::integral<T>) out = (T)val;
        else out = (T)to_double(val);
        state = val;
        return out;
    };

    // can do ~6.6 million per second on my laptop
    template<class T> requires arithmetic<T> T genrandom(T max, T min = 0) {
        T out = 1;
        unsigned long val = genrandom<unsigned long>();
        if constexpr (std::integral<T>) out = (T)((val % (max - min)) + min);
        else out = (T)(fmodl(to_double(val), max - min) * (max - min) + min);
        return out;
    };
}

int main() {
    int numright(0);
    printf("\e[H\e[JWelcome to the test. There are %u questions. \n\n", NUM_QUESTIONS);
    // printf("%lu\n", genrandom<long>(5, 1));
    // unsigned long t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    // for (int i = 0; i < 100000000; ++i) if (!genrandom<unsigned long>()) printf("zero get\n");
    // unsigned long t2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    // printf("Took %f seconds\n", 0.001 * (t2 - t1));
    for (int i = 0; i < NUM_QUESTIONS; ++i) askquestion(i);
    printf("Mark breakdown:\n");
    for (auto &c : answers) {
        bool right = {TO_INT(c) == correct[INDEX(c, answers)]};
        printf("\nQuestion %lu: %s\nYour answer: %c\n%s%s%s\n", INDEX(c, answers), questions[INDEX(c, answers)], c, right ? GREEN : RED, right ? "Correct!" : "Incorrect!", RESET);
        if (right) ++numright; else printf("Correct answer: %c\n", TO_LETTER(correct[INDEX(c, answers)]));
    }
    printf("Score: %u/%u\n", numright, NUM_QUESTIONS);
    printf("You got %lu points!\n", randnum::genrandom<unsigned long>());
    if (numright == NUM_QUESTIONS) doSomethingFun(); else printf("If you did perfect maybe you could have done something more interesting...");
    return 0;
}

bool askquestion(int index) {
    char i = 0;
    printf("%u. %s\n\n", index + 1, questions[index]);
    do {printf("    %c. %s\n", TO_LETTER(i), choices[index][i]);} while (choices[index][++i] && i < MAX_CHOICES);
    printf("\n");
    do {printf("\e[1A\e[0K");getline(std::cin, answer);} while (answer.c_str()[0] < 0x61 || answer.c_str()[0] > 0x60 + i);
    answers[index] = answer.c_str()[0];
    return ((TO_INT(answer.c_str()[0])) == correct[index]);
}
void doSomethingFun(void) {
    char* items = NULL;
    std::string numItems, item;
    printf("Enter the number of items in a char array\n");
    getline(std::cin, numItems);
    items = new char[std::stoi(numItems)];
    printf("Enter the items in the array\n");
    for (int i = 0; i < std::stoi(numItems); ++i) { getline(std::cin, item);items[i] = item.c_str()[0]; };
    printf("Enter an offset\n\n");
    do {printf("\e[1A\e[0K");getline(std::cin, item);} while (std::stoi(item) >= std::stoi(numItems));
    printf("Output text: %s\n\nYou just did some pointer arithmetic!(and almost caused a segmentation fault)", items + std::stoi(item)); // add offset to pointer
    delete[] items;
}
