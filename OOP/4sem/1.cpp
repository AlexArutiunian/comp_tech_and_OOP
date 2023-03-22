#include <iostream>
using namespace std;

int main() {
    char str[1000];
    int len = 0;
    cin.getline(str, 1000); // считываем строку с помощью функции getline()
    while (str[len] != '\0') { // перебираем символы до символа конца строки
        len++;
    }
    cout << len << endl; // выводим длину строки
    return 0;
}