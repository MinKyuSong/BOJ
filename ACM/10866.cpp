#include<iostream>
#include<cstring>

using namespace std;

typedef struct node
{
	int data;
	node *next;
	node *prev;
}Node;

struct DEQueue
{
	node *front;
	node *end;
	int size;
};

int main(void)
{
	int nTry;
	char command[11];

	cin >> nTry;

	DEQueue queue;
	queue.size = 0;
	queue.front = NULL;
	queue.end = NULL;

	while (nTry--)
	{
		cin >> command;
		if (strcmp(command, "push_front") == 0)
		{
			Node* newItem = new Node;
			cin >> newItem->data;
			newItem->next = NULL;
			newItem->prev = NULL;

			if (queue.size == 0)
				queue.end = newItem;
			else
				queue.front->prev = newItem;

			newItem->next = queue.front;
			queue.front = newItem;
			queue.size++;
		}
		else if (strcmp(command, "push_back") == 0)
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
		else if (strcmp(command, "pop_front") == 0)
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
		else if (strcmp(command, "pop_back") == 0)
		{
			Node* temp = queue.end;
			if (queue.size == 0)
				cout << -1 << endl;
			else
			{
				cout << queue.end->data << endl;
				queue.end = queue.end->prev;
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