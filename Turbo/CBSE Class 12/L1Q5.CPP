/*
Program No. : L1Q5
Developed by: Om Gupta
Date        : 9 April 2019
*/

#include <iostream.h>
#include <conio.h>

const int MAX_C = 40;

void inputMatrix(int A[][MAX_C], int R, int C)
{
	cout << "Enter elements of each row separated by spaces." << endl;
	for (int i = 0; i < R; i++)
	{
		cout << "Row " << i + 1 << ": ";
		for (int j = 0; j < C; j++)
			cin >> A[i][j];
		cout << endl;
	}
}

void displayMatrix(int A[][MAX_C], int R, int C)
{
	cout << "Displaying contents." << endl;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void addMatrices(int A[][MAX_C], int B[][MAX_C], int K[][MAX_C], char mode,
				 int R, int C)
{
	int M = (mode == 's') ? (-1) : (1);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			K[i][j] = A[i][j] + M*B[i][j];
	}
}

void main()
{
	 clrscr();
	 int R, C;
	 cout << "Enter the number of rows of the matrices: "; cin >> R;
	 cout << "Enter the number of cols of the matrices: "; cin >> C;
	 int A[MAX_C][MAX_C], B[MAX_C][MAX_C], S[MAX_C][MAX_C], D[MAX_C][MAX_C];
	 cout << "Enter contents of first matrix." << endl;
	 inputMatrix(A, R, C);
	 cout << endl << "Enter contents of second matrix." << endl;
	 inputMatrix(B, R, C);
	 addMatrices(A, B, S, 'a', R, C);
	 cout << endl << "Sum of the two matrices: " << endl;
	 displayMatrix(S, R, C);
	 addMatrices(A, B, D, 's', R, C);
	 cout << endl << "Difference of the two matrices: " << endl;
	 displayMatrix(D, R, C);
	 getch();
}

/*
OUTPUT:

                                                                                
Enter contents of second matrix.                                                
Enter elements of each row separated by spaces.                                 
Row 1: 1 3 5                                                                    
                                                                                
Row 2: 3 3 5                                                                    
                                                                                
Row 3: 7                                                                        
1                                                                               
2                                                                               
                                                                                
                                                                                
Sum of the two matrices:                                                        
Displaying contents.                                                            
8 7 14                                                                          
12 12 12                                                                        
15 8 11                                                                         
                                                                                
Difference of the two matrices:
Displaying contents.
6 1 4
6 6 2
1 6 7
*/
