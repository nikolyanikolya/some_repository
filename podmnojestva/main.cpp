
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

vector<int> arr = { 1, 2, 3, 4 };

void outMas(const vector<int>&mas, int num, string s)
{
    if (num == mas.size())
    {
        if(!s.empty()) {
            cout << s << '\n';
        }
        return;
    }
    outMas(mas,num+1,s);
    s = s + to_string(mas[num]) + ' ';
    outMas(mas,num+1,s);
}

int main()
{
    outMas(arr,0,"");
}