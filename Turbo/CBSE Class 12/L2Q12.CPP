/*
Program No. : L2Q12
Developed by: Om Gupta
Date        : 3 July 2019
*/

#include <iostream.h>
#include <conio.h>

struct Date
{
	int day;
	int month;
	int year;
};

struct Student
{
	int admno;
	char sname[20];
	Date dob;
};

void input(Student slist[], int N)
{
	cout << "Enter details of the students: " << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "Student " << i + 1 << ": " << endl;
		cout << "Admission number: "; cin >> slist[i].admno;
		cout << "Name: "; cin >> slist[i].sname;
		cout << "Date of birth (DD MM YYYY): ";
		cin >> slist[i].dob.day >> slist[i].dob.month >> slist[i].dob.year;
		cout << "----------------------------------------" << endl;
	}
}


int display(Student slist[], int N, int admno)
{
	for (int i = 0; i < N; i++)
	{
		if (slist[i].admno == admno)
		{
			cout << "Details of the student are as follows: " << endl;
			cout << "----------------------------------------" << endl;
			cout << "Admission number: " << slist[i].admno << endl;
			cout << "Name: " << slist[i].sname << endl;
			cout << "Date of birth: ";
			cout << slist[i].dob.day << " " << slist[i].dob.month << " " << slist[i].dob.year << endl;
			return 1;
		}
	}
	return 0;
}


void main()
{
	clrscr();
	Student slist[10];
	int N;
	cout << "Enter the number of students to input: "; cin >> N;
	cout << "Input the students:\n";
	input(slist, N);
	int admno;
	cout << "Enter Admission No. to enter info about: "; cin >> admno;
	int success = display(slist, N, admno);
	if (!success)
		cout << "No student with that admission number found.";
	getch();
}
/*
OUTPUT:
Enter details of the students:
----------------------------------------
Student 1:
Admission number: 1969
Name: David
Date of birth (DD MM YYYY): 26 11 1999
----------------------------------------
Student 2:
Admission number: 1420
Name: Chad
Date of birth (DD MM YYYY): 13 11 2001
----------------------------------------
Student 3:
Admission number: 1911
Name: Henry
Date of birth (DD MM YYYY): 21 12 1999
----------------------------------------
Enter Admission No. to enter info about: 1911
Details of the student are as follows:
----------------------------------------
Admission number: 1911
Name: Henry
Date of birth: 21 12 1999
*/
