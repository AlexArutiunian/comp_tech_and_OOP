#include <iostream>
using namespace std;

int main() {
    char str[10000];
    int len = 0;
    cin.getline(str, 10000); // считываем строку с помощью функции getline()
    while (str[len] != '\0') { // перебираем символы до символа конца строки
        len++;
    }
    for (int i = len - 1; i >= 0; i--) { // выводим символы в обратном порядке
        cout << str[i];
    }
    cout << endl;
    return 0;
}