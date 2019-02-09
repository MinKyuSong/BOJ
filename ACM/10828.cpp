#include<iostream>
#include<cstring>

using namespace std;

typedef struct node
{
	int data;
	node *next;
	node *prev;
}Node;

struct Stack
{
	node *head;
	node *top;
	int size;
};

int main(void)
{
	int nTry;
	char command[6];

	cin >> nTry;

	Stack stack;
	stack.size = 0;
	stack.head = NULL;
	stack.top = NULL;

	while (nTry--)
	{
		cin >> command;
		if (strcmp(command, "push") == 0)
		{
			Node* newItem = new Node;
			cin >> newItem->data;
			newItem->next = NULL;
			newItem->prev = NULL;

			if (stack.size == 0)
				stack.head = newItem;
			else
				stack.top->next = newItem;

			newItem->prev = stack.top;
			stack.top = newItem;
			stack.size++;
		}
		else if (strcmp(command, "pop") == 0)
		{
			Node* temp = stack.top;
			if (stack.size == 0)
				cout << -1 << endl;
			else
			{
				cout << stack.top->data << endl;
				stack.top = stack.top->prev;
				delete temp;
				stack.size--;
			}
		}
		else if (strcmp(command, "size") == 0)
		{
			cout << stack.size << endl;
		}
		else if (strcmp(command, "empty") == 0)
		{
			if (stack.size)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}
		else if (strcmp(command, "top") == 0)
		{
			if (stack.size == 0)
				cout << -1 << endl;
			else
				cout << stack.top->data << endl;
		}

	}

	Node* delItem=stack.head;
	while (stack.size--)
	{
		Node* temp = delItem->next;
		delete delItem;
		delItem = temp;
	}
	return 0;
}