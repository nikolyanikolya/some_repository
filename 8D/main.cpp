#include <iostream>
#include <vector>

int permutation(int n, int k, std::vector<std::vector<int>> &my_vec){
    if(n<k){
        return 0;
    }
    if(k==0){
        return 1;
    }
    if(my_vec[n][k]!=-1)
        return my_vec[n][k];
    return my_vec[n][k]=permutation(n-1, k, my_vec)+permutation(n-1, k-1, my_vec);
}
int main() {

    int c_1, c_2, c_3;
    std::cin>>c_1>>c_2>>c_3;
    std::vector<std::vector<int>> my_vec;
    my_vec.assign(c_1+c_3+c_2+1, std::vector<int>(c_2+c_3+c_1+1));

    for(int i=0; i<c_1+c_2+c_3+1; i++){
        {
            for(int j=0; j<c_1+1; j++){
                my_vec[i][j]=-1;
            }
        }
    }
    int first =permutation(c_1+c_2+c_3, c_1, my_vec);
    for(int i=0; i<c_1+c_2+c_3+1; i++){
        {
            for(int j=0; j<c_2+1; j++){
                my_vec[i][j]=-1;
            }
        }
    }
    int second =permutation(c_2+c_3, c_2, my_vec);
    std::cout<<first*second;

    return 0;
}
