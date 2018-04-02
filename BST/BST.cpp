#include"BST.h"
#include <iostream>
using namespace std;

BST::BST() {
    this -> root = NULL;
}

void BST::add(int data) {
    add(root, data);
}

void BST::add(Node* &root, int data) {
    if(!root) {
        root = new Node;
        root -> data = data;
        root -> left = NULL;
        root -> right = NULL;
        return;
    }
    if(data < root -> data) {
        add(root -> left, data);
    }else{
        add(root -> right, data);
    }
}

void BST::display() {
    display(root);
}

void BST::display(Node * root) {
    // 中序遍历 ：左，根，右
    // 前序遍历 ：根，左，右
    // 后序遍历 ：左，右，根
    if (!root) {
        return;
    }
    display(root -> left);
    cout<<root -> data<<' ';
    display(root -> right);
}