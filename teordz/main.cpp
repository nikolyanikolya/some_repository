#include <iostream>
#include <vector>

int S(int n, int k, std::vector<std::vector<int>> &my_vec){
    if(k==0){
        if(n==0){
            return 1;
        }
        return 0;
    }
    if(n<k){
        return 0;
    }
    if(my_vec[n][k]!=-1)
        return my_vec[n][k];
    return my_vec[n][k]=S(n-1, k-1, my_vec)+k*S(n-1, k, my_vec);
}
int main() {
    int n, k;
    std::cin>>n >>k;
    std::vector<std::vector<int>> my_vec;
    my_vec.assign(n+1, std::vector<int>(k+1));

    for(int i=0; i<n+1; i++){
        {
            for(int j=0; j<k+1; j++){
                my_vec[i][j]=-1;
            }
        }
    }
    std::cout<<S(n, k, my_vec);
    return 0;
}
