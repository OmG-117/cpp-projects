/*
Program No. : L2Q8
Developed by: Om Gupta
Date        : 30 April 2019
*/

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <iomanip.h>

struct Book
{
	int Bno;
	char Bname[20], Author[20];
	float Price;

};

void Enter(int y, Book books[])
{
	 for(int i=0;i<y; i++)
	 {
		cout<<"Enter the book number: ";
		cin>>books[i].Bno;
		cout<<"Enter the book name: ";
		gets(books[i].Bname);
		cout<<"Enter the name of the author: ";
		gets(books[i].Author);
		cout<<"Enter the book price: ";
		cin>>books[i].Price;
	 }
}

void Display(int y, Book books[])
{
	for(int i=0;i<y; i++)
	 {
		cout<<"Book number: "<<books[i].Bno<<setw(5);
		cout<<"Book name: "<<books[i].Bname<<setw(5);
		cout<<"Name of the author: "<<books[i].Author<<setw(5);
		cout<<"Book price: "<<books[i].Price<<setw(5);
	 }
}

void nosearch(int y, Book books[])
{
	int no;
	cout<<"Enter the desired book's no.:"<<endl;
	cin>>no;
	for(int i=0; i<y; i++)
	{
		if( books[i].Bno == no)
		{
			cout<<"Found!"<<endl;
			cout<<"Entered book number: "<<books[i].Bno<<"Book name: "<<books[i].Bname<<endl;
			cout<<"Name of the author: "<<books[i].Author<<"Book price: "<<books[i].Price<<endl;
			i=y;
		}
		else
			cout<<"Book not found."<<endl;
	}
}

void namesearch(int y, Book books[])
{
	char name[32];
	cout<<"Enter the desired book's name:"<<endl;
	cin>>name;
	for(int i = 0 ; i < y; i++)
	{
		if( strcmp(name,books[i].Bname) == 0 )
		{
			cout<<"Found!"<<endl;
			cout<<"Entered the book name: "<<books[i].Bname<<endl;
			cout<<"Book number: "<<books[i].Bno<<endl;
			cout<<"Name of the author: "<<books[i].Author<<endl;
			cout<<"Book price: "<<books[i].Price<<endl;
			i=y;
		}
		else
			cout<<"Book not found."<<endl;
	}
}

int menu(int menu)
{
	int option=0;

	if(menu == 1)
	{
		cout<<"Choose one of the following(1/2/3/4):"<<endl;
		cout<<"(1: Enter )"<<setw(5)<<"(2: Display)"<<endl;
		cout<<"(3: Search number)"<<setw(5)<<"(4: Search name)"<<endl;
		cin>>option;
	}
 return option;
}

void main()
{
	clrscr();
	char opt;
	Book books[10];
	int X=0,Y=0,Z=0;
	do
	{
		if( Y==1 )
			Enter(Z, books);
		else if( Y==2 )
			Display(Z, books);
		else if( Y == 3 )
			nosearch(Z, books);
		else if( Y == 4 )
			namesearch(Z, books);
		cout<<"Continue? (Y/N)"<<endl;
		cin>>opt;
	}while( opt == 'Y' || opt == 'y' );
	getch();
}

/*OUTPUT
Choose one of the following(1/2/3/4):
(1: Enter )(2: Display)
(3: Search number)(4: Search name)
1
Enter the no. of books in the array:     2
Enter the book number: 1
Enter the book name: DBZ
Enter the name of the author: A. Toriyama
Enter the book price: 399
Enter the book number: 2
Enter the book name: DBSuper
Enter the name of the author: A. Toriyama
Enter the book price: 449
Continue? (Y/N)
y
Choose one of the following(1/2/3/4):
(1: Enter )(2: Display)
(3: Search number)(4: Search name)
2
Enter the no. of books in the array:     2
Book number: 1Book name: DBZName of the author: A. ToriyamaBook price: 399Book n
umber: 2Book name: DBSuperName of the author: A. ToriyamaBook price: 449Continue
?(Y/N)
y
Choose one of the following(1/2/3/4):
(1: Enter )(2: Display)
(3: Search number)(4: Search name)
3
Enter the no. of books in the array:     2
Enter the desired book's no.:
1
Found!
Entered book number: 1Book name: DBZ
Name of the author: A. ToriyamaBook price: 399
Continue? (Y/N)
y
Choose one of the following(1/2/3/4):
(1: Enter )(2: Display)
(3: Search number)(4: Search name)
4
Enter the no. of books in the array:     2
Enter the desired book's name:
DBZ
Found!
Entered the book name: DBZ
Book number: 1
Name of the author: A. Toriyama
Book price: 399
Continue? (Y/N)
n
*/