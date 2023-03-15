#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    int n, m;
    std::cin >> n;


    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cin >> m;

    std::set<int> max_nums;

    for (int i = 0; i < n; i++) {
        max_nums.insert(arr[i]);
        if (max_nums.size() > m) {
            max_nums.erase(max_nums.begin());
        }
    }

    for (int i = 0; i < n; i++) {
        if (max_nums.count(arr[i]) > 0) {
            std::cout << arr[i] << " ";
            max_nums.erase(arr[i]);
        }
    }

    return 0;

}