/*
Program No. : L1Q6
Developed by: Om Gupta
Date        : 10 April 2019
*/

#include <iostream.h>
#include <conio.h>
#include <ctype.h>

void displayTypes(char str[])
{
	 int count_vowels = 0, count_cons = 0, count_digits = 0;
	 for (int i = 0; str[i] != '\0'; i++)
	 {
		  char C = tolower(str[i]);
		  if (C == 'a' || C == 'e' || C == 'i' || C == 'o' || C == 'u')
				count_vowels++;
		  else if (C >= '0' && C <= '9')
				count_digits++;
		  else if (C >= 'a' && C <= 'z')
				count_cons++;
	 }
	 cout << "Number of vowels: " << count_vowels << endl;
	 cout << "Number of consonants: " << count_cons << endl;
	 cout << "Number of digits: " << count_digits << endl;
}

void displayReverse(char str[])
{
	 int i;
	 for (i = 0; str[i] != '\0'; i++);
	 for (i--; i >= 0; i--)
		  cout << str[i];
}

void main()
{
	 clrscr();
	 char str[40];
	 cout << "Enter a string: "; cin.getline(str, 40);
	 cout << endl;
	 displayTypes(str);
	 cout << endl << "Reverse of the string: "; displayReverse(str);
	 getch();
}

/*
OUTPUT:
Enter a string: 8 vowels, 17 consonants and 4 digits

Number of vowels: 8
Number of consonants: 17
Number of digits: 4

Reverse of the string: stigid 4 dna stnanosnoc 71 ,slewov 8
*/
