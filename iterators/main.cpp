#include <iostream>
#include <vector>
#include <sstream>

template <typename int_container, typename comparator_t>
void remove_bads(int_container &vec){  // функция которая удаляет все нечетные
    for(auto it =vec.begin(); it!=vec.end();){
        if(*it %2!=0) // if( !comparator(!std::as_const(*it)
            it = vec.erase(it); // erase удаляет it и возвращает следующего соседа, в списках - это следующий элемент(после удалённого)
        else
            it++;
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
