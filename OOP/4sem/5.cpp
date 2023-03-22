#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string str;
    std::getline(std::cin, str);
    int n;
    std::cin >> n;
    bool in_word = false;
    int word_start = -1;
    int word_end = -1;
    int word_count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (!in_word && !std::isspace(str[i])) { // начало нового слова
            in_word = true;
            word_start = i;
            word_count++;
            if (word_count == n) {
                word_end = i;
            }
        } else if (in_word && std::isspace(str[i])) { // конец текущего слова
            in_word = false;
            if (word_count == n) {
                std::cout << str.substr(word_start, word_end - word_start + 1) << std::endl;
                return 0;
            }
        } else if (in_word) { // продолжение текущего слова
            word_end = i;
        }
    }
    if (word_count == n) { // последнее слово в строке
        std::cout << str.substr(word_start, word_end - word_start + 1) << std::endl;
    } else { // не нашли нужное слово
        std::cout << "-" << std::endl;
    }
    return 0;
}