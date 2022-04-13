#include <iostream>
using namespace std;

struct Node
{
public:
    char key;
    Node * leftptr;
    Node * rightptr;
};



class stack
{
private:
    int top = -1;
public:
    Node * stk[20];
    void push(Node * val);
    Node * pop();
    void expression_tree(char * equation);
    int checking_value(char key);
};
void stack::push(Node * val)
{
    top++;
    stk[top] = val;
}
Node * stack::pop()
{
    top--;
    return (stk[top + 1]);
}

void stack::expression_t(char *equation) {
   char value;
   Node *temp, *ptr1, *ptr2;
   int check;
   value = expression[0];
   for (int i = 1; value != 0; i++) {
      check = checking_value(value);
      if (check == 1) {
         temp = new Node();
         temp->key = value;
         temp->leftptr = NULL;
         temp->rightptr = NULL;
         push(temp);
      } else {
         ptr1 = pop();
         ptr2 = pop();
         temp = new Node();
         temp->key = value;
         temp->leftptr = ptr2;
         temp->rightptr = ptr1;
         push(temp);
      }
      key = equation[i];
   }
}


int stack::checking_char(char key)
{
    if (key == '+' || key == '-' || key == '*' || key == '/')
      return (-1);
   else if (key >= 'A' || key <= 'Z')
      return (1);
   else if (key >= 'a' || key <= 'z')
      return (1);
   else
      return (-2);
}


int main()
{
    char equation[20];
    stack sk;
    cout << "Enter Postfix Expression : ";
    cin >> equation;
    sk.expression_tree(equation);
}
