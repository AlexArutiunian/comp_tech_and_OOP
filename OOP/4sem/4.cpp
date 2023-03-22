#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char str[10000];
    int len = 0;
    cin.getline(str, 10000); // считываем строку с помощью функции getline()
    while (str[len] != '\0') { // перебираем символы до символа конца строки
        len++;
    }
    bool is_palindrome = true;
    for (int i = 0; i < len / 2; i++) { // проверяем, является ли строка палиндромом
        if (tolower(str[i]) != tolower(str[len - i - 1]) || isspace(str[i])) {
            is_palindrome = false;
            break;
        }
    }
    if (is_palindrome) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}