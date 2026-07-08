#include <iostream>
#include "console.h"
#include <string>
#include <fstream>
#include "map.h"
#include "strlib.h"
using namespace std;
bool isPalindrome(string s){
    if(s.empty()){
        return true;
    }
    char first = s[0];
    char last = s[s.length() - 1];
    string middle = s.substr(1,s.length() -2 );
    return (first == last && isPalindrome(middle));
}


int main()
{
    string s;
    cin >> s;
    cout << isPalindrome(s) << endl;

    return 0;
}
