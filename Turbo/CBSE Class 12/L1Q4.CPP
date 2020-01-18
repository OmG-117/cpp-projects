/*
Program No. : L1Q4
Developed by: Om Gupta
Date        : 9 April 2019
*/

#include <iostream.h>
#include <conio.h>

void enter(int A[], int N)
{
    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++)
        cin >> A[i];
}

void display(int A[], int N)
{
    cout << "The contents of the array are: ";
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
}

void sortA(int A[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        int T = A[i];
        A[i] = A[min];
        A[min] = T;
    }
    cout << "Array has been sorted.\n";
}

void search(int A[], int N)
{
    int tgt, mid, lb = 0, ub = N - 1;
    cout << "Enter number to search for: "; cin >> tgt;
    while (lb < ub)
    {
        mid = (lb + ub)/2;
        if (A[mid] == tgt)
            break;
        else if (A[mid] < tgt)
            lb = mid + 1;
        else if (A[mid] > tgt)
            ub = mid - 1;
    }
    if (A[mid] == tgt)
        cout << "Number found at position " << mid + 1 << ".\n";
    else
        cout << "That number does not exist.\n";
}

void main()
{
    clrscr();
    int A[20], N;
    cout << "Enter number of elements: "; cin >> N;
    int opt, cont = 1;
    while (cont)
    {
        cout << "1. Enter | ";
        cout << "2. Display | ";
        cout << "3. Sort | ";
        cout << "4. Search | ";
        cout << "5. Exit\n";
        cout << "Enter your choice: "; cin >> opt;
        switch(opt)
        {
            case 1: enter(A, N);
                break;
            case 2: display(A, N);
                break;
            case 3: sortA(A, N);
                break;
            case 4: search(A, N);
                break;
            case 5: cont = 0;
        }
        cout << endl;
    }
}

/*
OUTPUT:
Enter number of elements: 6
1. Enter | 2. Display | 3. Sort | 4. Search | 5. Exit
Enter your choice: 1
Enter the elements: 1 5 3 44 13 12

1. Enter | 2. Display | 3. Sort | 4. Search | 5. Exit
Enter your choice: 3
Array has been sorted.

1. Enter | 2. Display | 3. Sort | 4. Search | 5. Exit
Enter your choice: 2
The contents of the array are: 1 3 5 12 13 44

1. Enter | 2. Display | 3. Sort | 4. Search | 5. Exit
Enter your choice: 4
Enter number to search for: 5
Number found at position 3.

1. Enter | 2. Display | 3. Sort | 4. Search | 5. Exit
Enter your choice: 5
*/
