#include "WhatAreYouDoing.h"
#include <string>
#include "strlib.h"
#include <cctype>
#include "vector.h"
using namespace std;
string Converter(Vector<string> v){
    string s;
    for(int i=0;i<v.size();i++){
        s+=v[i];
    }
    return s;
}

void aHelper(Vector<string>& v,Vector<string>& chosen,Set<string>& set,int i){
    if(i == v.size()){
        set.add(Converter(chosen));
        return ;
    }
    else{
        if(!isalpha(v[i][0])){
            chosen+=v[i];
            aHelper(v,chosen,set,i+1);
            chosen.remove(chosen.size()-1);
        }
        else{
            string lower = toLowerCase(v[i]);
            string upper = toUpperCase(v[i]);

            chosen+=lower;
            aHelper(v,chosen,set,i+1);
            chosen.remove(chosen.size()-1);

            chosen+=upper;
            aHelper(v,chosen,set,i+1);
            chosen.remove(chosen.size()-1);
        }
    }
}

Set<string> allEmphasesOf(const string& sentence) {
    Vector<string> v = tokenize(sentence);
    Set<string> set;
    Vector<string> chosen;
    int i=0;
    aHelper(v,chosen,set,i);
    return set;

}
