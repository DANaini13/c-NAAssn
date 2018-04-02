struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST{
public:
    BST();
    void add(int data);
    void display();
    void preOrderDisplay();
    void postOrderDisplay();
    void deleteAll();
private:
    Node* root;

    void add(Node* &root, int data);
    void display(Node *root);
};