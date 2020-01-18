/*
Program No. : L3Q15
Developed by: Om Gupta
Date        : 30 July 2019
*/

#include <fstream.h>
#include <conio.h>
#include <ctype.h>

void inText()
{
	ofstream f("Story.txt");
	char line[100], cont = 'y';
	while (tolower(cont) == 'y')
	{
		cout << "Enter a line: ";
		cin.getline(line, 100);
		f << line << endl;
		cout << "Continue? (Y)"; cont = getch();
		cout << endl << endl;
	}
	f.close();
}

void outText()
{
	ifstream f("Story.txt");
	char word[20];
	while(!f.eof())
	{
		f >> word;
		cout << word << " ";
	}
	f.close();
}

void main()
{
	 clrscr();
	 cout << "Enter the contents of Story.txt." << endl;
	 inText();
	 cout << "Displaying contents of the file word by word." << endl << endl;
	 outText();
	 getch();
}

/*
OUTPUT:
Enter the contents of Story.txt.
Enter a line: line number one
Continue? (Y)

Enter a line: line number two
Continue? (Y)

Displaying contents of the file word by word.

line number one line number two
*/
