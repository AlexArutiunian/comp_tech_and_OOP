#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> image(n, std::vector<char>(m));

    // Read image from input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin.get(image[i][j]);
        }
        // Ignore new line character
        std::cin.ignore();
    }

    // Rotate image
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            std::cout << image[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}