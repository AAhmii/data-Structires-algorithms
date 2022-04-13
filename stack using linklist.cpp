#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node* down;
};

class stack
{
private:
    node* top;
    int length;
    int count;
public:
    stack()
    {
        top = NULL;
        length = 0;
        count = 5;
    }

    node* create_node(int data)
    {
        node* link_node = new node();
        link_node->data = data;
        return link_node;
    }

    void push(int data)
    {
        if (count == length)
        {
            cout << "overflow" << endl;
            return;
        }



        if (top == NULL)
        {
            top = create_node(data);
            cout << "when top == null data: " << top->data << endl;
            top->down = NULL;
        }
        else
        {
            node* n_node = create_node(data);
            n_node->down = top;
            top = n_node;
            cout << "top data: " << top->data << endl;
        }
        length++;
        cout << "length : " << length << endl;

    }

    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return 0;
        }
        else
        {
            node* temp = top;
            top = top->down;
            cout << "the top value " << temp->data << " is deleted" << endl;
            length--;
            delete temp;
            temp = NULL;
        }

    }
};
int main()
{
    stack s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    cout << "pop" << endl;
    s.pop();
    s.pop();
    s.pop();
    cout << "push" << endl;
    s.push(7);
    cout << "pop" << endl;
    s.pop();
    s.pop();
    s.pop();
    return 0;
}