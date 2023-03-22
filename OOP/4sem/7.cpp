#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LENGTH = 10000;

// Функция для разбиения строки на слова
int split_string(char str[], char words[][MAX_LENGTH])
{
    int n = 0; // количество слов
    int word_start = -1; // начало текущего слова
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) { // начало нового слова
            if (word_start == -1) {
                word_start = i;
            }
        } else if (word_start != -1) { // конец текущего слова
            int word_len = i - word_start;
            strncpy(words[n], str + word_start, word_len); // копируем слово в массив
            words[n][word_len] = '\0'; // добавляем завершающий нулевой символ
            n++;
            word_start = -1;
        }
    }
    if (word_start != -1) { // последнее слово в строке
        int word_len = len - word_start;
        strncpy(words[n], str + word_start, word_len);
        words[n][word_len] = '\0';
        n++;
    }
    return n;
}

int main()
{
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    char words1[MAX_LENGTH / 2][MAX_LENGTH], words2[MAX_LENGTH / 2][MAX_LENGTH];
    int n1, n2;

    cin.getline(str1, MAX_LENGTH);
    cin.getline(str2, MAX_LENGTH);

    n1 = split_string(str1, words1);
    n2 = split_string(str2, words2);

    bool found = false;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (strcmp(words1[i], words2[j]) == 0) { // найдено совпадающее слово
                cout << words1[i] << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "-" << endl;
    }
    return 0;
}