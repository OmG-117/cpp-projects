/*
Program No. : L2Q9
Developed by: Om Gupta
Date        : 1 May 2019
*/

#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <stdio.h>

struct CANDIDATE
{
	int Cno, score;
	char Cname[20];
}trainees[15];

void Enter(int y, CANDIDATE trainees[])
{
	 for(int i=0;i<y; i++)
	 {
		cout<<"----------------------------------------\n";
		cout<<"Enter the candidate number: \n";
		cin>>trainees[i].Cno;
		cout<<"Enter the candidate name: \n";
		gets(trainees[i].Cname);
		cout<<"Enter the candidate score: \n";
		cin>>trainees[i].score;
		cout<<"----------------------------------------\n";
	 }

}

void Display(int y, CANDIDATE trainees[])
{
	for(int i=0;i<y; i++)
	 {
		cout<<"----------------------------------------\n";
		cout<<"Candidate number: "<<trainees[i].Cno<<endl;
		cout<<"Candidate name:   "<<trainees[i].Cname<<endl;
		cout<<"Candidate score   "<<trainees[i].score<<endl;
		cout<<"----------------------------------------\n";
	 }
}

void Sort(int y, CANDIDATE trainees[])
{
	CANDIDATE T;
	for(int i=0; i<y; i++)
	{
		for(int j=0; j<y-i-1; j++)
		{
			if(trainees[j].score > trainees[j+1].score)
			{
				T = trainees[j];
				trainees[j] = trainees[j+1];
				trainees[j+1]= T;
			}
		}
	}
	cout<<endl<<"The sorted array is:"<<endl;

	Display(y, trainees);
}
int menu(int menu)
{
	int option=0;

	if(menu == 1)
	{
		cout<<"Choose one of the following(1/2/3):\n";
		cout<<"(1: Enter )\n";
		cout<<"(2: Display)\n";
		cout<<"(3: Sort using the Score)\n";
		cin>>option;
	}

 return option;
}

void main()
{
	clrscr();

	char opt;
	int X=0,Y=0,Z=0;
	cout<<"If you wanna start the menu, enter 1"<<endl;
	cin>>X;
	cout<<"Enter the no. of candidates: ";
	cin>>Z;

	do
	{
		if( X == 1 )
		{
			Y=menu(X);
		}

		else
		{
			cout<<"Program ended"<<endl;
		}

		if( Y==1 )
		{
			Enter(Z, trainees);
		}

		else if( Y==2 )
		{
			Display(Z, trainees);
		}

		else if( Y == 3 )
		{
			Sort(Z, trainees);
		}

		cout<<"Continue? (Y/N)"<<endl;
		cin>>opt;
	}while( opt == 'Y' || opt == 'y' );

	getch();
}

/*
OUTPUT:
Enter the no. of candidates: 2
Choose one of the following(1/2/3):
(1: Enter )
(2: Display)
(3: Sort using the Score)
1
----------------------------------------
Enter the candidate number:
911
Enter the candidate name:
Nonamae
Enter the candidate score:
98
----------------------------------------
----------------------------------------
Enter the candidate number:
912
Enter the candidate name:
Onenamae
Enter the candidate score:
96
----------------------------------------
Continue? (Y/N)
y

Choose one of the following(1/2/3):
(1: Enter )
(2: Display)
(3: Sort using the Score)
3

The sorted array is:
----------------------------------------
Candidate number: 912
Candidate name:   Onenamae
Candidate score   96
----------------------------------------
----------------------------------------
Candidate number: 911
Candidate name:   Nonamae
Candidate score   98
----------------------------------------
Continue? (Y/N)
n
*/
