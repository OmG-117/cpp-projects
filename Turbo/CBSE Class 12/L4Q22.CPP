/*
Program No. : L4Q22
Developed by: Om Gupta
Date        : 10 November 2019
*/

#include <iostream.h>
#include <conio.h>

struct Book
{
    int bno;
    char bname[20];
	Book *next;
};

class Stack
{
	Book *top;
public:
	Stack() {top = NULL;}
	void push();
	void pop();
	void display();
	~Stack();
};

void Stack::push()
{
	Book *b = new Book;
	cout << "Enter book number: "; cin >> b->bno;
	cout << "Enter book name: "; cin >> b->bname;
	b->next = top;
	top = b;
}

void Stack::pop()
{
	if (top != NULL)
	{
		Book *b = top;
		top = b->next;
		cout << "Book " << b->bno << " deleted." << endl;
		delete b;
	}
	else
		cout << "Stack is empty." << endl;
}

void Stack::display()
{
	cout << "Contents of stack: " << endl;
	Book *b = top;
	while (b != NULL)
	{
		cout << "Number: " << b->bno << " | ";
		cout << "Name: " << b->bname << endl;
		b = b->next;
	}
}

Stack::~Stack()
{
	while (top != NULL)
	{
		Book *b = top;
		top = b-> next;
		delete b;
	}
}

void main()
{
	 clrscr();
     Stack S;
     int opt = 0;
     while (opt != 4)
     {
         cout << "(1. Push | 2. Pop | 3. Display | 4. Exit): "; cin >> opt;
         switch (opt)
         {
             case 1: S.push();
                 break;
             case 2: S.pop();
                 break;
             case 3: S.display();
                 break;
         }
         cout << endl;
     }
}

/*
OUTPUT:
(1. Push | 2. Pop | 3. Display | 4. Exit): 1
Enter book number: 1
Enter book name: b1

(1. Push | 2. Pop | 3. Display | 4. Exit): 1
Enter book number: 2
Enter book name: b2

(1. Push | 2. Pop | 3. Display | 4. Exit): 1
Enter book number: 3
Enter book name: b3

(1. Push | 2. Pop | 3. Display | 4. Exit): 3
Contents of stack:
Number: 3 | Name: b3
Number: 2 | Name: b2
Number: 1 | Name: b1

(1. Push | 2. Pop | 3. Display | 4. Exit): 2
Book 3 deleted.

(1. Push | 2. Pop | 3. Display | 4. Exit): 3
Contents of stack:
Number: 2 | Name: b2
Number: 1 | Name: b1

(1. Push | 2. Pop | 3. Display | 4. Exit): 2
Book 2 deleted.

(1. Push | 2. Pop | 3. Display | 4. Exit): 2
Book 1 deleted.

(1. Push | 2. Pop | 3. Display | 4. Exit): 2
Stack is empty.

(1. Push | 2. Pop | 3. Display | 4. Exit): 3
Contents of stack:


(1. Push | 2. Pop | 3. Display | 4. Exit): 4


*/
