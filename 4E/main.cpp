#include <iostream>
#include <vector>
#include <unordered_map>

int low(const long long &L,  const std::vector<std::pair<long long, long long>> &my_vec) {
    int l = -1;
    int r = my_vec.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (my_vec[m].first >= L)
            r = m;
        else
            l = m;
    }
    return r;
}

int up(const long long  &R, const std::vector<std::pair<long long, long long>> &my_vec) {
    int l = -1;
    int r = my_vec.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (my_vec[m].first > R)
            r = m;
        else
            l = m-1;
    }
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int num_city;
    std::cin>>num_city;
    long long l;
    long long r;
    long long x;
    std::vector<std::pair<long long,long long>> cities(num_city);
    int city;
    for (int i=0; i<num_city; i++){
       std::cin>>cities[i].first;
       cities[i].second=i+1;
    }

    long long query;
    std::cin>>query;
    std::vector<long long> results;
    std::vector<long long> necessary
    int k=1;
    for(int i=0; i<query; i++){
        std::cin>>l;
        std::cin>>r;
        std::cin>>x;


    }
    for(int i=0; i<query; i++)
        std::cout<<results[i];
  return 0;
}
//5 123 666 314 666 434 5 1 5 314 1 5 578 2 4 666 4 4 713 1 1 123