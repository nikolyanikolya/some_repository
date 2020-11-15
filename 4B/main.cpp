#include <iostream>
#include <vector>
int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::vector<int> my_vec;
    std::vector<std::string> answers;
    int n, k;
    std::cin>>n;
    std::cin>>k;
    my_vec.resize(n);
    answers.resize(k);
    for(int i=0; i<n; i++){
        std::cin>>my_vec[i];
    }
    int b;
    int ptr=0;
    for(int j=0; j<k; j++){
        std::cin>>b;
        while(ptr!=n && my_vec[ptr]<b)
            ptr++;
        if (my_vec[ptr]==b && ptr!=n)
           answers[j]= "YES";
        else(answers[j]="NO");
    }
    for(std::string i : answers){
        std::cout<<i<<"\n";
    }
    return 0;
}
