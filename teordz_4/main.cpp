#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin>>n;
    std::vector<int> dir(n+1);
    std::vector<int> next(n+1);
    std::vector<int> prev(n+1);
    std::vector<int> block(n+1);
    for(int i=1; i<=n; i++){
        block[i]=1;
        dir[i]=1;
    }
    next[1]=n+1;
    prev[1]=0;
    int x=0;
    int i;
    while(x!=1){
        for(int j=1; j<=n; j++) {
            std::cout << block[j] << " ";
        }
        x=n;
        while(x>1 && ((block[x]=x && dir[x]==1) || (block[x]==1 && dir[x]==-1))){
            dir[x]=-dir[x];
            x--;
        }
        i=block[x];
        if(dir[x]==1){
            if(next[i]>x){
                if(next[i]==n+1){
                    next[x]=n+1;
                }
                else{
                    next[x]=next[i];
                    prev[next[i]]=x;
                }
                next[i]=x;
                prev[x]=i;
            }
            block[x]=next[i];
        }
        else if (block[x]==x){
            if(next[i]==n+1) {
                next[prev[i]] = n + 1;
            }
            else{
                next[prev[i]]=next[i];
                prev[next[i]]=prev[i];
            }
            block[x]=prev[i];
        }
    }
    return 0;
}
