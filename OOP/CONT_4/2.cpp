#include <iostream>
#include <vector>

int main() {
    int q;
    std::cin >> q;

    // Создаем вектор для хранения очереди и битовую маску для отметки беспокоящихся людей
    std::vector<int> queue;
    std::vector<bool> worried;

    for (int i = 0; i < q; ++i) {
        std::string operation;
        std::cin >> operation;

        if (operation == "WORRY") {
            int index;
            std::cin >> index;

            worried[index] = true;
        } else if (operation == "QUIET") {
            int index;
            std::cin >> index;

            worried[index] = false;
        } else if (operation == "COME") {
            int k;
            std::cin >> k;

            if (k > 0) {
                for (int j = 0; j < k; ++j) {
                    queue.push_back(0);
                    worried.push_back(false);
                }
            } else {
                for (int j = 0; j < -k; ++j) {
                    queue.pop_back();
                    worried.pop_back();
                }
            }
        } else if (operation == "WORRY_COUNT") {
            int count = 0;
            for (int j = 0; j < worried.size(); ++j) {
                if (worried[j]) {
                    ++count;
                }
            }

            std::cout << count << std::endl;
        }
    }

    return 0;
}
