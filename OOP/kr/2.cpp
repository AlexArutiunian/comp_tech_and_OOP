#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    // создаем словарь, где ключ - имя датчика, значение - вектор его отсчетов
    map<string, vector<int>> data;

    for (int i = 0; i < n; i++) {
        string name;
        int value;
        cin >> name >> value;
        data[name].push_back(value);
    }

    // сортируем каждый вектор отсчетов и вычисляем медианные значения
    map<string, int> medians;
    for (auto& [name, values] : data) {
        sort(values.begin(), values.end());
        int size = values.size();
        if (size % 2 == 0) {
            medians[name] = (values[size/2 - 1] + values[size/2]) / 2;
        } else {
            medians[name] = values[size/2];
        }
    }

    int m;
    cin >> m;

    // выводим медианные значения для запрошенных датчиков
    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        if (data.count(name) == 0) {
            cout << "no data" << endl;
        } else {
            cout << medians[name] << endl;
        }
    }

    return 0;
}
