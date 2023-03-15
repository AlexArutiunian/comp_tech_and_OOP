#include <iostream>
#include <string>
#include <cctype>

unsigned long get_really_any_hexadecimal() {
    std::string s;
    std::getline(std::cin, s);

    unsigned long number = 0;
    for (char c : s) {
        if (isspace(c)) {
            break;
        }
        if (isxdigit(c)) {
            number = number * 16 + std::stoi(std::string(1, toupper(c)), nullptr, 16);
        }
    }

    return number;
}

int main() {
    std::cout << "Enter a hexadecimal number: ";
    unsigned long number = get_really_any_hexadecimal();
    std::cout << "You entered: " << number << std::endl;

    return 0;
}