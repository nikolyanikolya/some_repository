#include <iostream>
#include <vector>

bool is_it_suits(int x, const std::vector<int> &stalls, int num_of_cows) {
    int cow = 1;
    int last_cow = stalls[0];
    for (int i = 0; i < stalls.size(); i++) {
        if (stalls[i] - last_cow >= x) {
            cow++;
            last_cow = stalls[i];
        }
    }
    return cow >= num_of_cows;
}

int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int num_of_stalls, num_of_cows;
    std::cin >> num_of_stalls;
    std::cin >> num_of_cows;
    std::vector<int> stalls(num_of_stalls);
    int left_side = 1;
    for (int i = 0; i < num_of_stalls; i++)
        std::cin >> stalls[i];
    int right_side = stalls[stalls.size() - 1];
    while (right_side-left_side>1) {
        int middle = (right_side + left_side) / 2;
        if (is_it_suits(middle, stalls, num_of_cows))
            left_side = middle;
        else
            right_side = middle;
    }
   std::cout << left_side;
    return 0;
}
