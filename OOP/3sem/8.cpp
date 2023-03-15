#include <iostream>

struct Vector {
    int x, y, z;
};

// Function to add two vectors
Vector sum(Vector a, Vector b) {
    Vector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

int main() {
    int n;
    std::cout << "Enter number of vectors: ";
    std::cin >> n;

    Vector result = {0, 0, 0}; // Initialize result vector to (0, 0, 0)

    for (int i = 0; i < n; i++) {
        Vector v;
        std::cout << "Enter vector " << i + 1 << " (x, y, z): ";
        std::cin >> v.x >> v.y >> v.z;
        result = sum(result, v);
    }

    std::cout << "Resultant vector: (" << result.x << ", " << result.y << ", " << result.z << ")" << std::endl;

    return 0;
}