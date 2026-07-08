#include <iostream>
#include "console.h"
#include <string>
#include <fstream>
#include "map.h"
#include "strlib.h"
#include "gwindow.h"
using namespace std;
int evaluate(string s, int& i)
{
    char c = s[i];
    if(c == '('){
        i++;
        int left = evaluate(s,i);
        i++;
        char opr = s[i];
        i++;
        int right = evaluate(s,i);
        i++;
        if (opr == '+'){
            return left+right;
        }
        else return left*right;
    }
    else{
        //i++;
        return charToInteger(c);
    }
}

int main(){
    string s;
    cin >> s;
    int i=0;
    cout<<evaluate(s,i)<<endl;
    return 0;
}
