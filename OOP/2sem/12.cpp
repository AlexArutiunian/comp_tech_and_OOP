#include <iostream>
#include <string>
#include <cctype>

unsigned long get_a_hexadecimal(std::string s) {
    unsigned long number = 0;
    for (char c : s) {
        
        if (isxdigit(c)) {
            number = number * 16 + std::stoi(std::string(1, c), nullptr, 16);
        }
        if (isupper(c) || !isdigit(c)) {
            return 0;
        }
    }


    return number;

}


int main() {
    std::cout << "Enter a hexadecimal number: ";
    std::string s;
    std::getline(std::cin, s);
    unsigned long number = get_a_hexadecimal(s);
    if (number == 0) {
        std::cout << "Invalid input: contains uppercase letters or non-hexadecimal characters" << std::endl;
    } else {
        std::cout << "You entered: " << std::hex << number << std::endl;
    }


    return 0;

}