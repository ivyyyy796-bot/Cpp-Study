#include <iostream>
#include "console.h"
#include <string>
#include "vector.h"
#include "vector"
#include "set.h"
using namespace std;
void ph(Vector<string>& v,  Vector<string>& c,Set<Vector<string>>& set){
    if(v.isEmpty() && !set.contains(c)){
        cout << c << endl;
        set.add(c);
    }
    else{
        for(int i=0;i<v.size();i++){
            string s=v[i];
            c.add(s);
            v.remove(i);
            ph(v,c,set);
            v.insert(i,s);
            c.remove(c.size()-1);
        }
    }
}
void permute(Vector<string>& v){
    Vector<string> c;
    Set<Vector<string>> set;
    ph(v,c,set);
}

int main(){
    Vector<string> v {"a","a","b","b","c"};
    permute(v);
    return 0;
}
