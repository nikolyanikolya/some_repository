
#include  <vector>
#include "optimization.h"
const int N = 999983;
int getIndex(const int &x, const std::vector<std::pair<int, int>> &my_vec) {
    int d=x%N;
    while(my_vec[d].first!=0 && my_vec[d].first!=x){
        if(d++==N)
            d=0;
    }
    return d;
}
bool exist(const int &x, const std::vector<std::pair<int, int>> &my_vec){
    bool flag=true;
    int d=x%N;
    while(my_vec[d].first!=x && flag){
        if(my_vec[d].first==0)
            flag=false;
        if (d++==N)
            d=0;
    }
    return flag;
}
int main() {
    int n=readInt();
    int a[n];
    int one;
    int two;
    int t;
    int c;
    int d;
    std::vector<std::pair<int, int>> my_vec(N);
    for (int i = 0; i < N; i++) {
        my_vec[i].first = 0;
        my_vec[i].second = 0;
    }
    for (int i = 0; i < n; i++) {
        one=readInt();
        two=readInt();
        c = getIndex(one, my_vec);
        d = getIndex(two, my_vec);
        if (!exist(one, my_vec)){
            my_vec[c].second=one;
        }
        if (!exist(two, my_vec)){
            my_vec[d].second=two;
        }
        my_vec[c].first=one;
        my_vec[d].first=two;
        a[i] = abs(my_vec[d].second-my_vec[c].second);
        t = my_vec[c].second;
        my_vec[c].second = my_vec[d].second;
        my_vec[d].second = t;
    }
    for (int i = 0; i < n; i++) {
        writeInt(a[i]);
        writeChar('\n');
    }
    return 0;
}
