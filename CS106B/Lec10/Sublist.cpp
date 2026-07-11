#include <iostream>
#include "console.h"
#include <string>
#include "vector.h"
#include "set.h"
using namespace std;
void sublistHelper(Vector<string> v,Set<Vector<string>>& chosen){
    for(int i=0;i<v.size();i++){
        string temp=v[i];
        v.remove(i);
        chosen.add(v);
        sublistHelper(v,chosen);
        v.insert(i,temp);
    }
}
void sublist(Vector<string> v){
    Set<Vector<string>> chosen {v};
    sublistHelper(v,chosen);
    for(Vector vec :chosen){
        cout << vec << endl;
    }
}

int main(){
    Vector<string> v {"a","b","c"};
    sublist(v);
    return 0;
}
