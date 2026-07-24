#include "HeapPQueue.h"
using namespace std;

HeapPQueue::HeapPQueue() {
    elems = new DataPoint[INITIAL_SIZE];
    allocatedSize = INITIAL_SIZE;
}

HeapPQueue::~HeapPQueue() {
    delete[] elems;
    elems = nullptr;
}

int HeapPQueue::size() const {
    return logicalSize;
}

bool HeapPQueue::isEmpty() const {
    if(logicalSize == 0){
        return true;
    }
    return false;
}

void HeapPQueue::enqueue(const DataPoint& data) {
    if(logicalSize == allocatedSize - 1){
        DataPoint* temp = elems;
        elems = new DataPoint[allocatedSize*2];
        allocatedSize *=2;
        for(int i = 1; i<=logicalSize; i++){
            elems[i] = temp[i];
        }
        delete[] temp;
        temp = nullptr;
    }
    int n = logicalSize + 1;
    elems[n] = data;
    logicalSize ++ ;
    while(n/2 >= 1 && data.weight < elems[n/2].weight){
        DataPoint parent = elems[n/2];
        elems[n/2] = data;
        elems[n] = parent;
        n /= 2;
    }
}

DataPoint HeapPQueue::peek() const {
    if(logicalSize == 0){
        error("ERROR: trying to peek an empty HeapPQueue.");
    }
    return elems[1];
}

DataPoint HeapPQueue::dequeue() {
    if(logicalSize == 0){
        error("ERROR: trying to dequeue an empty HeapPQueue.");
    }
    DataPoint res = elems[1];
    elems[1] = elems[logicalSize];
    int n = 1;
    while(2*n+1 <= logicalSize ){
        int c;
        elems[2*n].weight < elems[2*n+1].weight? c = 2*n : c = 2*n+1;
        if(elems[n].weight > elems[c].weight){
            DataPoint child = elems[c];
            elems[c] = elems[n];
            elems[n] = child;
            n = c;
        }
        else break;
    }
    logicalSize --;
    return res;
}
