#include <iostream>

bool is_a_number(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    char c;
    int sum = 0;

    std::cout << "Enter a sequence of characters (end with $): ";
    std::cin.get(c);

    while (c != '$') {
        if (is_a_number(c)) {
            sum += c - '0';
        }
        std::cin.get(c);
    }

    std::cout << "Sum of digits: " << sum << std::endl;

    return 0;
}