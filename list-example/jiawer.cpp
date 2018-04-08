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

void LinkList:: append(int data,Node* head){
    if(!head){
        head = NULL;
        head = new Node;
        head -> data = data;
        return;
    }
        append(data,head -> next);
    
}

void LinkList:: append(int data){
    append(data, head);
}

void LinkList:: removeLast(){
    if(!head){
        return;
    }
    if(!head -> next){
        head = NULL;
    }
}