#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    // Создаем массив для хранения значений температуры
    std::vector<int> temperatures(n);
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> temperatures[i];
        sum += temperatures[i];
    }

    // Вычисляем среднее арифметическое
    int average = sum / n;
    
    // Ищем номера дней, где температура выше среднего
    std::vector<int> above_average;
    for (int i = 0; i < n; ++i) {
        if (temperatures[i] > average) {
            above_average.push_back(i);
        }
    }

    // Выводим результаты
    std::cout << above_average.size() << std::endl;
    for (int i = 0; i < above_average.size(); ++i) {
        std::cout << above_average[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
