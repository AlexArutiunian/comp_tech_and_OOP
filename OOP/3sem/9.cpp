#include <iostream>
#include <vector>

struct Protoss {
    unsigned long long int id;
    unsigned int health, shield, position[2];
    char name[100];
};


unsigned int count_wounded(Protoss* army, unsigned int n, unsigned int threshold) {
    unsigned int count = 0;
    for (unsigned int i = 0; i < n; i++) {
        if (army[i].health < threshold) {
            count++;
        }
    }
    return count;
}


int main() {
    unsigned int n, threshold;
    std::cin >> n >> threshold;


    Protoss* army = new Protoss[n];

    for (unsigned int i = 0; i < n; i++) {
        std::cin >> army[i].id >> army[i].health >> army[i].shield >> army[i].position[0] >> army[i].position[1] >> army[i].name;
    }

    unsigned int wounded_count = count_wounded(army, n, threshold);

    std::cout << "Number of wounded Protosses: " << wounded_count << std::endl;

    delete[] army;

    return 0;

}