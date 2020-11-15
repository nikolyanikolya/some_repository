#include <iostream>
#include <vector>
int n;
int l;
int r;
void bin_str(int count_minus, int count_plus, int l, int r,  std::vector<int> &my_vec){
    if(count_plus+count_minus==n) {
        if(count_plus-count_minus>=l && count_plus-count_minus <= r) {
            for (auto j : my_vec) {
                std::cout << j << " ";
            }
            std::cout << "\n";
            return;
        }
        return;
    }
        my_vec.push_back(1);
        bin_str(count_minus, count_plus+1, l, r, my_vec);
        my_vec.pop_back();
        my_vec.push_back(-1);
        bin_str(count_minus+1, count_plus, l, r,  my_vec);
        my_vec.pop_back();
}
int main() {
    std::cin>>n>>l>>r;
    std::vector<int> my_vec;
    bin_str(0, 0, l, r, my_vec);
    return 0;
}
