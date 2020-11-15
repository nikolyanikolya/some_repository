#include <iostream>
#include <vector>
unsigned int cur = 0;
unsigned int a=0;
unsigned int b=0;
unsigned int nextRand24() {
     cur = cur * a + b;
     return cur >>  8;
     }
void merge(int l, int m, int r, std::vector <int> a, std::vector<int> buffer) {
    int i=0;
    int j=i;
    while(i!=l && j+m!=r){
        if(a[i]> a[j+m]){
            buffer.push_back(a[j+m]);
            j++;
        }
        else
        {
            buffer.push_back(a[i++]);
        }
    }
    while(i!=l){
            buffer.push_back(a[i++]);

    }
    while(j+m!=r){
        buffer.push_back(a[j+m]);
        j++;
    }
}
void MergeSort (int l, int r, std::vector<int> a, std::vector<int> buffer) {
     if (r - l <= 1) return ;
     int m = (l + r) / 2;
     MergeSort (l, m, a, buffer);
     MergeSort (m, r, a, buffer);
     merge(l, m, r, a, buffer);
     }
int main() {
    int m, n;
    std::cin>> m;
    std:: cin>> n;
    std::cin >> a;
    std::cin >> b;

    
    return 0;
}
