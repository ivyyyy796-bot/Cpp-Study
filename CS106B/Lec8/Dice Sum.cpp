#include <iostream>
#include "vector.h"
using namespace std;
int cnt=0;
void dshelper(int dice, int sum, Vector<int>& v){
    cnt++;
    if(dice==0 && sum==0){
        cout << v << endl;
    }
    else{
        for(int i=1;i<=6 && dice>0 && sum >0;i++){
            v.add(i); 
            dshelper(dice-1,sum-i,v);
            // un-choosing **
            v.remove(v.size()-1);
        }
    }
}

void ds(int dice, int sum){
    Vector<int> v;
    dshelper(dice,sum,v);
}

int main(){
    ds(2,5);
    cout<<cnt<<endl;
    return 0;
}
