#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
unsigned int cur = 0;
unsigned int a;
unsigned int b;
unsigned int nextRand24() {
    cur = cur * a + b;
    return cur >> 8;
}
unsigned int nextRand32() {
    unsigned int a = nextRand24(), b = nextRand24();
    return (a<< 8) ^ b;
}
int main() {
    unsigned int n;
    std::cin>>n;
    std::cin>>a;
    std::cin>>b;
    vector< long long > my_vec(n);
    for (int i=0; i<n; i++){
        my_vec[i]=nextRand32();
    }
    std::nth_element(my_vec.begin(), my_vec.begin() + my_vec.size()/2, my_vec.end());

    unsigned long long sum=0;
    for(int i=0; i<n; i++){

        if (my_vec[i]-my_vec[my_vec.size()/2]>0) {
            sum += my_vec[i] - my_vec[my_vec.size() / 2];

        }
        else {
            sum -= my_vec[i] - my_vec[my_vec.size() / 2];

        }

    }

    std::cout<<sum;

}
