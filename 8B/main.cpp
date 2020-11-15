#include <iostream>
#include <vector>

void soch(int n, int k,  std::vector<int> arr){
   if(k==0) {
       for(auto i :arr)
       {
           std::cout<<i<<" ";
       }
       std::cout<<"\n";
       return;
   }
   if(n>=k){
       arr.push_back(n);
       soch(n-1, k-1,  arr);
       arr.pop_back();
   }
   if(n>k){
       soch(n-1, k,  arr);
   }


}
int main() {
    std::vector<int> arr;
    int n;
    int k;
    std::cin>>n;
    std::cin>>k;
    soch(n, k, arr);
    return 0;
}
