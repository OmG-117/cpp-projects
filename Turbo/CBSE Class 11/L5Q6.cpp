#include <iostream.h>
#include <conio.h>
#include <string.h>

void input(char CITY[][10], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Enter city " << i + 1 << ": "; gets(CITY[i]);
    }
}

int search(char CITY[][10], int N, char S[])
{
    for (int i = 0; i < N; i++)
    {
        if (strcmp(CITY[i], S) == 0)
            return i;
    }
    return -1;
}

void sort(char CITY[][10], int N)
{
    int min;
    for (int i = 0; i < N - 1; i++)
    {
        min = i
        for (int j = i + 1; j < N; j++)
        {
            if (strcmp(M[j].Mname, M[max].Mname) < 0)
                min = j;
        }
        char T[20];
        strcpy(T, CITY[i]);
        strcpy(CITY[i], CITY[max]);
        strcpy(CITY[max], T);
}

void main()
{
    clrscr();
    char CITY[20][10];
    int N;
    char S[20];

    cout << "Enter number of entries to be made: "; cin >> N;
    input(CITY, N);

    cout << endl << "Enter city to search for: "; gets(S);
    if (search(CITY, N, S) == -1)
        cout << "Value not found." << endl;
    else
        cout << "Value found at position " << search(CITY, N, S) + 1 << endl;

    cout << "Sorting array.";
    sort(CITY, N);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < N; i++)
    {
        puts(CITY[i]);
        cout << endl;
    }

    cout << "Press any key to exit. "; getch();
}
