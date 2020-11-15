#include <iostream>
#include <vector>
#include <algorithm>

struct shelves{
    unsigned long long y=0;
    unsigned long long left_side;
    unsigned long long right_side;
    int open_close;
};
bool compare_blin(shelves y_1,  shelves y_2){
    return (y_1.y < y_2.y);
}
int main() {
    int N;
    std::cin>>N;
    std::vector<unsigned long long>x_coordinate(2*N);
    std::vector<shelves>y_coordinate(2*N);
    for(int i=0; i<N; i++){
        std::cin>>x_coordinate[2*i];
        std::cin>>y_coordinate[2*i].y;
        y_coordinate[2*i].open_close=1;
        std::cin>>x_coordinate[2*i+1];
        std::cin>>y_coordinate[2*i+1].y;
        y_coordinate[2*i+1].open_close=-1;
        y_coordinate[2*i+1].left_side=x_coordinate[2*i];
        y_coordinate[2*i+1].right_side=x_coordinate[2*i+1];
        y_coordinate[2*i].left_side=x_coordinate[2*i];
        y_coordinate[2*i].right_side=x_coordinate[2*i+1];
    }


    std::sort(x_coordinate.begin(), x_coordinate.end());

    std::sort(y_coordinate.begin(), y_coordinate.end(), compare_blin);

    int counter =0;
    unsigned long long union_rect=0;
    bool flag;
    unsigned long long y_1;
    for(int i=1; i<2*N; i++){
            flag = false;
            for(int j=0; j<2*N; j++){
              if(y_coordinate[j].left_side >= x_coordinate[i] || y_coordinate[j].right_side<=x_coordinate[i-1])
                  continue;
               else {
                  if (flag==false)
                      y_1=y_coordinate[j].y;
                  counter += y_coordinate[j].open_close;
                  flag = true;
              }
               if (counter ==0 && flag)
               {
                  union_rect+= (y_coordinate[j].y - y_1)* (x_coordinate[i]-x_coordinate[i-1]);
                  flag = false;
               }


       }
    }
    std::cout<<union_rect;
    return 0;
}
