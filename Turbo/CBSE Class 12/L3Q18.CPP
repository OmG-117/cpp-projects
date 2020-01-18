/*
Program No. : L3Q18
Developed by: Om Gupta
Date        : 31 July 2019
*/

#include <fstream.h>
#include <conio.h>
#include <ctype.h>

class Candidate
{
	int cno, score;
	char cname[20];
public:
	void enter()
	{
		cout << "Enter candidate number: "; cin >> cno;
		cout << "Enter candidate name: "; cin >> cname;
		cout << "Enter candidate score: "; cin >> score;
	}
	void display()
	{
		cout << "Candidate number: " << cno << endl;
		cout << "Candidate name: " << cname << endl;
		cout << "Candidate score: " << score << endl;
	}
	int rscore() {return score;}
};

void enroll()
{
	ofstream f("Candidates.dat", ios::binary);
	cout << "Enter details of candidates: ";
	Candidate c;
	char cont = 'y';
	while (tolower(cont) == 'y')
	{
		cout << endl;
		c.enter();
		f.write((char*)&c, sizeof(Candidate));
		cout << "Candidate recorded. More? (Y): "; cin >> cont;
	}
	cout << endl;
	f.close();
}

void getPass()
{
	ifstream f("Candidates.dat", ios::binary);
	cout << "Display details of pass candidates: ";
	Candidate c;
	while (!f.eof())
	{
		f.read((char*)&c, sizeof(Candidate));
		if (c.rscore() >= 33)
		{
			cout << endl;
			c.display();
		}
	}
	f.close();
}

void main()
{
	 clrscr();
	 enroll();
	 cout << endl;
	 getPass();
	 getch();
}

/*
OUTPUT:
Enter details of candidates:
Enter candidate number: 1
Enter candidate name: jon
Enter candidate score: 72
Candidate recorded. More? (Y): y

Enter candidate number: 2
Enter candidate name: rob
Enter candidate score: 44
Candidate recorded. More? (Y): y

Enter candidate number: 3
Enter candidate name: sam
Enter candidate score: 31
Candidate recorded. More? (Y): n


Display details of pass candidates:
Candidate number: 1
Candidate name: jon
Candidate score: 72

Candidate number: 2
Candidate name: rob
Candidate score: 44
*/
