
#include <vector>
#include <set>
#include <unordered_map>
#include "optimization.h"

int N=999983;
int get_index(int a, const std::vector<int> &b){
    int index= a%N;
    while(b[index]!=-1 && b[index]!=a) {
        index++;
        if (index == N)
            index=0;
    }
    return index;

}
int main() {

    std::unordered_map<int, std::set<int>> my_map; //value -> indexes
    std::set<std::pair<int, int>> num_of_values; // pair.first -> п╨п╬п╩п╦я┤п╣я│я┌п╡п╬ п╥п╫п╟я┤п╣п╫п╦п╧, pair.second -> index
    std::pair<int, int> aux_pair;
    int n=readInt();
    std::vector<int> my_vec(n);
    for(int i=0; i<n; i++) {
        my_vec[i]=readInt();
        my_map[my_vec[i]].insert(i);
    }
    for(int i=0; i<n; i++){
        aux_pair.first=my_map[my_vec[i]].size();
        aux_pair.second=*my_map[my_vec[i]].begin();
        num_of_values.insert(aux_pair);
    }
    int q=readInt();
    char k;
    int change_index;
    int new_value;
    int help_element;
    std::pair<int, int> aux_2;
    std::vector<int> result;
    for(int i=0; i<q; i++){
        k=readChar();
        if(k=='?') {
            result.push_back(num_of_values.begin()->second);
        }
        else {
            change_index=readInt<long long>();
            new_value=readInt<long long>();
            if (new_value != my_vec[change_index]) {
                if (my_map.count(new_value)) {
                    aux_2.first = my_map[new_value].size();
                    aux_2.second = *my_map[new_value].begin();
                    num_of_values.erase(aux_2);
                }
                help_element = my_map[my_vec[change_index]].size();
                aux_pair.first = help_element;
                aux_pair.second = *my_map[my_vec[change_index]].begin();
                num_of_values.erase(aux_pair);
                if (help_element == 1) {
                    my_map.erase(my_vec[change_index]);
                    my_map[new_value].insert(change_index);
                    aux_pair.first = my_map[new_value].size();
                    aux_pair.second = *my_map[new_value].begin();
                    num_of_values.insert(aux_pair);
                    my_vec[change_index] = new_value;
                } else {
                    my_map[my_vec[change_index]].erase(change_index);
                    aux_pair.first = help_element - 1;
                    aux_pair.second = *my_map[my_vec[change_index]].begin();
                    num_of_values.insert(aux_pair);
                    my_map[new_value].insert(change_index);
                    aux_pair.first = my_map[new_value].size();
                    aux_pair.second = *my_map[new_value].begin();
                    num_of_values.insert(aux_pair);
                    my_vec[change_index] = new_value;
                }

            }
        }
    }
    for(unsigned int i=0; i<result.size(); i++) {
        writeInt(result[i]);
        writeChar('\n');
    }
    return 0;
}
