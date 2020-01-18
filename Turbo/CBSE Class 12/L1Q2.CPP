/*
Program No. : L1Q3
Developed by: Om Gupta
Date        : 3 April 2019
*/

#include <iostream.h>
#include <conio.h>

int isPrime(char N[])
{
    int i, n = 0;
    for (i = 0; N[i] != '\0'; i++); i--;
    for (int mult = 1; i >= 0; i--, mult *= 10)
    {
        n += (N[i] - 48)*mult;
    }
    for (int k = 2; i < n; i++)
    {
        if (n % k == 0)
            return 0;
    }
    return 1;
}

int isPalindrome(char N[])
{
    int i, j;
    for (i = 0; N[i] != '\0'; i++); i--;
    for (j = 0; i >= 0; j++, i--)
    {
        if (N[j] != N[i])
            return 0;
    }
    return 1;
}

int sumIsEven(char N[])
{
    int sum = 0;
    for (int i = 0; N[i] != '\0'; i++)
        sum += N[i] - 48;
    if (sum % 2 == 0)
        return 1;
    else
        return 0;
}

void main()
{
    clrscr();
    int result, opt, cont = 1;
    char N[10];
    while (cont)
    {
        cout << "Enter a number: "; cin >> N;
        cout << "Choose condition to check: ";
        cout << "1. Prime | ";
        cout << "2. Palindrome | ";
        cout << "3. Has even sum of digits | ";
        cout << "4. Exit\n";
        cout << "Enter your choice: "; cin >> opt;
        switch(opt)
        {
            case 1: result = isPrime(N);
                break;
            case 2: result = isPalindrome(N);
                break;
            case 3: result = sumIsEven(N);
                break;
            case 4: cont = 0;
        }
        if (cont && result)
            cout << "The condition holds true.\n\n";
        else if (cont)
            cout << "The condition does not hold true.\n\n";
    }
}

/*
OUTPUT:
Enter a number: 7
Choose condition to check: 1. Prime | 2. Palindrome | 3. Has even sum of digits | 4. Exit
Enter your choice: 1
The condition holds true.

Enter a number: 747
Choose condition to check: 1. Prime | 2. Palindrome | 3. Has even sum of digits | 4. Exit
Enter your choice: 2
The condition holds true.

Enter a number: 55
Choose condition to check: 1. Prime | 2. Palindrome | 3. Has even sum of digits | 4. Exit
Enter your choice: 3
The condition holds true.

Enter a number: 0
Choose condition to check: 1. Prime | 2. Palindrome | 3. Has even sum of digits | 4. Exit
Enter your choice: 4
*/
