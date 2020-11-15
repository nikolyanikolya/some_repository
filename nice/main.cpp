#include <iostream>
#include <vector>

using namespace std;
int main() {
    std::vector<int> long_number;
    string init_str;
    std::cin >> init_str;
    long_number.resize(init_str.length());
    for (int i = init_str.length()-1; i >=0; i--) {
        char symbol = init_str[i];
        long_number[long_number.size() - i - 1] = symbol - '0';
    }
        for (int j = 0; j < long_number.size(); j++)
            std::cout << long_number[j];
        return 0;

}

