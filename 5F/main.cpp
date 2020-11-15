#include <iostream>
#include <vector>
#include <algorithm>
int low(int L, const std::vector<int> &my_vec) {
    int l = -1;
    int r = my_vec.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (my_vec[m] >= L)
            r = m;
        else
            l = m;
    }
    return r-1;
}
int up(int R, const std::vector<int> &my_vec) {
    int l = -1;
    int r = my_vec.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (my_vec[m] > R)
            r = m;
        else
            l = m;
    }
    return r-1;
}
int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
   int m, n;
   std::cin>>n;
   std::cin>>m;
    std::vector<int> left(n);
    std::vector<int> right(n);
    int k;
    int l;
   for(int i=0; i<n; i++){
       std::cin>>k;
       std::cin>>l;
       if(k>=l) {
          right[i]=k;
          left[i] = l;
       }
       else {
           right[i]=l;
           left[i] = k;
       }
   }
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
   int point;
   int num_of_opened;
   int num_of_closed;
   std::vector<int> results(m);
   for (int j=0; j<m; j++){
       std::cin>>point;
       num_of_opened = up(point, left)+1;
       num_of_closed = low(point, right)+1;
       results[j]=num_of_opened - num_of_closed;
   }
    for (int j=0; j<m; j++){
        std::cout<<results[j]<<" ";
    }
   return 0;
}
