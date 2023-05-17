#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> words; // множество для хранения уникальных слов

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.insert(word);
    }

    // переносим элементы множества в вектор и сортируем его по убыванию длины
    vector<string> sorted_words(words.begin(), words.end());
    sort(sorted_words.begin(), sorted_words.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
    });

    // выводим отсортированные слова
    for (const string& word : sorted_words) {
        cout << word << endl;
    }

    return 0;
}
