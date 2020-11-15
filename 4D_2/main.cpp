#include <iostream>
#include <vector>
const int L=999983;
std::vector<int> hash(L);
std::vector<int> how_many(L);
int get_num(const int &x){
    int r=x%L;
    while(hash[r]!=0 && hash[r]!=x){
        if(r++==L)
            r=0;
    }
    return r;
}
void swap(int &a, int &b){
    int t=a;
    a=b;
    b=t;
}
struct hse_1{
private:
    int n;
    std::vector<int> a;
public:
    hse_1(){
        n=0;
        a.resize(200000);
    }
    void add(const int &x) {
        a[++n]=x;
        siftUp(n);
    }
    void siftUp(int i) {
        while (i > 1 && a[i] < a[i / 2]) {
            swap(a[i], a[i / 2]);
            i /= 2;
        }
    }
    void  siftdown(int i) {
        while (1) {
            int l = 2 * i;
            if (l + 1 <= n && a[l + 1] < a[l]) l++; // выбрать меньшего из детей
            if (!(l <= n && a[l] < a[i]) ) break ; // если все дети не меньше нас, это конец
            swap (a[l] , a[i]) , i = l; // перейти в ребёнка
        }
    }
      int min(){
        return a[1];
    }
    void extract_min(){
        swap(a[1], a[n]);
        n--;
        siftdown(1);
    }

};
struct hse_2{
private:
    int n;
    std::vector<int> a;
public:
    hse_2(){
        n=0;
        a.resize(100001);
    }
    void add(const int &x) {
        a[++n]=x;
        siftUp(n);
    }
    void siftUp(int i) {
        while (i > 1 && a[i] > a[i / 2]) {
            swap(a[i], a[i / 2]);
            i /= 2;
        }
    }
    void  siftdown(int i) {
        while (1) {
            int l = 2 * i;
            if (l + 1 <= n && a[l + 1] > a[l]) l++; // выбрать меньшего из детей
            if (!(l <= n && a[l] > a[i]) ) break ; // если все дети не меньше нас, это конец
            swap (a[l] , a[i]) , i = l; // перейти в ребёнка
        }
    }
    int max(){
        return a[1];
    }
    void extract_max(){
        swap(a[1], a[n]);
        n--;
        siftdown(1);
    }

};

int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    char current_element;
    int element;
    hse_1 min_heap;
    hse_2 max_heap;
    char par_1;
    char par_2;
    for(int i=0; i<N; i++){
        for(int j=0; j<=5; j++){
            std::cin>>current_element;
        }
        if(current_element=='t'){
            std::cin>>par_1;
            std::cin>>element;
            std::cin>>par_2;
            how_many[get_num(element)]+=1;
            hash[get_num(element)]=element;
            min_heap.add(element);
            max_heap.add(element);
        }
        else if(current_element=='x'){
            while(how_many[get_num(max_heap.max())]==0)
                max_heap.extract_max();
            std::cout<<max_heap.max()<<"\n";
            how_many[get_num(max_heap.max())]-=1;
            max_heap.extract_max();
        }
        else {
            while(how_many[get_num(min_heap.min())]==0)
                min_heap.extract_min();
            std::cout<<min_heap.min()<<"\n";
            how_many[get_num(min_heap.min())]-=1;
            min_heap.extract_min();
        }
    }

    return 0;
}
