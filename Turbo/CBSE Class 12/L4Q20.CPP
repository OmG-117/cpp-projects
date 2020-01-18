/*
Program No. : L4Q20
Developed by: Om Gupta
Date        : 5 November 2019
*/

#include <iostream.h>
#include <conio.h>

const int size = 10;

void push(int S[], int &top)
{
    if (top < size - 1)
    {
        top++;
        cout << "Enter data: "; cin >> S[top];
    }
    else
        cout << "Stack is full." << endl;
}

void pop(int S[], int &top)
{
    if (top != -1)
    {
        cout << S[top] << " deleted." << endl;
        top--;
    }
    else
        cout << "Stack is empty." << endl;
}

void display(int S[], int top)
{
    cout << "Contents of stack: ";
    for (int i = top; i >= 0; i--)
        cout << S[i] << " ";
    cout << endl;
}

void main()
{
    clrscr();
    int S[size], opt = 0, top = -1;
    while (opt != 4)
    {
        cout << "(1. Push | 2. Pop | 3. Display | 4. Exit): "; cin >> opt;
        switch (opt)
        {
            case 1: push(S, top);
                break;
            case 2: pop(S, top);
                break;
            case 3: display(S, top);
                break;
        }
        cout << endl;
    }
}

/*
OUTPUT:
(1. Push | 2. Pop | 3. Display | 4. Exit): 1
Enter data: 3

(1. Push | 2. Pop | 3. Display | 4. Exit): 1
Enter data: 6

(1. Push | 2. Pop | 3. Display | 4. Exit): 1
Enter data: 7

(1. Push | 2. Pop | 3. Display | 4. Exit): 3
Contents of stack: 7 6 3

(1. Push | 2. Pop | 3. Display | 4. Exit): 2
7 deleted.

(1. Push | 2. Pop | 3. Display | 4. Exit): 3
Contents of stack: 6 3

(1. Push | 2. Pop | 3. Display | 4. Exit): 2
6 deleted.

(1. Push | 2. Pop | 3. Display | 4. Exit): 2
3 deleted.

(1. Push | 2. Pop | 3. Display | 4. Exit): 2
Stack is empty.

(1. Push | 2. Pop | 3. Display | 4. Exit): 3
Contents of stack:

(1. Push | 2. Pop | 3. Display | 4. Exit): 4


*/
