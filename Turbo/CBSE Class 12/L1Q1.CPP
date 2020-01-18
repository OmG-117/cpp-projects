/*
Program No. : L1Q1
Developed by: Om Gupta
Date        : 26 March 2019
*/

#include <iostream.h>
#include <conio.h>

float series1(float X, int N)
{
    float term, sum = 0;
    for (int i = 1; i <= N; i++)
    {
		term = 1;
		for (int j = 1; j <= i; j++)
			 term *= X;
		sum += term;
    }
    return sum;
}

float series2(float U, int N)
{
    float power, factorial, sum = 0;
    for (int i = 1; i <= N; i++)
    {
		power = 1; factorial = 1;
		for (int j = 1; j <= i; j++)
			power *= U;
		for (int k = 1; k <= i; k++)
			factorial *= k;
		sum += power/factorial;
    }
    return sum;
}

int series3(int N)
{
    int acc, sum = 0;
    for (int i = 1; i <= N; i++)
    {
		acc = 0;
		for (int j = 2; j <= 2*i; j += 2)
			acc += j;
		sum += acc;
    }
    return sum;
}

void main()
{
    clrscr();
    int choice, N;
    float result;
    while (1)
    {
		cout << "Enter series to calculate sum of:" << endl;
		cout << "1. X + X^2 + X^3 + ... + X^N" << endl;
		cout << "2. U + U^2/2! + U^3/3! + ... + U^N/N!" << endl;
		cout << "3. 2 + (2 + 4) + (2 + 4 + 6) + ... + (2 + 4 + 6 + ... + 2*N)" << endl;
		cout << "Enter your choice (1/2/3): "; cin >> choice;
		cout << "Enter the value of N: "; cin >> N;
		if (choice == 1)
		{
			float X;
			cout << "Enter the value of X: "; cin >> X;
			result = series1(X, N);
			break;
		}
		else if (choice == 2)
		{
			float U;
			cout << "Enter the value of U: "; cin >> U;
			result = series2(U, N);
			break;
		}
		else if (choice == 3)
		{
			result = series3(N);
			break;
		}
		else
			cout << "Invalid choice." << endl;
    }
    cout << endl << "The sum of the series is " << result;
    getch();
}

/*
OUTPUT:
Enter series to calculate sum of:
1. X + X^2 + X^3 + ... + X^N
2. U + U^2/2! + U^3/3! + ... + U^N/N!
3. 2 + (2 + 4) + (2 + 4 + 6) + ... + (2 + 4 + 6 + ... + 2*N)
Enter your choice (1/2/3): 1
Enter the value of N: 5
Enter the value of X: 2

The sum of the series is 62

Enter series to calculate sum of:
1. X + X^2 + X^3 + ... + X^N
2. U + U^2/2! + U^3/3! + ... + U^N/N!
3. 2 + (2 + 4) + (2 + 4 + 6) + ... + (2 + 4 + 6 + ... + 2*N)
Enter your choice (1/2/3): 2
Enter the value of N: 3
Enter the value of U: 2

The sum of the series is 5.333333

Enter series to calculate sum of:
1. X + X^2 + X^3 + ... + X^N
2. U + U^2/2! + U^3/3! + ... + U^N/N!
3. 2 + (2 + 4) + (2 + 4 + 6) + ... + (2 + 4 + 6 + ... + 2*N)
Enter your choice (1/2/3): 3
Enter the value of N: 3

The sum of the series is 20
*/