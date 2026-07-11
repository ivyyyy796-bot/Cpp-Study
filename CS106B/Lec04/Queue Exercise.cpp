/* write mirror and stutter functions
*/

#include "stack.h"
#include <iostream>
#include <string>
#include "queue.h"
using namespace std;
void stutter(Queue<int>& q);
void mirror(Queue<string>& q);
int main(){
    Queue<string> q {"a","b","c"};
    mirror(q);
    cout<<q<<endl;

    Queue<int> qu {1,2,3};
    stutter(qu);
    cout<<qu<<endl;

    return 0;
}
void stutter(Queue<int>& q){
    int size=q.size();
    for(int i=0;i<size;i++){
        int j=q.dequeue();
        q.enqueue(j);
        q.enqueue(j);
    }
}

void mirror(Queue<string>& q){
    Stack<string> s;
    for(int i=0;i<q.size();i++){
        string str=q.dequeue();
        s.push(str);
        q.enqueue(str);
    }
    while(!s.isEmpty()){
        q.enqueue(s.pop());
    }
}
