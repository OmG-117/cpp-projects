/*
Program No. : L3Q13
Developed by: Om Gupta
Date        : 10 July 2019
*/

#include <iostream.h>
#include <conio.h>
#include <string.h>

class Book
{
	int bno;
	char bname[32];
	char author[32];
	float price;
public:
	void enter()
	{
		cout << "Enter book number: "; cin >> bno;
		cout << "Enter book name  : "; cin >> bname;
		cout << "Enter book author: "; cin >> author;
		cout << "Enter book price : "; cin >> price;
	}
	void display()
	{
		cout << "Book number: " << bno << endl;
		cout << "Book name  : " << bname << endl;
		cout << "Book author: " << author << endl;
		cout << "Book price : " << price << endl;
	}
	int rbno() {return bno;}
	char* rbname() {return bname;}
};

void enter(Book list[10], int &N)
{
	if (N < 10)
	{
		cout << "Enter data for book at position " << N + 1 << ".\n";
		list[N++].enter();
	}
	else
		cout << "Sorry, no more data can be entered.";
}

void display(Book list[10])
{
	int n;
	cout << "Enter the position at which to display: "; cin >> n;
	list[n - 1].display();
}

int searchbno(Book list[], int N)
{
	int tgt;
	cout << "Enter book number to search for: "; cin >> tgt;
	for (int i = 0; i < N; i++)
	{
		if (list[i].rbno() == tgt)
		{
			cout << "Book found.\n";
			list[i].display();
			return 1;
		}
	}
	cout << "No book with that number found.\n";
	return 0;
}

int searchbname(Book list[], int N)
{
	char tgt[32];
	cout << "Enter book name to search for: "; cin >> tgt;
	for (int i = 0; i < N; i++)
	{
		if (!strcmp(list[i].rbname(), tgt))
		{
			cout << "Book found.\n";
			list[i].display();
			return 1;
		}
	}
	cout << "No book with that name found.\n";
	return 0;
}

int menu(int option, Book list[], int &N)
{
	switch (option)
	{
		case 1:
		{
			enter(list, N);
			break;
		}
		case 2:
		{
			display(list);
			break;
		}
		case 3:
		{
			searchbno(list, N);
			break;
		}
		case 4:
		{
			searchbname(list, N);
			break;
		}
		case 5:
			return 1;
	}
	return 0;
}

void menu_controller()
{
	int N = 0, exit = 0;
	Book list[10];
	while (!exit)
	{
		int opt;
		cout << "1) Enter values\n2) Display values\n3) Search using number\n4) Search using name\n5) Exit\n";
		cout << "Enter your choice: "; cin >> opt;
		cout << endl;
		exit = menu(opt, list, N);
		cout << endl;
	}
}

void main()
{
	 clrscr();
	 menu_controller();
	 cout << "Press any key to exit...";
	 getch();
}

/*
OUTPUT:
1) Enter values
2) Display values
3) Search using number
4) Search using name
5) Exit
Enter your choice: 1

Enter data for book at position 1.
Enter book number: 54
Enter book name  : abc
Enter book author: jon
Enter book price : 119

1) Enter values
2) Display values
3) Search using number
4) Search using name
5) Exit
Enter your choice: 1

Enter data for book at position 2.
Enter book number: 48
Enter book name  : def
Enter book author: may
Enter book price : 169

1) Enter values
2) Display values
3) Search using number
4) Search using name
5) Exit
Enter your choice: 1

Enter data for book at position 3.
Enter book number: 42
Enter book name  : ghi
Enter book author: sam
Enter book price : 224

1) Enter values
2) Display values
3) Search using number
4) Search using name
5) Exit
Enter your choice: 3

Enter book number to search for: 48
Book found.
Book number: 48
Book name  : def
Book author: may
Book price : 169

1) Enter values
2) Display values
3) Search using number
4) Search using name
5) Exit
Enter your choice: 4

Enter book name to search for: ghi
Book found.
Book number: 40
Book name  : ghi
Book author: sam
Book price : 224

1) Enter values
2) Display values
3) Search using number
4) Search using name
5) Exit
Enter your choice: 5


Press any key to exit...
*/
