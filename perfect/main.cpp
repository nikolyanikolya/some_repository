#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    int k;
    int d;
    cin>>d;
    cin>>k;
    vector <int> b;
    bool flag=false;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int j=0;
    int t=0;
    while(k!=0 && t!=n-1){
        while(a[t+1]<a[t]&& t!=n-1)
            t++;
         j=t;
         if(t==n-1)
             flag=true;
         while (a[j]<=a[t] && k!=0 && j!=0){
             a[j]=d+1;
             j--;
             k--;
         }
         t++;
        if(t==n-1 && k!=0)
            flag=true;
    }
    if (flag) {
        for (int i = 0; i < n; i++){
            if(i>=n-k)
                a[i]=d+1;
        }
    }
    else
    {
        for(int i=0; i<n; i++){
            if(a[i]!=d+1)
                b.push_back(a[i]);
        }
    }
    for(int i=0; i<n-k; i++)
        cout<<b[i]<<" ";
    return 0;
}