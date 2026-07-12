#include "arraystack.h"
#include "error.h"
#include "strlib.h"

ArrayStack::ArrayStack(){
    elements=new int[10];
    size=0;
    capacity=10;
}

void ArrayStack::push(int n){
    elements[size]=n;
    size++;
}
int ArrayStack::pop(){
    if(size==0){
        error("error");
    }
    int result=elements[size - 1];
    size --;
    return result;
}
int ArrayStack::peek(){
    if(size==0){
        error("error");
    }
    int result=elements[size - 1];
    return result;
}
bool ArrayStack::isEmpty(){
    return size==0;
}
string ArrayStack::toString(){
    string s="{";
    for(int i;i<size;i++){
        s+=" "+integerToString(elements[i]);
    }
    return s+"}";
}
