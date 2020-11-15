

#include <iostream>
#include <vector>

void merge(unsigned long long l, unsigned long long separate, unsigned long long r, std::vector <unsigned long long> &ar,  std::vector<std::pair<unsigned long long, unsigned long long>> &result) {
    std::vector<unsigned long long> left_side(separate-l+1);
    std::vector<unsigned long long> right_side(r-separate);
    //std::cout<<"l"<<":"<<l<<" ";
    //std::cout<<"separator"<<":"<<separate<<" ";
    //std::cout<<"r"<<":"<<r<<"\n";
    for(int k=0; k<separate-l+1; k++)
        left_side[k]=ar[l+k];
    for(int k=0; k<r-separate; k++)
        right_side[k]=ar[separate+1+k];
    unsigned long long i = 0;
    unsigned long long j = 0;
    unsigned long long h=l;
    for(; i<left_side.size() && j<right_side.size(); h++){
        if(right_side[j]>=left_side[i]){
            ar[h]=left_side[i++];
            result[ar[h]].second+=j;
        }
        else
        {
            ar[h] = right_side[j++];
            result[ar[h]].first+=separate-l-i+1;
        }
    }
    while(i<left_side.size()){
        ar[h]=left_side[i++];
        result[ar[h]].second+=j;
        h++;
    }
    while(j<right_side.size()){
        ar[h++]=right_side[j++];
    }


}
void MergeSort (unsigned long long l, unsigned long long r, std::vector<unsigned long long> &ar, std::vector<std::pair<unsigned long long, unsigned long long>> &result) {
    if (r ==l) return ;
    unsigned long long separate = (l + r) / 2;
    MergeSort (l, separate, ar, result);
    MergeSort (separate+1, r, ar, result);
    merge(l, separate, r, ar, result);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    std::cin>> n;
    std::vector<std::pair<unsigned long long, unsigned long long>> result(n+1);
    std::vector<unsigned long long> source(n);
    for(int i=0; i<n; i++) {
        std::cin >> source[i];
        result[i].first=0;
        result[i].second=0;
    }
    result[n].first=0;
    result[n].second=0;
    MergeSort(0, n-1, source, result);
    unsigned long long S=0;
    for(int i=0; i<n; i++) {
        S += result[i].first * result[i].second;
        //std::cout<<source[i]<<" ";
    }
    std::cout<<S;
    return 0;
}
