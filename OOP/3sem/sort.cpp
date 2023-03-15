#include <iostream>
#include <vector>
int main(){
    int n = 0;
    std::cin >> n;
    std::vector<int> data(n);
    for(int i = 0; i != n; ++i){
        int temp;
        std::cin >> temp;
        data.push_back(temp); 
    }
    
}