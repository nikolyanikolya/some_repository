#include <iostream>
#include <vector>

void soch(int n, int k, int current,  std::vector<int> arr){
   if(k==0) {
       for(auto i :arr)
       {
           std::cout<<i<<" ";
       }
       std::cout<<"\n";
       return;
   }
    if(current<=n){
        arr.push_back(current);
        soch(n, k-1, current+1,  arr);
        arr.pop_back();
    }
   if(current<n){
       soch(n, k, current+1, arr);
   }
}
int main() {
    std::vector<int> arr;
    int n;
    int k;
    std::cin>>n;
    std::cin>>k;
    soch(n, k, 1, arr);
    return 0;
}
