#include <iostream>
#include <algorithm>
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
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    unsigned long long n;
    std::cin>>n;
    std::cin>>a;
    std::cin>>b;
    unsigned long long numerator=0;
    for(int i=0; i<n; i++){
       numerator+= nextRand32();
    }
    unsigned long long my_gcd = std::__gcd(numerator, n);
    numerator/=my_gcd;
    n/=my_gcd;
  std::cout<<numerator<<"/"<<n;

}