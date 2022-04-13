#include<iostream>
using namespace std;


struct node {

	int info;
	node* next;
};

class linklist {

private:	
	node* head;
	node* temp;


public:

	
	void deletion();
	void print();
	void search();
	void emptiness();
	void Delete_Position();
	linklist();
	void add_link_node_to_head(int data);
	node* get_new_node(int data) {
		node* link_node = new node();
		link_node->info = data;
		link_node->next = NULL;
		return link_node;
	}
};

linklist::linklist()
{
	head = NULL;
	temp = NULL;
	

}

void linklist::emptiness()
{
	head = new node;
	temp = head;
	if (head==NULL)
	{
		cout << "the list is empty:	" << endl;
	}
	else
	{
		cout << "Enter data:	" << endl;
		cin >> temp->info;
	}

}




void linklist:: add_link_node_to_head(int data) {
	if (head == NULL) {
		head = get_new_node(data);
		return;
	}
	node* data_node = get_new_node(data);
	data_node->next = head;
	head = data_node;
}

void linklist::deletion()
{
	temp = head;
	int key;
	node* temp1;
	cout << "enter the key:	" << endl;
	cin >> key;
	while (temp != NULL)
	{
		if (temp->next->info == key)
		{
			temp1 = temp->next;
			temp->next = temp->next->next;
			delete temp1;

		}


		temp = temp->next;

	}

}

void linklist::print()
{
	node* itera = head;
	while (itera) {
		cout << itera->info << " ";
		itera = itera->next;
	}
}





void linklist::search()
{
	int key;
	cout << "ENTER THR KEY TO FIND THE NODE:	" << endl;
	cin >> key;
	temp = head;
	while (temp!=NULL)
	{ 
		if (temp->info==key)
		{
			cout << "Node Found!	"<< temp->info << endl;
			//cout << temp->info;
			return;
		}
		




		temp = temp->next;
		
	}
	
}

void linklist::Delete_Position()
{
	int position;
	cout << "Enter the position of the node you want to delete \n";
	cin >> position;
	node* temp = new node;
	node* previous = new node;
	temp = head;
	for (int i = 1; i < position; i++)
	{
		previous = temp;
		temp = temp->next;

	}
	previous->next = temp->next;
}


int main()
{
	linklist l;
	

	for (;;)
	{
		int num;
		cout << "ENTER YOUR CHOICE TO EVALUATE THE FUNCTION:	" << endl;
		cin >> num;
		if (num==1)
		{
			l.emptiness();
		}
		else	if (num == 2)
		{
			int data = 0;
			cout << "enter data" << endl;
			cin >> data;
			l.add_link_node_to_head(data);
		}
		else if (num == 3)
		{
			l.Delete_Position();
		}
		else if (num == 4)
		{
			l.print();
		}
		else if (num == 5)
		{
			l.search();
		}
		else
		{
			cout << "WRONG INPUT:	" << endl;
		}
		
		
	}

	


	return 0;

}









