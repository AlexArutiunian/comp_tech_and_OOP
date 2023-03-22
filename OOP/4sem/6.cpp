#include <iostream>

#include <cstring> 

int main() {
    const int MAXLEN = 10000;
    char str[MAXLEN];
    std::cin.getline(str, MAXLEN);


int len = strlen(str);
bool in_word = false;
int word_start = 0;
for (int i = 0; i <= len; i++) {
    if (!in_word && !isspace(str[i])) { // начало нового слова
        in_word = true;
        word_start = i;
    } else if (in_word && (isspace(str[i]) || i == len)) { // конец текущего слова
        in_word = false;
        int word_len = i - word_start;
        if (word_len % 2 == 0) { // переворачиваем слово
            for (int j = 0; j < word_len / 2; j++) {
                std::swap(str[word_start + j], str[i - j - 1]);
            }
        }
    }
}

std::cout << str << std::endl;
return 0;

}