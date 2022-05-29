#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node* next, * pre;
    Node(int value);
};
Node::Node(int value)
{
    val = value;
    next, pre = nullptr, nullptr;
}
class doubly
{
private:
    Node* hdr, * curr;
    int len;
public:
    doubly();
    void insert(int val, int pos);
    void print();
    void deletion(int pos);
};

doubly::doubly()
{
    hdr, curr = nullptr, nullptr;
    len = 0;
}
void doubly::insert(int val, int pos)
{
    Node* n = new Node(val);
    if (len == 0)
    {
        hdr = n;
        len++;
        return;
    }
    if (pos == 1)
    {
        n->next = hdr;
        hdr->pre = n;
        hdr = n;
        len++;
        return;
    }
    curr = hdr;
    for (int i = 1; i < pos; i++)// dleting at any specific position in the list 
    {
        curr = curr->next;
    }
    n->next = curr->next;
    n->pre = curr;
    if (curr->next != nullptr)
    {
        curr->next->pre = n;
    }
    curr->next = n;
    len++;
    return;


}
         






void doubly::print() {
   
    curr = hdr;
    if (hdr == nullptr)
    {
        cout << "Linked list is empty./n";
        return;
    }

    for (int i = 0; i <= len; i++)
    {
        cout << curr->val << endl;
        curr = curr->next;
    }
    cout << curr->val << endl;
}
void doubly::deletion(int pos) {
    if (len == 0)
    {
        cout << "list is already empty" << endl;
        return;
    }
    if (pos == 1)
    {
        curr = hdr;
        hdr = curr->next;
        delete curr;
        hdr->pre = nullptr;
        len--;
        return;
    }
    
    Node* previous = nullptr;
    curr = hdr;
    for (int i = 0; i <= pos; i++)
    {
        previous = curr;
        curr = curr->next;
    }
    previous->next = curr->next;
    curr->next->pre = previous;
    delete curr;
    len--;
}
int main() {
    doubly d1;
    d1.insert(1, 1);
    d1.insert(2, 2);
    d1.insert(3, 3);
    d1.insert(4, 4);
    d1.deletion(4);
    d1.print();
}