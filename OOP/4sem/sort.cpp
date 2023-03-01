#include <iostream>
#include <vector>

struct something {
    int a;
    bool b;
    char c;
};

struct something* calc_address(struct something* start, unsigned int number){
    return &start[number];
}

int main(){
    something Test[10];
    std::cout << &Test[5] << std::endl;
    std::cout << calc_address(Test, 5);
    
}