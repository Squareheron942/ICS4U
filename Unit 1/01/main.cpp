#include <iostream>

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

int main() {
    int numright(0);
    printf("\e[H\e[JWelcome to the test. There are %u questions. \n\n", NUM_QUESTIONS);
    for (int i = 0; i < NUM_QUESTIONS; ++i) askquestion(i);
    printf("Mark breakdown:\n");
    for (auto &c : answers) {
        bool right = {TO_INT(c) == correct[INDEX(c, answers)]};
        printf("\nQuestion %lu: %s\nYour answer: %c\n%s%s%s\n", INDEX(c, answers), questions[INDEX(c, answers)], c, right ? GREEN : RED, right ? "Correct!" : "Incorrect!", RESET);
        if (right) ++numright; else printf("Correct answer: %c\n", TO_LETTER(correct[INDEX(c, answers)]));
    }
    printf("Score: %u/%u\n", numright, NUM_QUESTIONS);
    
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
    for (int i = 0; i < std::stoi(numItems); ++i) {
        getline(std::cin, item);
        items[i] = item.c_str()[0];
    };
    printf("Enter an offset\n\n");
    do {printf("\e[1A\e[0K");getline(std::cin, item);} while (std::stoi(item) >= std::stoi(numItems));
    printf("Output text: %s\n\nYou just did some pointer arithmetic!(and almost caused a segmentation fault)", items + std::stoi(item)); // add offset to pointer
    delete[] items;
}