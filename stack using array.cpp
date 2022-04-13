#include<iostream>

using namespace std;

class Stack
{
private:
    int* arr;
    int* top;
    int size;
    int count;
public:
    Stack(int s)
    {
        arr = new int[s];
        size = s;
        count = -1;
        top = arr;
    }

    bool isFull()
    {
        if (count == (size - 1))
            return true;
        else
            return false;
    }

    void push(int val)
    {

        if (isFull())
        {
            cout << "Overflow!" << endl;

        }


        else
        {
            count++;
            top++;
            *top = val;
            cout << "top data : " << *top << endl;

        }




    }

    bool isEmpty()
    {
        if (count == -1)
            return true;
        else
            return false;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return -1;
        }
        else
        {
            int* val = top;
            top--;
            count--;
            return *val;
        }

    }



    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack s(5);
    s.push(5);
    s.push(1);
    s.push(4);
    s.push(3);
    s.push(1);
    s.push(99);
    cout << "pop" << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << "pop" << endl;
    cout << s.pop() << endl;
    s.push(9);
    s.push(4);

    system("pause");

    return 0;
}