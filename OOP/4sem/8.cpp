#include <iostream>

#include <cstring>

using namespace std;


bool is_printable(const char* word) {
    const char targets[] = "nctu";
    int counts[] = {0, 0, 0, 0};
    for (int i = 0; i < strlen(word); i++) {
        char c = tolower(word[i]);
        for (int j = 0; j < 4; j++) {
            if (c == targets[j]) {
                counts[j]++;
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (counts[i] == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    const int MAXCHARS = 10000;
    char str[MAXCHARS];
    std::cin.getline(str, MAXCHARS);


const char* delim = " \n";
char* word = strtok(str, delim);
while (word != NULL) {
    if (!is_printable(word)) {
        // пропускаем это слово
    } else {
        std::cout << word << " ";
    }
    word = strtok(NULL, delim);
}
std::cout << endl;
return 0;

}