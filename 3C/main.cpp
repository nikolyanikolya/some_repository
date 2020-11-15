#include <iostream>
#include <stack>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::stack<char> operators;
    std::stack<int> numbers;
    char c,op;
    int x;
    int num = 0;
    bool fl=false;
    int inscobs=0;
    while (std::cin.peek() != '\n') {
        std::cin>>c;

        if ((c =='(') || (c == ')') || (c == '+') || (c == '-')){
            if (fl){
                numbers.push(num);
                fl=false;
                num = 0;
            }
            operators.push(c);
        }
        else{
            fl=true;
            num*=10;
            num+= c - '0';
        }

        if (!operators.empty() && operators.top()==')'){
            operators.pop();

            while(operators.top() != '('){
                op = operators.top();
                operators.pop();
                x=numbers.top();
                numbers.pop();
                if (op=='+')
                    inscobs+=x;
                else
                    inscobs-=x;
            }

            operators.pop();
            x=numbers.top();
            numbers.pop();
            inscobs+=x;
            numbers.push(inscobs);
            inscobs=0;
        }

    }

    if ((c !='(') && (c != ')') && (c != '+') && (c != '-'))
        numbers.push(num);

    inscobs=0;
    while(!operators.empty()) {
        op = operators.top();
        operators.pop();

        if (op=='-')
            inscobs-=numbers.top();
        else
            inscobs+=numbers.top();

        numbers.pop();
    }
    x=numbers.top();
    numbers.pop();
    numbers.push(inscobs+x);

    cout<<numbers.top();

    return 0;

}