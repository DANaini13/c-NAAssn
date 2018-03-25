
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
private:
    Node *head;
};
//deng wo 3 fen zhong...
//ni xian xie list.cpp wenjian.