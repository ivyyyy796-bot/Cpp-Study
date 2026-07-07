/* write a function checkBalance that accepts a string of source code and checks whether the braces ot parentheses are balanced. 
- every ( or { must be closed by a ) or } in the opposite order.
- return the index at which an imbalance occurs, or -1 if balanced.
- if any ( or { are never closed, return the strings's length*/

#include "stack.h"
#include <iostream>
#include <string>
using namespace std;
int checkBalance(string code);
int main()
{
    string code1="if (a(4)>9) { foo(a(2));}";
    string code2="for(int i=0;i<(3};i++) {foo{);)";
    string code3="(";

    cout<<checkBalance(code1)<<endl;
    cout<<checkBalance(code2)<<endl;
    cout<<checkBalance(code3)<<endl;
    return 0;
}
int checkBalance(string code)
{
    Stack<char> stack;
    for(int i=0;i<code.length();i++){
        char c = code[i];
        if(c == '(' || c== '{'){
            stack.push(c);
        }
        else if(c == ')'){
            if(!stack.isEmpty() && stack.peek() =='('){
                stack.pop();
            }
            else return i;
        }
        else if(c =='}'){
            if(!stack.isEmpty() && stack.peek() =='{'){
                stack.pop();
            }
            else return i;
        }
    }
    if(!stack.isEmpty() ){
        return code.size();
    }

    return -1;
}
