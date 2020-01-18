#include <iostream.h>
#include <conio.h>
#include <string.h>

void insert(char STR[], char NEW[], char RESULT[], int N)
{
    for (int i = 0, k = 0; STR[i] != '\0'; i++, k++)
    {
        RESULT[k] = STR[i];
        if (i == N - 1)
        {
            for (int j = 0; NEW[j] != '\0'; j++, k++)
                RESULT[k] = NEW[j];
        }
    }
    RESULT[k] = '\0';
}

void main()
{
    clrscr();
    char STR[20], NEW[20], RESULT[40];
    int N;

    cout << "Input main string: "; gets(STR);
    cout << "Input string to be added: "; gets(NEW);
    cout << "Input position to add string to: "; cin >> N;

    insert(STR, NEW, RESULT, N);
    cout << endl;

    cout << "Resulting string: "; puts(RESULT);
    getch();
}
