#include <iostream>
#include <stack>
int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::stack<char> operators;
    std::stack<int> numbers;
    char symbol;
    int number=0;
    bool flag=false;
    int in_parent=0;
    char operation;
    int current_num;
    while (std::cin.peek()!='\n'){
        std::cin>>symbol;
        if(symbol<='9' && symbol>='0'){
            number*=10;
            number+=symbol-'0';
            flag=true;
        }
        else
        {
            if(flag) {
                numbers.push(number);
                number = 0;
            }
            operators.push(symbol);

        }
        if(!operators.empty() && operators.top()==')'){
            operators.pop();
            while (operators.top()!='('){
                if(operators.top()=='*'||operators.top()=='/')
                    while(operators.top()!='+'&& operators.top()!='-'&& operators.top()!='(') {
                        if (operation =='*'){
                            current_num*=numbers.top();
                            numbers.pop();
                            numbers.push(current_num);
                            else if (operation =='/'){
                                current_num=numbers.top()/current_num;
                                numbers.pop();
                                numbers.push(current_num);
                    }
               operation= operators.top();
               operators.pop();
               current_num=numbers.top();
               numbers.pop();
               if(operation=='+')
                   in_parent+=current_num;
               else if (operation=='-')
                   in_parent-=current_num;

               }
               else if (operation =='/'){
                   current_num=numbers.top()/current_num;
                   numbers.pop();
                   numbers.push(current_num);
               }
            }
            operators.pop();
            current_num=numbers.top();
            numbers.pop();
            in_parent+=current_num;
            numbers.push(in_parent);
            in_parent = 0;
        }

    }
    if (symbol<='9' && symbol>='0')
        numbers.push(number);
    in_parent=0;
    while(!operators.empty()){
        operation=operators.top();
        operators.pop();
        current_num=numbers.top();
        numbers.pop();
        if(operation=='*') {
            current_num *= numbers.top();
            numbers.pop();
            numbers.push(current_num);
        }
        else if (operation=='/')
        {
            current_num=numbers.top()/current_num;
            numbers.pop();
            numbers.push(current_num);
        }
        else if(operation=='-')
            in_parent-=current_num;
        else if(operation=='+')
            in_parent+=current_num;
    }
    current_num=numbers.top();
    numbers.pop();
    in_parent+=current_num;
    numbers.push(in_parent);
    std::cout<<numbers.top();
    return 0;
}
