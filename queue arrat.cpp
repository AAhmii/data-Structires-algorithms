#include<iostream>
using namespace std;
class Queue {


private:
	int* arr;
	int* front;
	int* rear;
	int size;  
	int noElements;
public:
	Queue(int sz)
	{
		size = sz;
		arr = new int[size];
		front = NULL;
		noElements = 0;
		rear = NULL;
	}

	
	void enqueue(int val)
	{

		if (front == NULL && rear == NULL)
		{
			front = arr;
			rear = arr;
			*rear = val;
			rear++;
			return;
		}

		if (front == arr && rear == arr + (size - 1))
		{
			cout << "queue is overflows" << endl;
			return;
		}

		if ((rear + 1) == front)
		{
			cout << "queue is overflows" << endl;
			return;
		}

		*rear = val;
		rear++;
		return;
	}

	void print() {

		int* ptr;
		ptr = front;
		if (*rear == -1) {
			cout << " empty" << endl;

		}

		while (ptr != rear) {

			cout << *ptr << ",";


			if (ptr == arr + (size - 1)) {

				ptr = arr;
			}
			else {
				ptr++;
			}
			if (ptr == rear) {

				cout << *ptr;
			}

		}
	}

		int dequeue(){
	if ( isEmpty())
	{
	cout << "Queue Underflows!" << endl;
	return -1;
	}

			int* val = front;
			noElements--;
			int* si = &size - 1;
			if (front == si)
				front = 0;
			else
				front++;
			cout << "dequeue val : " << *val << endl;
			return *val;
		}



		~Queue()
		{
			delete[]arr;
		}





	};
	int main()
	{
		Queue q(3);
		q.enqueue(2);
		q.enqueue(4);
		q.enqueue(3);

		q.enqueue(1);

	}

