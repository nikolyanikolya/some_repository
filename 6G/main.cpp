#include <iostream>
#include <vector>
#include <stdlib.h>
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
void swap (unsigned long long &k, unsigned long long &l){
    unsigned long long t=k;
     k=l;
     l=t;
}
void Partition( int l,  int r, unsigned long long x, vector<unsigned long long> &c, int &i, int &j){
     i = l;
     j = r;
    while(i<=j){
        while(c[i]<x) i++;
        while(c[j]>x){ j--; }
        if (i<=j) {
            swap(c[i], c[j]);
            i++;
            j--;

        }
    }

}
unsigned long long Statistic ( int l, int r, vector<unsigned long long> &p, int k ) { // [l, r]
     if (r <= l) return p[r];
     int i, j;
     unsigned long long x;
     x = p[rand()%(r-l+1)+l];
     //std::cout<<x<<"\n";
     Partition (l, r, x, p, i, j) ;
     for(int z=0; z<p.size(); z++){
         //std::cout<<p[z]<<" ";
     }
    // std::cout<<"\n";
     if (j < k && k < i) return x;
     return k <= j ? Statistic(l, j, p, k) : Statistic (i, r, p, k);
     }
int main() {
    int n, q;
    std::cin>>n;
    std::cin>>q;
    std::cin>>a;
    std::cin>>b;
    vector<unsigned long long > my_vec(n);
    for (int z=0; z<n; z++){
        my_vec[z]=nextRand32();
    }
    for(unsigned int k=0; k<my_vec.size(); k++){
        //std::cout<<my_vec[k]<<" ";
    }
    //std::cout<<"\n";
    //Partition(0, n-1, my_vec[5], my_vec, i, j);
    for(unsigned int k=0; k<my_vec.size(); k++){
        //std::cout<<my_vec[k]<<" ";
    }
    //std::cout<<"\n";
    std::cout<<Statistic(0, n-1, my_vec, q-1);

return 0;
}
