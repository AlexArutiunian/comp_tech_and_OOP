#include <iostream>

class VectorN {
public:
    // Конструктор вектора размерности n
    VectorN(unsigned int n) : size_(n) {
        data_ = new int[n];
    }

    // Деструктор
    ~VectorN() {
        delete[] data_;
    }

    // Получение размерности вектора
    unsigned int getSize() const {
        return size_;
    }

    // Получение значения i-ой координаты вектора,
    // i находится в диапазоне от 0 до n-1
    int getValue(unsigned int i) const {
        return data_[i];
    }

    // Задание значения i-ой координаты вектора равным value,
    // i находится в диапазоне от 0 до n-1
    void setValue(unsigned int i, int value) {
        data_[i] = value;
    }

    // Перегрузка оператора ==
    bool operator==(const VectorN& other) const {
        if (size_ != other.size_) {
            return false;
        }
        for (unsigned int i = 0; i < size_; ++i) {
            if (data_[i] != other.data_[i]) {
                return false;
            }
        }
        return true;
    }

    // Перегрузка оператора !=
    bool operator!=(const VectorN& other) const {
        return !(*this == other);
    }

    // Перегрузка оператора +
    VectorN operator+(const VectorN& other) const {
        VectorN result(size_);
        for (unsigned int i = 0; i < size_; ++i) {
            result.data_[i] = data_[i] + other.data_[i];
        }
        return result;
    }

    // Перегрузка оператора * (умножение вектора на скаляр)
    friend VectorN operator*(int scalar, const VectorN& vector) {
        VectorN result(vector.size_);
        for (unsigned int i = 0; i < vector.size_; ++i) {
            result.data_[i] = scalar * vector.data_[i];
        }
        return result;
    }

    // Перегрузка оператора * (умножение скаляра на вектор)
    VectorN operator*(int scalar) const {
        return scalar * (*this);
    }

private:
    int* data_;
    unsigned int size_;
};

int main() {
    VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);

    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);

    std::cout << (a == b) << std::endl; // false
    std::cout << (a != b) << std::endl; // true

    VectorN c = a + b;
    VectorN d = 5 * c;

    for (unsigned int i = 0; i < a.getSize(); ++i) {
        std::cout << d.getValue(i) << std::endl;
    }

    return 0;
}

