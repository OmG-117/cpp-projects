/*
Program No. : L3Q17
Developed by: Om Gupta
Date        : 30 July 2019
*/

#include <fstream.h>
#include <conio.h>

void revText()
{
	ifstream f("Story.txt");
	char line[100];
	while (!f.eof())
	{
		f.getline(line, 100);
		if (line[0] == 'T')
		{
			for (int i = 0; line[i] != '\0'; i++);
			for (i--; i >= 0; i--)
				cout << line[i];
			cout << endl;
		}
	}
	f.close();
}

void main()
{
	 clrscr();
	 cout << "Displaying modified contents of Story.txt." << endl << endl;
	 revText();
	 cout << endl << "Done.";
	 getch();
}

/*
STORY.TXT:
This is line 1
This is line 2
Line 3 doesn't start with a T

OUTPUT:
Displaying modified contents of Story.txt.

1 enil si sihT
2 enil si sihT

Done.
*/
