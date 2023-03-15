#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cin >> m;

    // Sort array in descending order
    std::sort(arr.begin(), arr.end(), std::greater<int>());

    // Print m largest elements in ascending order
    for (int i = 0; i < m; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}