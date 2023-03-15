#include <iostream>
#include <ctype.h>

char get_a_letter() {
    char c;
    std::cin >> c;
    while (!isalpha(c)) {
        std::cin >> c;
    }
    return toupper(c);
}

int main() {
    std::cout << "Enter a string: ";
    std::string s;
    std::getline(std::cin, s);

    for (int i = 0; i < 10 && i < s.length(); i++) {
        char c = toupper(s[i]);
        if (isalpha(c)) {
            std::cout << c;
        } else {
            i--;
        }
    }

    std::cout << std::endl;

    return 0;
}