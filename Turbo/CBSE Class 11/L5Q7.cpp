#include <iostream.h>
#include <conio.h>
#include <string.h>

struct MEMBER
{
    int Mno;
    char Mname[20];
    float fee;
};

void swapStr(char val1[], char val2)
{
    char T[20];
    strcpy(T, val1);
    strcpy(val2, val1);
    strcpy(val1, T);
}

void input(MEMBER M[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Enter member number for member " << i + 1 << ": "; cin >> M[i].Mno;
        cout << "Enter member name for member " << i + 1 << ": "; cin >> M[i].Mname;
        cout << "Enter fee for member " << i + 1 << ": "; cin >> M[i].fee;
        cout << endl;
    }
}

void display(MEMBER M[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Member number of member " << i + 1 << ": " << M[i].Mno;
        cout << "Member name of member " << i + 1 << ": " << M[i].Mname;
        cout << "Fee of member " << i + 1 << ": " << M[i].fee;
    }
}

int SearchNo(MEMBER M[], int N, int val)
{
    for (int i = 0; i < N; i++)
    {
        if (M[i].Mno == val)
            return i;
    }
    return -1;
}

int SearchName(MEMBER M[], int N, char val[])
{
    for (int i = 0; i < N; i++)
    {
        if (strcmp(M[i].name, val) == 0)
            return i;
    }
    return -1;
}

void SortNo(MEMBER M[], int N)
{
    int min;
    for (int i = 0; i < N - 1; i++)
    {
        min = i
        for (int j = i + 1; j < N; j++)
        {
            if (M[j].Mno < M[min].Mno)
                min = j;
        }
        int T = M[i].Mno;
        M[i].Mno = M[min].Mno;
        M[min].Mno = T;
    }
}

void SortName(MEMBER M[], int N)
{
    int max;
    for (int i = 0; i < N - 1; i++)
    {
        max = i
        for (int j = i + 1; j < N; j++)
        {
            if (strcmp(M[j].Mname, M[max].Mname) > 0)
                max = j;
        }
        char T[20];
        strcpy(T, M[i].Mname);
        strcpy(M[i].Mname, M[max].Mname);
        strcpy(M[max].Mname, T);
    }
}

int SumFee(MEMBER M[], int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += M[i].fee;
    return sum;
}

void main()
{
    clrscr();
    MEMBER M1[10];
    int N, choice, sval;
    char sstr[20];

    while (1)
    {
        cout << endl;
        cout << "Select an option from the menu below: " << endl;
        cout << "1. Input data" << endl << "2. Display data" << endl;
        cout << "3. Search member number" << endl << "4. Search member name" << endl;
        cout << "5. Sort by member number" << endl << "6. Sort by member name" << endl;
        cout << "7. Get fee sum" << endl << "8. Exit" << endl;
        cout << "Your selection: "; cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            cout << "Enter desired number of entries: "; cin >> N;
            input(M1, N);
        }
        else if (choice == 2)
        {
            display(M1, N);
        }
        else if (choice == 3)
        {
            cout << "Enter number to be searched for: "; cin >> sval;
            sval = SearchNo(M1, N, sval);
            if (sval == -1)
                cout << "Value not found.";
            else
                cout << "Value found at position " << sval;
        }
        else if (choice == 4)
        {
            cout << "Enter name to be searched for: "; cin >> sstr;
            sval = SearchName(M1, N, sstr);
            if (sval == -1)
                cout << "Value not found.";
            else
                cout << "Value found at position " << sval;
        }
        else if (choice == 5)
        {
            sortNo(M1, N);
            cout << "Array sorted on basis of member number.";
        }
        else if (choice == 6)
        {
            SortName(M1, N);
            cout << "Array sorted on basis of member name.";
        }
        else if (choice == 7)
        {
            cout << "The sum of all fees is: " << SumFee(M1, N);
        }
        else if (choice == 8)
        {
            break;
        }
        else
        {
            cout << "Invalid input. Try again.";
        }
    }

    cout << "Press any key to exit. "; getch();
}
