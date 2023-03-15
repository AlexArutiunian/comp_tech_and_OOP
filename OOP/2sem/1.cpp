#include <iostream>

int reverse_integer(int x) {
    return -x;
}

int main() {
    int x;
    std::cout << "Введите целое число: ";
    std::cin >> x;
    std::cout << "Обратное значение: " << reverse_integer(x) << std::endl;
    return 0;
}