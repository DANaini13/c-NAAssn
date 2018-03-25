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