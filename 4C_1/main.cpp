
#include <iostream>
#include <vector>
#include <algorithm>
#include "optimization.h"
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
    //std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::vector<long long> my_vec;
    long long  N = readInt();
    my_vec.resize(N);
    long long  element;
    for (int i = 0; i < N; i++) {
        element = readInt<long long>();
        my_vec[i] = element;
    }
    std::sort(my_vec.begin(), my_vec.end());
    int k = readInt();
    long long L;
    long long R;
    for (int i = 0; i < k; i++) {
        L = readInt();
        R = readInt();
        //std::cout<<up(R, my_vec)<<" ";
        //std::cout<<low(L, my_vec)<< " ";
        writeInt<long long>(up(R, my_vec) - low(L, my_vec) + 1 );
        writeChar(' ');
    }

    return 0;
}

