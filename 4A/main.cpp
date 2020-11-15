#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n=0;
    int l;
    int r;
    int m;
    double z;
    vector<int> vec(1000);
    for(int i=0; i<1000; i++){
        cin>>n;
        l=0;
        r=n;

        while(r>l+1){
            z=static_cast<double>(l+r)/2;
            m=static_cast<int>(z);
            if (m*m<=n)
                l=m;
            else r=m;

        }
        if(n==1)
           vec[i]=1;
        else
            vec[i]=l;
    }
    for(int i=0; i<1000; i++)
        cout<<vec[i]<<'\n';
    return 0;
}
