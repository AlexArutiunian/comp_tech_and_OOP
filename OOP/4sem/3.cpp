#include <iostream>
using namespace std;

int main() {
    char str[10000];
    int len = 0;
    cin.getline(str, 10000); // считываем строку с помощью функции getline()
    while (str[len] != ' ' && str[len] != '\0') { // перебираем символы до первого пробела или символа конца строки
        len++;
    }
    bool is_palindrome = true;
    for (int i = 0; i < len / 2; i++) { // проверяем, является ли первое слово палиндромом
        if (str[i] != str[len - i - 1]) {
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

