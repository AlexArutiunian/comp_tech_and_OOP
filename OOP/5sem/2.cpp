#include <iostream>

struct something {
 int a;
 bool b;
 char c;
};

struct something* calc_address(struct something* start, unsigned int number) {
    return start + number - 1;
    // -1 because indicating from 0
}

int main(){

}
/*

Для решения этой задачи мы можем использовать указатель на структуру и арифметику указателей. В функции мы сначала создаем указатель на структуру и инициализируем его значением start. Затем мы используем арифметику указателей, чтобы перейти к нужной структуре в массиве, используя значение number. Наконец, мы возвращаем адрес найденной структуры.
*/