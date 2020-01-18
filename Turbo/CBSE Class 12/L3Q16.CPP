/*
Program No. : L3Q16
Developed by: Om Gupta
Date        : 30 July 2019
*/

#include <fstream.h>
#include <conio.h>
#include <ctype.h>

void countAVD()
{
	ifstream f("Story.txt");
	int v = 0, a = 0, d = 0;
	char ch;
	while (!f.eof())
	{
		ch = tolower(f.get());
		if (isalpha(ch))
			a++;
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			v++;
		if (isdigit(ch))
			d++;
	}
	cout << "Alphabets: " << a << endl;
	cout << "Vowels: " << v << endl;
	cout << "Digits: " << d << endl;
	f.close();
}

void main()
{
	 clrscr();
	 cout << "Checking content of Story.txt..." << endl;
	 countAVD();
	 getch();
}

/*
STORY.TXT:
line number 1
line number 2
line number 3

OUTPUT:
Checking content of Story.txt...
Alphabets: 30
Vowels: 12
Digits: 3
/*e
