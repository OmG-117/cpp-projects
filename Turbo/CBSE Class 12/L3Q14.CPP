/*
Program No. : L3Q14
Developed by: Om Gupta
Date        : 12 July 2019
*/

#include <iostream.h>
#include <conio.h>

struct Date
{
	int day;
	int month;
	int year;
};

int datecmp(Date d, int dd, int mm, int yyyy)
{
	if (d.day == dd && d.month == mm && d.year == yyyy)
		return 1;
	else
		return 0;
}

class Student
{
	int admno;
	char sname[20];
	Date dob;
public:
	void input()
	{
		cout << "Admission number: "; cin >> admno;
		cout << "Name: "; cin >> sname;
		cout << "Date of birth (DD MM YYYY): ";
		cin >> dob.day >> dob.month >> dob.year;
		cout << endl;
	}
	void show()
	{
		cout << "Admission number: " << admno << endl;
		cout << "Name: " << sname << endl;
		cout << "Date of birth: ";
		cout << dob.day << " " << dob.month << " " << dob.year << endl;
		cout << endl;
	}
	Date rdob() {return dob;}
};

int display(Student slist[], int N)
{
	int tgt;
	cout << "Enter student to display details of: "; cin >> tgt;
	for (int i = 0; i < N; i++)
	{
		if (i == tgt - 1)
		{
			cout << "Details of the student are as follows: " << endl;
			slist[i].show();
			return 1;
		}
	}
	return 0;
}

void displaySpecific(Student slist[], int N)
{
	for (int i = 0; i < N; i++)
	{
		if (   datecmp(slist[i].rdob(), 1, 1, 1990)
			|| datecmp(slist[i].rdob(), 2, 2, 1990)
			|| datecmp(slist[i].rdob(), 3, 3, 1990))
		{
			slist[i].show();
			return;
		}
	}
	cout << "No student with matching DOB found." << endl;
}

void input(Student slist[], int &N)
{
	cout << "Enter details for student " << N + 1 << ":\n";
	slist[N++].input();
}

void showMenu(Student slist[], int N)
{
    int opt, cont = 1;
	while (cont)
    {
		cout << "\nMENU\n";
		cout << "1. Display General | ";
		cout << "2. Display Specific | ";
        cout << "3. Input | ";
		cout << "4. Exit\n";
        cout << "Enter your choice: "; cin >> opt;
        switch(opt)
        {
            case 1: display(slist, N);
                break;
            case 2: displaySpecific(slist, N);
                break;
            case 3: input(slist, N);
                break;
            case 4: cont = 0;
        }
    }
}

void main()
{
	clrscr();
	int N = 0;
	Student slist[10];
	showMenu(slist, N);
}

/*
OUTPUT:

MENU
1. Display General | 2. Display Specific | 3. Input | 4. Exit
Enter your choice: 3
Enter details for student 1:
Admission number: 1
Name: Jon
Date of birth (DD MM YYYY): 12 5 1992


MENU
1. Display General | 2. Display Specific | 3. Input | 4. Exit
Enter your choice: 3
Enter details for student 2:
Admission number: 2
Name: Perry
Date of birth (DD MM YYYY): 1 1 1992


MENU
1. Display General | 2. Display Specific | 3. Input | 4. Exit
Enter your choice: 1
Enter student to display details of: 1
Details of the student are as follows:
Admission number: 1
Name: Jon
Date of birth: 12 5 1992


MENU
1. Display General | 2. Display Specific | 3. Input | 4. Exit
Enter your choice: 2
Admission number: 2
Name: Perry
Date of birth: 1 1 1990


MENU
1. Display General | 2. Display Specific | 3. Input | 4. Exit
Enter your choice: 4

*/
