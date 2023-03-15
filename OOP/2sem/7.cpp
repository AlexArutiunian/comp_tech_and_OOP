#include <iostream>


unsigned int sum_of_numbers(unsigned long long int n);



int fib(unsigned long long int n){
    int* F = new int[n];
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i != n; ++i){
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n - 1];
}
unsigned int sum_of_numbers(unsigned long long int n){
    unsigned int res = 0;
    while (n){
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    unsigned int n;
    std::cin >>n;
    std::cout << fib(n) << std::endl;
    std::cout <<sum_of_numbers(fib(n)) << std::endl;
    return 0;
}