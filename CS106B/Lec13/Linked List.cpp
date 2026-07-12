#include <iostream>
#include "console.h"
using namespace std;
struct ListNode{
    int data;
    ListNode* next;
    ListNode(int value){
        data=value;
        next=nullptr;
    }
};

void addFront(ListNode*& front, int value){
    ListNode* NewNode = new ListNode();
    NewNode->data = value;
    NewNode->next = front;
    front = NewNode;
}

void add(ListNode*& front, int value){
    ListNode* newNode = new ListNode();
    NewNode->data = value;
    NewNode->next = nullptr;
    if(front == nullptr){
        front=newNode;
    }
    else{
        ListNode* current=front;
        while(current->next!=nullptr){
            current=current->next;
        }
        current->next=newNode;        
    }
}

void removeFront(ListNode*& front){
    if(front!=nullptr){
        ListNode* temp=front;
        front=front->next;
        delete temp;
    }
}

int main(){
    ListNode* front=nullptr;
    addFront(front,10);
    return 0;
}
