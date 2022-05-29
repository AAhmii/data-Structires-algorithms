#include<iostream>
using namespace std;

struct node
{
	int data;
	int leftbit;
	int rightbit;
	node* left;
	node* right;
};

class BTT {
private:
	node* left;
	node* right;
	node* temp, * temp2;
	node* n;
public:
	node* root;

	BTT()
	{
		n = new node;
		n->left = n->right = n;
		n->leftbit = n->rightbit = 1;
		root, left, right, temp, temp2 = NULL;
	}

	~BTT() {
	}

	void insert(node* temp, int key) {
		if (root == NULL)
		{
			root = new node;
			root->data = key;
			root->left = n;
			root->right = n;
			root->rightbit = 1;
			root->leftbit = 0;
			n->left = root;
			return;
		}

		if (key < temp->data)
		{
			if (temp->leftbit == 0)
			{
				temp2 = new node;
				temp2->data = key;
				n->left = root->left;
				root->left = n;
				n->leftbit = root->leftbit;
				root->leftbit = 1;
				n->right = root;
				return;
			}
			else
			{
				insert(temp->left, key);
			}
		}
		

		if (key > temp->data)
		{
			if (temp->rightbit == 0)
			{
				temp2 = new node;
				temp2->data = key;
				n->right = root->right;
				root->right = n;
				n->rightbit = root->rightbit;
				root->rightbit = 1;
				n->left = root;
				return;
			}
			else
			{
				insert(temp->right, key);
			}
		}
		
	}

};

int main()
{

	BTT obt;
	obt.insert(obt.root, 10);
	obt.insert(obt.root, 100);
	obt.insert(obt.root, 823);
	obt.insert(obt.root, 177);
	obt.insert(obt.root, 2);

	return 0;
}
