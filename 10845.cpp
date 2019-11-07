#include<iostream>
#include<cstring>

using namespace std;

typedef struct node
{
	int data;
	node *next;
	node *prev;
}Node;

struct Queue
{
	node *front;
	node *end;
	int size;
};

int main(void)
{
	int nTry;
	char command[6];

	cin >> nTry;

	Queue queue;
	queue.size = 0;
	queue.front = NULL;
	queue.end = NULL;

	while (nTry--)
	{
		cin >> command;
		if (strcmp(command, "push") == 0)
		{
			Node* newItem = new Node;
			cin >> newItem->data;
			newItem->next = NULL;
			newItem->prev = NULL;

			if (queue.size == 0)
				queue.front = newItem;
			else
				queue.end->next = newItem;

			newItem->prev = queue.end;
			queue.end = newItem;
			queue.size++;
		}
		else if (strcmp(command, "pop") == 0)
		{
			Node* temp = queue.front;
			if (queue.size == 0)
				cout << -1 << endl;
			else
			{
				cout << queue.front->data << endl;
				queue.front = queue.front->next;
				delete temp;
				queue.size--;
			}
		}
		else if (strcmp(command, "size") == 0)
		{
			cout << queue.size << endl;
		}
		else if (strcmp(command, "empty") == 0)
		{
			if (queue.size)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}
		else if (strcmp(command, "back") == 0)
		{
			if (queue.size == 0)
				cout << -1 << endl;
			else
				cout << queue.end->data << endl;
		}
		else if (strcmp(command, "front") == 0)
		{
			if (queue.size == 0)
				cout << -1 << endl;
			else
				cout << queue.front->data << endl;
		}
	}

	Node* delItem = queue.front;
	while (queue.size--)
	{
		Node* temp = delItem->next;
		delete delItem;
		delItem = temp;
	}
	return 0;
}