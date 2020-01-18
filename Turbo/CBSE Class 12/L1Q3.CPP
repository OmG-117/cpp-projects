/*
Program No. : L1Q3
Developed by: Om Gupta
Date        : 3 April 2019
*/

#include <iostream.h>
#include <conio.h>

void input(float A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << i + 1 << ": ";
		cin >> A[i];
	}
}

void display(float A[], int N)
{
	for (int i = 0; i < N; i++)
		cout << A[i] << ", ";
}

void sort(float A[], int N)
{
	for (int i = 1; i < N - 1; i++)
	{
		float here = A[i];
		int j = i - 1;
		while (here < A[j] && j >= 0)
		{
			float T = A[j];
			A[j] = A[j+1];
			A[j+1] = T;
			--j;
		}
	}
}

int search(float A[], int N, float tgt)
{
	for (int i = 0; i < N; i++)
	{
		if (A[i] == tgt)
			return i;
	}
	return -1;
}

void main()
{
	clrscr();
	int N;
	cout << "Enter desired length of array: "; cin >> N;
	float A[40];
	cout << "Enter elements of array." << endl;
	input(A, N);
	sort(A, N);
	cout << "Sorted array: ";
	display(A, N);
	float tgt;
	cout << endl << endl;
	cout << "Enter value to search for: "; cin >> tgt;
	int index = search(A, N, tgt);
	if (index == -1)
		cout << "Value not found.";
	else
		cout << "Value found at position " << index + 1 << ".";
	getch();
}

/*
OUTPUT:
Enter desired length of array: 6
Enter elements of array.
1: 24.72
2: 52.1
3: 12.3
4: 9.11
5: 42.0
6: 90.5
Sorted array: 9.11, 12.3, 24.719999, 42, 52.099998, 90.5,

Enter value to search for: 12.3
Value found at position 2.
*/
