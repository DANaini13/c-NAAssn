#include "list.h"
#include <iostream>
using namespace std;

void LinkList:: display(Node* head){
    if (!head)
        return;
    cout<<head -> data <<' ';
    display(head -> next);
}

void LinkList:: displayAll() {
    display(head);
    cout<<endl;
}

void LinkList:: removeAll() {
    removeAll(head);
}

void LinkList:: removeAll(Node* &head){
    if(!head)
        return;
    removeAll(head -> next);
    delete head;
    head = NULL;
}

void LinkList:: append(int data,Node* &head){
    if(!head){
        head = new Node;
        head -> data = data;
        head -> next = NULL;
        return;
    }
        append(data,head -> next);
}

void LinkList:: append(int data){
    append(data, head);
}

void LinkList:: removeLast(){
    removeLast(head);
}

void LinkList:: removeLast(Node* &head){
    if(!head){
        return;
    }
    if(!head -> next){
        delete head;
        head = NULL;
        return;
    }
    removeLast(head -> next);
}

void LinkList:: removeFirst(){
    removeFirst(head);
}

void LinkList:: removeFirst(Node* &head){
    if(!head){
        return;
    }
    Node* temp;
    temp = head -> next;
    delete head;
    head = temp;
}

void LinkList:: removeTwo(){
    removeTwo(head);
}

void LinkList:: removeTwo(Node* &head){
    if(!head)
    return;
    if(head -> data == 2){
        Node* temp;
        temp = head -> next;
        delete head;
        head = temp;
    }
    removeTwo(head -> next);
}