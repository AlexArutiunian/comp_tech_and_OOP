#include <iostream>

unsigned int sum_of_numbers(unsigned int n);

int main() {
    unsigned int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Sum of digits: " << sum_of_numbers(n) << std::endl;
    return 0;
}

unsigned int sum_of_numbers(unsigned int n) {
    unsigned int sum = 0;
    while (n > 0) {
        sum += n % 10;  // находим остаток от деления на 10
        n /= 10;        // отбрасываем младшую цифру
    }
    return sum;
}