#include <iostream>

unsigned long long int factorial(unsigned int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}


int sum_of_digits(unsigned long long int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    unsigned int n;
    std::cout << "Enter a number: ";
    std::cin >> n;


    unsigned long long int fact = factorial(n);
    int sum = sum_of_digits(fact);

    std::cout << "Factorial of " << n << " is " << fact << std::endl;
    std::cout << "Sum of digits in factorial of " << n << " is " << sum << std::endl;

    return 0;

}