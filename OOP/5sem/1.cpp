#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int BITS_IN_BYTE = 8;
    const int BITS_IN_MEGABYTE = 1024 * 1024 * BITS_IN_BYTE;
    int mb;
    cin >> mb;
    int bits = mb * BITS_IN_MEGABYTE;

    int bytes = ceil((double)bits / BITS_IN_BYTE);
    cout << bytes << endl;
    return 0;
}
/*
В этой программе мы сначала считываем количество мегабайт из входных данных. Затем мы вычисляем количество бит, которые нужно для адресации памяти мощностью mb мегабайт. Далее мы вычисляем количество байт, которые нужны для хранения этого количества бит, с помощью функции ceil. Наконец, мы выводим этот результат.
*/