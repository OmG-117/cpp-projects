/*
Program No. : L2Q10
Developed by: Om Gupta
Date        : 8 May 2019
*/

#include <iostream.h>
#include <conio.h>
#include <iomanip.h>

struct Account
{
	int accno;
	char name[20];
	float balance;
};

void input(Account list[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "----------------------------------------\n";
		cout << "Enter account number: "; cin >> list[i].accno;
		cout << "Enter account name: "; cin >> list[i].name;
		cout << "Enter account balance: "; cin >> list[i].balance;
		cout << "----------------------------------------\n";
	}
}

void display(Account list[], int N)
{
	cout << "Account No. | Account Name | Account Balance\n";
	for (int i = 0; i < N; i++)
	{
		cout << setw(12) << list[i].accno; cout << "|";
		cout << setw(14) << list[i].name; cout << "|";
		cout << setw(16) << list[i].balance; cout << endl;
	}
}

void displayRich(Account list[], int N)
{
	cout << "Account No. | Account Name | Account Balance\n";
	for (int i = 0; i < N; i++)
	{
		if (list[i].balance > 100000)
		{
			cout << setw(12) << list[i].accno; cout << "|";
			cout << setw(14) << list[i].name; cout << "|";
			cout << setw(16) << list[i].balance; cout << endl;
		}
	}
}

void main()
{
	 clrscr();
	 Account list[20];
	 int N;
	 cout << "Enter number of accounts to input: "; cin >> N;
	 input(list, N);
	 cout << "\nDisplaying all accounts:\n";
	 display(list, N);
	 cout << "\nDisplaying accounts with balance >100000:\n";
	 displayRich(list, N);
	 getch();
}

/*
OUTPUT:
Enter number of accounts to input: 2
----------------------------------------
Enter account number: 1
Enter account name: abc
Enter account balance: 120000
----------------------------------------
----------------------------------------
Enter account number: 2
Enter account name: def
Enter account balance: 80000
----------------------------------------

Displaying all accounts:
Account No. | Account Name | Account Balance
		   1|           abc|          120000
		   2|           def|           80000

Displaying accounts with balance >100000:
Account No. | Account Name | Account Balance
		   1|           abc|          120000
*/
