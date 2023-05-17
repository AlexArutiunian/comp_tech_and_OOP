#include <iostream>
#include <cstdlib>

class Storage {
protected:
    unsigned int size; // размер хранилища
    int* data; // указатель на массив данных

public:
    // Конструктор хранилища размерности n
    Storage(unsigned int n) : size(n), data(new int[n]) {}

    // Деструктор
    virtual ~Storage() {
        delete[] data;
    }

    // Получение размерности хранилища
    unsigned getSize() {
        return size;
    }

    // Получение значения i-го элемента из хранилища,
    // i находится в диапазоне от 0 до n-1,
    int getValue(unsigned int i) {
        return data[i];
    }

    // Задание значения i-го элемента из хранилища равным value,
    // i находится в диапазоне от 0 до n-1.
    void setValue(unsigned int i, int value) {
        data[i] = value;
    }
};

// Класс TestStorage, наследуется от вашей реализации Storage
class TestStorage : public Storage {
protected:
    // Унаследованная реализация зачем-то хочет выделить ещё памяти. Имеет право.
    int* more_data;

public:
    // В конструкторе память выделяется,
    TestStorage(unsigned int n) : Storage(n) {
        more_data = new int[n];
    }
    // ... а в деструкторе освобождается - всё честно.
    ~TestStorage() {
        delete[] more_data;
    }
};

int main() {
    Storage *ts = new TestStorage(42);
    delete ts;
    return 0;
}