#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

    int max_sum = 0, max_sum_col = 0;

    // Чтение матрицы из входных данных и подсчет суммы элементов в каждом столбце
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        int col_sum = 0;
        for (int i = 0; i < n; i++) {
            col_sum += matrix[i][j];
        }
        if (col_sum > max_sum) {
            max_sum = col_sum;
            max_sum_col = j;
        }
    }

    std::cout << max_sum_col << std::endl;

    return 0;
}