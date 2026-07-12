#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include <string>
using namespace std;
class ArrayStack{
public:
    ArrayStack();
    void push(int n);
    int pop();
    int peek();
    bool isEmpty();
    string toString();
private:
    int* elements;
    int size;
    int capacity;
};

#endif // ARRAYSTACK_H
