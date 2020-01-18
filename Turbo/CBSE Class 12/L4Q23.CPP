/*
Program No. : L4Q23
Developed by: Om Gupta
Date        : 26 November 2019
*/

#include <iostream.h>
#include <conio.h>

struct Node
{
    double data;
	Node *next;
};

class Queue
{
	Node *r, *f;
public:
	Queue() {r = NULL; r = NULL;}
	void insert();
	void del();
	void display();
	~Queue();
};

void Queue::insert()
{
	Node *n = new Node;
	cout << "Enter value: "; cin >> n->data;
	n->next = NULL;
	if (r != NULL)
	{
		r->next = n;
		r = n;
	}
	else
	{
		r = n;
		f = n;
	}
}

void Queue::del()
{
	if (f != NULL)
	{
		Node *n = f;
		f = n->next;
		if (f == NULL)
			r = NULL;
		cout << n->data << " deleted." << endl;
		delete n;
	}
	else
		cout << "Queue is empty." << endl;
}

void Queue::display()
{
	cout << "Contents of Queue: ";
	Node *n = f;
	while (n != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

Queue::~Queue()
{
	while (f != NULL)
	{
		Node *n = f;
		f = n-> next;
		delete n;
	}
}

void main()
{
	 clrscr();
     Queue Q;
     int opt = 0;
     while (opt != 4)
     {
         cout << "(1. Insert | 2. Delete | 3. Display | 4. Exit): "; cin >> opt;
         switch (opt)
         {
             case 1: Q.insert();
                 break;
             case 2: Q.del();
                 break;
             case 3: Q.display();
                 break;
         }
         cout << endl;
     }
}

/*
OUTPUT:
(1. Insert | 2. Delete | 3. Display | 4. Exit): 1
Enter value: 6

(1. Insert | 2. Delete | 3. Display | 4. Exit): 1
Enter value: 4

(1. Insert | 2. Delete | 3. Display | 4. Exit): 1
Enter value: 7

(1. Insert | 2. Delete | 3. Display | 4. Exit): 3
Contents of Queue: 6 4 7

(1. Insert | 2. Delete | 3. Display | 4. Exit): 2
6 deleted.

(1. Insert | 2. Delete | 3. Display | 4. Exit): 3
Contents of Queue: 4 7

(1. Insert | 2. Delete | 3. Display | 4. Exit): 2
4 deleted.

(1. Insert | 2. Delete | 3. Display | 4. Exit): 2
7 deleted.

(1. Insert | 2. Delete | 3. Display | 4. Exit): 2
Queue is empty.

(1. Insert | 2. Delete | 3. Display | 4. Exit): 3
Contents of Queue:

(1. Insert | 2. Delete | 3. Display | 4. Exit): 4


*/
