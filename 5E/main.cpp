#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int M;
    std::cin >> M;
    std::vector<std::pair<int, int>> my_vec;
    int p;
    int v;
    std::cin >> p;
    std::cin >> v;
    while (p != 0 || v != 0) {
        my_vec.emplace_back(p, v);
        std::cin >> p;
        std::cin >> v;
    }
    int r_max = 0;
    int num_of_subsegment = 0;
    std::sort(my_vec.begin(), my_vec.end());
    std::vector<std::pair<int, int>> results;
    int max_current = 0;
    int left_side = -50001;
    bool flag = true;
    int i = 0;
    while (r_max < M && flag) {
        flag = false;
        while (i < static_cast<int>(my_vec.size()) && my_vec[i].first <= r_max) {
            if (max_current < my_vec[i].second) {
                max_current = my_vec[i].second;
                left_side = my_vec[i].first;
                flag = true;
            }
            i++;
        }
        if (flag) {
            r_max = max_current;
            results.emplace_back(left_side, max_current);
            num_of_subsegment++;
        }
    }
    if (r_max < M)
        std::cout << "No solution";
    else {
        std::cout << num_of_subsegment << "\n";
        for (int j = 0; j < num_of_subsegment; j++) {
            std::cout << results[j].first << " ";
            std::cout << results[j].second << "\n";
        }
    }
    return 0;
}
