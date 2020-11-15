#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int sum(std::vector<int> ints) { //динамический массив
    long long long sum = 0;
    for (int i = 0; i < ints.size(); ++i)
        sum += ints[i];
    return sum;
}

int main() {
    cout << "Hello, World" << '\n';
    std::vector<int> ints = {1, 2, 3, 4};
    cout << sum(ints);
    return 0;

}
