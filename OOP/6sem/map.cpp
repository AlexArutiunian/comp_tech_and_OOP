#include <iostream>
#include <map>
#include <string>

using string = std::string;

int main() {
    std::map<string, int> originalMap = {{"one", 1}, {"two", 2}, {"three", 3}};

    std::map<int, string> swappedMap;
    for (auto element : originalMap) {
        swappedMap[element.second] = element.first;
    }

    for (auto element : swappedMap) {
        std::cout << element.first << " " << element.second << std::endl;
    }

    return 0;
}