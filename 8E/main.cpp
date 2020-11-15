#include <iostream>
#include <vector>
std::vector<std::vector<int>> result;
void soch(int n, std::vector<int> &my_vec){
    if(n==0) {
        result.push_back(my_vec);
        return;
    }

        for(int i=n; i>=1; i--){
           if ( my_vec.size()==0 || i<=my_vec[my_vec.size()-1]) {
               n -= i;
               my_vec.push_back(i);
               soch(n, my_vec);
               n += i;
               my_vec.pop_back();
           }
           else continue;

        }
}
int main() {
    int n;
    std::cin>>n;
    std::vector<int>my_vec;
    soch(n, my_vec);
    for(int t=result.size()-1; t>=0; t--){
        for (auto i: result[t]) {
            std::cout<<i<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}
