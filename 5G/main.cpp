#include <iostream>
#include <vector>
#include <queue>

int main() {
    int num_color;
    int num_section;
    std::cin>>num_section;
    std::cin>>num_color;
    int friends;
    std::priority_queue<int> q;
    std::cin>>friends;
    std:: vector<int> color(friends);
    std:: vector<int> begin(friends);
    std:: vector<int> end(friends);
    for (int i=0; i<friends; i++){
        std::cin>>color[i]>>begin[i]>>end[i];
    }

    return 0;
}
