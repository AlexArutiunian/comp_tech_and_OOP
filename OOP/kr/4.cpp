#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    // создаем словарь, где ключ - имя поля, значение - пара из значения поля и времени его последнего изменения
    map<string, pair<string, int>> fields;

    for (int i = 0; i < n; i++) {
        int timestamp;
        string action, property, value;
        cin >> timestamp >> action >> property;
        if (action == "SET") {
            cin >> value;
            fields[property] = {value, timestamp};
        } else if (action == "DELETE") {
            fields.erase(property);
        }
    }

    int m;
    cin >> m;

    // для каждого запроса выводим состояние полей в указанный момент времени
    int last_timestamp = -1;
    for (int i = 0; i < m; i++) {
        int timestamp;
        cin >> timestamp;
        if (timestamp <= last_timestamp) {
            // если запрашиваем момент времени, который уже прошел, то выводим последнее известное состояние полей
            for (auto& [property, value] : fields) {
                cout << property << ": " << value.first << ", ";
            }
            cout << endl;
        } else {
            // иначе выводим состояние полей на указанный момент времени
            for (auto& [property, value] : fields) {
                if (value.second <= timestamp) {
                    cout << property << ": " << value.first << ", ";
                }
            }
            cout << endl;
            last_timestamp = timestamp;
        }
    }

    return 0;
}
