#include <iostream>

char leveiling(char c){
    int ascii_c = static_cast<int>(c);
    ascii_c += 32;
    return static_cast<char>(ascii_c);
}

int main(){
    std::cout << leveiling('A') << std::endl;
}