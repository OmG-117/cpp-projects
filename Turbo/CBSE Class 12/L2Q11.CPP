/*
Program No. : L2Q11
Developed by: Om Gupta
Date        : 2 July 2019
*/

#include <iostream.h>
#include <conio.h>

struct Flight
{
	int Flno;
	char DepTime[20];
	char ArrTime[20];
	float Fare;
};

void input(Flight list[], int N)
{
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "Enter details for flight " << i + 1 << ": " << endl;
		cout << "Flight number: "; cin >> list[i].Flno;
		cout << "Departure time: "; cin >> list[i].DepTime;
		cout << "Arrival time: "; cin >> list[i].ArrTime;
		cout << "Fare: "; cin >> list[i].Fare;
		cout << "----------------------------------------" << endl;
	}
}

void display(Flight list[], int N)
{
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "Flight number: " << list[i].Flno << endl;
		cout << "Departure time: " << list[i].DepTime << endl;
		cout << "Arrival time: " << list[i].ArrTime << endl;
		cout << "Fare: " << list[i].Fare << endl;
		cout << "----------------------------------------" << endl;
	}
}

int min_fare(Flight list[], int N)
{
	int min = 0;
	for (int i = 1; i < N; i++)
	{
		if (list[i].Fare < list[min].Fare)
			min = i;
	}
	return list[min].Flno;
}

void main()
{
	 clrscr();
	 Flight list[10];
	 int N;
	 cout << "Input number of flights to be entered: "; cin >> N;
	 input(list, N);
	 cout << endl << "Displaying flight information: " << endl;
	 display(list, N);
	 cout << endl << "Flight with lowest fare: " << min_fare(list, N);
	 getch();
}

/*
OUTPUT:
Input number of flights to be entered:
----------------------------------------
Enter details for flight 1:
Flight number: 77
Departure time: 19:30
Arrival time: 22:00
Fare: 4500
----------------------------------------
Enter details for flight 2:
Flight number: 32
Departure time: 9:00
Arrival time: 11:15
Fare: 5260
----------------------------------------
Enter details for flight 3:
Flight number: 54
Departure time: 13:00
Arrival time: 15:30
Fare: 4250
----------------------------------------

Displaying flight information:
----------------------------------------
Flight number: 77
Departure time: 19:30
Arrival time: 22:00
Fare: 4500
----------------------------------------
Flight number: 32
Departure time: 9:00
Arrival time: 11:15
Fare: 5260
----------------------------------------
Flight number: 54
Departure time: 13:00
Arrival time: 15:30
Fare: 4250
----------------------------------------

Flight with lowest fare: 54
*/
