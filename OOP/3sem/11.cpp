#include <iostream>
#include <vector>
#include <algorithm>

struct Box {
    int price;
    int candies;
};


bool compare_boxes(Box b1, Box b2) {
    return b1.price < b2.price;
}


int main() {
    int n;
    std::cin >> n;


std::vector<Box> boxes(n);

for (int i = 0; i < n; i++) {
    std::cin >> boxes[i].price >> boxes[i].candies;
}

int s;
std::cin >> s;

std::sort(boxes.begin(), boxes.end(), compare_boxes);

int total_boxes = 0;
int total_candies = 0;

for (int i = 0; i < n; i++) {
    if (s >= boxes[i].price) {
        int boxes_to_buy = std::min(s / boxes[i].price, boxes[i].candies);
        s -= boxes_to_buy * boxes[i].price;
        total_boxes += boxes_to_buy;
        total_candies += boxes_to_buy * boxes[i].candies;
    }
}

std::cout << total_boxes << " " << total_candies << std::endl;

return 0;

}