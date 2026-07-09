#include <iostream>
#include "console.h"
#include <string>
#include <fstream>
#include "map.h"
#include "strlib.h"
#include "gwindow.h"
#include "vector.h"
#include "vector"
using namespace std;
int cnt=0;
void dshelper(int dice, int sum, Vector<int>& v){
    cnt++;
    if(dice==0 && sum==0){
        cout << v << endl;
    }
    else if(sum>=dice*1 && sum <=dice*6){
        for(int i=1;i<=6;i++){
            v.add(i);
            dshelper(dice-1,sum-i,v);
            v.remove(v.size()-1);
        }
    }
}

void ds(int dice, int sum){
    Vector<int> v;
    dshelper(dice,sum,v);
}

int main(){
    ds(3,7);
    cout<<cnt<<endl;
    return 0;
}
