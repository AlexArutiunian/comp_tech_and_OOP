#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    double avg = static_cast<double>(sum) / n;

    for (int i = 0; i < n; i++) {
        if (arr[i] > avg) {
            std::cout << arr[i] << " ";
        }
    }

    return 0;
}