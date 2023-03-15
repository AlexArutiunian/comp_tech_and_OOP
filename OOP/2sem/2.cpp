#include <iostream>

bool is_simple(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cout << "Введите целое число: ";
    std::cin >> n;
    std::cout << "Простые числа от 1 до " << n << ":\n";
    for (int i = 2; i <= n; i++) {
        if (is_simple(i)) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}