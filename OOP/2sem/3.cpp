#include <iostream>

int sum(int a, int b);

int main() {
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;
    std::cout << "Sum = " << sum(a, b) << std::endl;
    return 0;
}

int sum(int a, int b) {
    return a + b;
}