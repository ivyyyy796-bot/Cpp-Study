#include <iostream>
#include "console.h"
#include <string>
#include "strlib.h"
using namespace std;
void pbhelper(int digits, string s){
    if(digits==0){
        cout << s << endl;
    }
    else{
        pbhelper(digits - 1, s + '0');
        pbhelper(digits - 1, s + '1');
    }
}
void pb(int digits){
    pbhelper(digits,"");
}

int main(){
    pb(3);
    return 0;
}
