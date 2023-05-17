#include <iostream>
#include <vector>
#include <string>

int main() {
    int q;
    std::cin >> q;

    // Создаем вектор векторов для хранения списка дел каждого дня текущего месяца
    std::vector<std::vector<std::string>> tasks(31);
    int days_count = 31; // число дней в январе
    int current_day = 0;

    for (int i = 0; i < q; ++i) {
        std::string operation;
        std::cin >> operation;

        if (operation == "ADD") {
            int day;
            std::string task;
            std::cin >> day >> task;

            tasks[day - 1].push_back(task);
        } else if (operation == "DUMP") {
            int day;
            std::cin >> day;

            std::cout << tasks[day - 1].size();
            for (const auto& task : tasks[day - 1]) {
                std::cout << " " << task;
            }
            std::cout << std::endl;
        } else if (operation == "NEXT") {
            ++current_day;
            if (current_day > days_count) {
                // Переходим на следующий месяц

                // Вычисляем количество дней в следующем месяце
                int next_days_count = 28;
                if (days_count == 28 || days_count == 29) {
                    next_days_count = 31;
                } else if (days_count == 30) {
                    next_days_count = 31;
                }

                // Создаем новый список дел для следующего месяца
                std::vector<std::vector<std::string>> new_tasks(next_days_count);

                // Переносим дела из текущего списка на новый
                for (int j = 0; j < days_count; ++j) {
                    if (tasks[j].size() > 0) {
                        if (j < next_days_count) {
                            new_tasks[j] = tasks[j];
                        } else {
                            new_tasks[next_days_count - 1].insert(new_tasks[next_days_count - 1].end(), tasks[j].begin(), tasks[j].end());
                        }
                    }
                }

                // Обновляем текущий список задач и устанавливаем день в 1
                tasks = new_tasks;
                current_day = 1;
                days_count = next_days_count;
            }
        }
    }

    return 0;
}
