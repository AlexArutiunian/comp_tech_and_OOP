#include <iostream>

void binary(unsigned int n);

int main() {
    unsigned int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
    std::cout << "Binary representation: ";
    binary(n);
    std::cout << std::endl;
    return 0;
}

void binary(unsigned int n) {
    if (n > 1) {
        binary(n / 2);
    }
    std::cout << n % 2;
}