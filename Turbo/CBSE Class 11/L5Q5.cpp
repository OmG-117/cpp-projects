#include <iostream.h>
#include <conio.h>
#include <string.h>

void split(char STR[], char ONE[], char TWO[])
{
    for (int i = 0; STR[i] != '\0'; i++)
    {
        if (i % 2 == 0)
            ONE[i/2] = STR[i];
        else
            TWO[i/2] = STR[i];
    }
}

void main()
{
    clrscr();
    char STR[20], ONE[10], TWO[10];

    cout << "Enter string: "; gets(STR);
    split(STR, ONE, TWO);
    cout << endl;
    cout << "Contents of ONE: "; puts(ONE);
    cout << "Contents of TWO: "; puts(TWO);

    getch();
}
