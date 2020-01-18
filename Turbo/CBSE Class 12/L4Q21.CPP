/*
Program No. : L4Q21
Developed by: Om Gupta
Date        : 5 November 2019
*/

#include <iostream.h>
#include <conio.h>

const int size = 10;

struct Student
{
    int admno;
    char name[20];
};

void insert(Student Q[], int &r, int f)
{
    if ((r + 1) % size != f)
    {
        r = (r + 1) % size;
        cout << "Enter admission no: "; cin >> Q[r].admno;
        cout << "Enter name: "; cin >> Q[r].name;
    }
    else
        cout << "Queue is full." << endl;
}

void del(Student Q[], int r, int &f)
{
    if (r != f)
    {
        f = (f + 1) % size;
        cout << "Student " << Q[f].admno << " removed." << endl;
    }
    else
        cout << "Queue is empty." << endl;
}

void display(Student Q[], int r, int f)
{
    cout << "Contents of queue: " << endl;
    int i = f;
    while (i != r)
    {
        i = (i + 1) % size;
        cout << "Admission number: " << Q[i].admno << " | ";
        cout << "Name: " << Q[i].name << endl;
    }
}

void main()
{
	 clrscr();
     Student Q[size];
     int opt = 0, r = 0, f = 0;
     while (opt != 4)
     {
         cout << "(1. Insert | 2. Delete | 3. Display | 4. Exit): "; cin >> opt;
         switch (opt)
         {
             case 1: insert(Q, r, f);
                 break;
             case 2: del(Q, r, f);
                 break;
             case 3: display(Q, r, f);
                 break;
         }
         cout << endl;
     }
}

/*
OUTPUT:
(1. Insert | 2. Delete | 3. Display | 4. Exit): 1
Enter admission no: 1
Enter name: abc

(1. Insert | 2. Delete | 3. Display | 4. Exit): 1
Enter admission no: 2
Enter name: bcd

(1. Insert | 2. Delete | 3. Display | 4. Exit): 1
Enter admission no: 3
Enter name: cde

(1. Insert | 2. Delete | 3. Display | 4. Exit): 3
Contents of queue:
Admission number: 1 | Name: abc
Admission number: 2 | Name: bcd
Admission number: 3 | Name: cde

(1. Insert | 2. Delete | 3. Display | 4. Exit): 2
Student 1 removed.

(1. Insert | 2. Delete | 3. Display | 4. Exit): 3
Contents of queue:
Admission number: 2 | Name: bcd
Admission number: 3 | Name: cde

(1. Insert | 2. Delete | 3. Display | 4. Exit): 2
Student 2 removed.

(1. Insert | 2. Delete | 3. Display | 4. Exit): 2
Student 3 removed.

(1. Insert | 2. Delete | 3. Display | 4. Exit): 2
Queue is empty.

(1. Insert | 2. Delete | 3. Display | 4. Exit): 3
Contents of queue:

(1. Insert | 2. Delete | 3. Display | 4. Exit): 4


*/
