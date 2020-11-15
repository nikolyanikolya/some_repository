#include <iostream>
#include <vector>

int jumping(int n, std::vector<int> &my_vec){
    if(n<0) {
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(my_vec[n]!=-1)
        return my_vec[n];
    return my_vec[n]=jumping(n-1, my_vec) +jumping(n-3, my_vec)+jumping(n-4, my_vec);
}
int main() {
    int n;
    std::cin>>n;
    std::vector<int> my_vec(n+1);
    for(int i=0; i<=n; i++)
        my_vec[i]=-1;
    std::cout<<jumping(n, my_vec);
    return 0;
}
