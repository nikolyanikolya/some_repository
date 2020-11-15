#include <iostream>
#include <vector>
#include <algorithm>
int low(const long long &L, const std::vector<long long> &my_vec) {
    int l = -1;
    int r = my_vec.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (my_vec[m] >= L)
            r = m;
        else
            l = m;
    }
    return r;
}
int up(const long long  &R, const std::vector<long long> &my_vec) {
    int l = -1;
    int r = my_vec.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (my_vec[m] > R)
            r = m;
        else
            l = m;
    }
    return r - 1;
}


int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    int m;
    std::cin>>n;
    std::cin>>m;
    std::vector<long long> kitten(n);
    for(int i=0; i<n; i++)
       std::cin>>kitten[i];
    std::sort(kitten.begin(), kitten.end());
    std::vector<long long> results(m);
    long long left;
    long long right;
    long long current_number;
    for(int i=0; i<m; i++)
    {
        std::cin>>left;
        std::cin>>right;
        current_number = up(right, kitten) - low(left, kitten)+1;
        results[i]=current_number;
    }
    for(int i=0; i<m; i++)
        std::cout<<results[i]<<" ";
    return 0;
}
