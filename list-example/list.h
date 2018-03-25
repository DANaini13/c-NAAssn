
struct Node{
    int data;
    Node* next;
};

class LinkList{
public:
    LinkList();
    void add(int data);
    void build();
    void display();

    //====================================================
    void displayAll();
    void append(int data);
    void removeLast();
    void removeAll();
    void removeFirst();
    bool exsit(int data); //loop only
private:
    Node *head;

    //====================================================
    void display(Node*);
    void append(int, Node*);
    
};
//deng wo 3 fen zhong...
//ni xian xie list.cpp wenjian.