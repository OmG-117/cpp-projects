Program 17

/*
Program Number    :    17
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>
void main()
{
    clrscr();
    int a, b, c, d, e, marks, N;

    cout << "Enter number of marks to input: "; cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cout << "Marks " << i << ": "; cin >> marks;
        if (marks <= 100 && marks > 90)
        {
            cout << "A" << endl;
            a++;
        }
        else if (marks <= 90 && marks > 70)
        {
            cout << "B" << endl;
            b++;
        }
        else if (marks <= 70 && marks > 50)
        {
            cout << "C" << endl;
            c++;
        }
        else if (marks <= 50 && marks > 32)
        {
            cout << "D" << endl;
            d++;
        }
        else if (marks <= 32 && marks > 0)
        {
            cout << "E" <<endl;
            e++;
        }
    }
    cout << "No. of students who got A:" << endl << a << endl;
    cout << "No. of students who got B:" << endl << b << endl;
    cout << "No. of students who got C:" << endl << c << endl;
    cout << "No. of students who got D:" << endl << d << endl;
    cout << "No. of students who got E:" << endl << e << endl;
    getch();
}

Program 18

/*
Program Number    :    18
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    int n, i, c = 0;
    cout << "Enter any number n: "; cin >> n;

    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
           c++;
        }
    }
    if (c == 2)
    {
        cout << "n is a Prime number" << endl;
    }
    else
    {
        cout << "n is not a Prime number" << endl;
    }
    getch();
}

Program 19

/*
Program Number    :    19
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    int N, M, X;
    cin >> M >> N;

    if (M > N)
    {
        X = M;
    }
    else if(N > M)
    {
        X = N;
    }

    int i = 1;
    while(i <= X)
    {
        if(N % i == 0 && M % i == 0)
        {
            cout << "The common factor is: " << i;
        }
    }
    getch();
}

Program 20

/*
Program Number    :    20
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    int N, M, max;


    cout << "Enter two numbers: ";
    cin >> N >> M;

    max = (N > M) ? N : M;

    while (1)
    {
        if (max % N == 0 && max % M == 0)
        {
            cout << "LCM = " << max;
            break;
        }
        else
            max++;
    }
    getch();
}

Program 21

/*
Program Number    :    21
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    int a, b, t, hcf, lcm;

    cout << "Enter two numbers: "; cin >> a >> b;

    while(b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    hcf = a;
    lcm = (x*y)/hcf;

    cout << "HCF = " << hcf << endl;
    cout << "LCM = " << lcm << endl;
    getch();
}

Program 22

/*
Program Number    :    22
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    int t1 = 0, t2 = 1, next, n;

    cout << "Enter a number to generate series up to: "; cin >> n;
    cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";

    next = t1 + t2;
    while(nextTerm <= n)
    {
        cout << nextTerm << ", ";
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    getch();
}

Program 23

/*
Program Number    :    23
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    int num, sum = 0, digit;
    cout << "Enter a positive integer: "; cin >> num;

    for(int i = num; i != 0; i /= 10)
    {
        digit = i % 10;
        sum += (digit*digit*digit);
    }

    if (sum == num)
        cout << num << " is an Armstrong number.";
    else
        cout << num << " is not an Armstrong number.";
    getch();
}


Program 24

/*
Program Number    :    24
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>
void main()
{
    clrscr();
    long shape, s1, s2;

    do
    {
        cout << endl << "Enter a shape to calculate area of (triangle = 3/rectangle = 4/circle = 0): ";
        cin >> shape; cout << endl;

        if (shape == 3)
        {
            cout << "Enter base of triangle: "; cin >> s1;
            cout << "Enter height of triangle: "; cin >> s2;
            cout << endl << "Area of given triangle: " << (0.5*s1*s2) << " units squared";
        }
        else if(shape == 4)
        {
            cout << "Enter length of rectangle: "; cin >> s1;
            cout << "Enter breadth of rectangle: "; cin >> s2;
            cout << endl << "Area of given rectangle: " << s1*s2 << " units squared";
        }
        else if(shape == 0)
        {
            cout << "Enter radius of circle: "; cin >> s1;
            cout << endl << "Area of given circle: " << (3.141*s1*s1) << " units squared";
        }
        else
            cout << endl << "Invalid input. Try again.";
            cout << endl << "Do you want to quit? (Yes = 1/No = 0): "; cin >> quit;
    } while (quit != 1);
    getch();
}

Program 25a

/*
Program Number    :    25
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    int N;
    cin >> N;
    long sum = 0, ssum = 0;

    for(int i = 1; i <= N; i++)
    {
    sum += i;
    sum += sum;
    ssum += sum;
    }
    cout << ssum;
    getch();
}

Program 25b

/*
Program Number    :    26
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();

    int N;
    cin >> N;
    long fact = 1, sum = 0;

    for (int i = 1, i <= N; i++)
    {
        fact *= i;
        sum += fact;
    }
    cout << sum;
    getch();
}

Program 25c

/*
Program Number    :    27
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();

    int N;
    cin >> N;

    long fact, sum = 0;

    for (int i = 1; i < 2*N - 1; i += 2)
    {
        fact = 1;

        for (int j = 1; j <= c; j++)
            fact *= j;

        sum += fact;
    }
    cout << sum;
    getch();

}

Program 25d

/*
Program Number    :    28
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>
void main()
{
    clrscr();
    int N;
    cin >> N;

    long fact, sum=0;

    for(int i = 2; i <= 2*N; i += 2)
    {
        fact = 1;
        for (int j = 2; j <= i; j++)
            fact *= j;
        sum += fact;
    }
    cout << sum;
    getch();
}

Program 26a

/*
Program Number    :    29
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();

    long prod = 1; sum = 0;
    int X, N;

    cin >> X >> N;

    for (int i = 1; i = N; i++)
    {
        prod *= X;
        sum += Prod;
    }
    cout << sum;
    getch();
}

Program 26b

/*
Program Number    :    30
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();

    long prod = 1; sum = 0;
    int X, N;

    cin >> X >> N;

    for (int i = 1; i = 2*N - 1; i += 2)
    {
        prod *= X;
        sum += prod;
    }

    cout << sum;
    getch();
}

Program 26c

/*
Program Number    :    31
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    int X, N;
    cin >> X >> N;

    long sum = 0, prod = 1, fact = 1;

    for (int i = 1; i <= N; i++)
    {
        prod *= X;
        fact *= i;
        sum += prod/fact;
    }
    cout << sum;
    getch();
}

Program 26d

/*
Program Number    :    32
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    int X, N;
    cin >> X >> N;

    long sum = 0, prod = 1, fact = 1;

    for (int i = 1; i <= N; i++)
    {
        prod *= X;
        fact *= -i;
        sum += prod/fact;
    }
    cout << sum;
    getch();
}

Program 27a

/*
Program Number    :    33
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>
void main()
{
    clrscr();
    for (int R = 1; R <= 5; R++)
    {
        for (int C = 1; C <= R; C++)
            cout << C;

        cout << endl;
    }
    getch();
}

Program 27b

/*
Program Number    :    34
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    for (int R = 1; R <= 5; R++)
    {
        for (int C = 1; C <= R; C++)
            cout << R;
        cout << endl;
    }
    getch();
}

Program 27c

/*
Program Number    :    35
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    05-05-2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    for (int R = 1; R <= 5; R++)
    {
        for (int C = 5; C >= R; C--)
            cout << C;
        cout << endl;
    }
    getch();
}

Program 27d

/*
Program Number    :    36
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    for (int R = 1; R <= 5; R++)
    {
        for(int C = 1; C <= R; C++)
            cout<<"*";
        cout<<endl;
    }
    getch();
}

Program 27e

/*
Program Number    :    37
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    for (int R = 1; R <= 5; R++)
    {
        for (int C = 5; C >= R; C--)
            cout << "*";
        cout<<endl;
    }
    getch();
}

Program 27f

/*
Program Number    :    38
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    int e=1;
    for (int a = 1; a <= 5; a++)
    {
        for (int b = 4; b >= a; b--)
            cout << " ";
        for(int c=0;c<e;c++)
            cout << "*";
        cout << endl;
        e += 2;
    }
    getch();
}

Program 27g

/*
Program Number    :    39
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    for (int R = 1; R <= 3; R++)
    {
        for (int C = 1; C <= R; C++)
            cout << "*";
        cout << endl;
    }
    for (int R = 1; R <= 2; R++)
    {
        for (int C = 2; C >= R; C--)
            cout << "*";
        cout << endl;
    }
    getch();
}

Program 27h

/*
Program Number    :    40
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    for (int R = 1; R <= 3; R++)
    {
        for (int C = 1; C <= R; C++)
            cout << C;
        cout << endl;
    }
    for (int R = 1; R <= 2; R++)
    {
        for (int C = 2; C >= R; C--)
            cout << C;
        cout << endl;
    }
    getch();
}

Program 27i

/*
Program Number    :    41
Developed by      :    Vinamr L Sachdeva, Om Gupta
Class Section     :    XI H
Date              :    08 July 2018
*/

#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();
    int n, c, k, s = 1;

    cin >> n;
    s = n - 1;

    for (k = 1; k <= n; k++)
    {
        for (c = 1; c <= s; c++)
            cout << " ";
        s--;
        for (c = 1; c <= 2*k - 1; c++)
            cout << "c";
        cout << endl;
    }

    s = 1;

    for (k = 1; k <= n - 1; k++)
    {
        for (c = 1; c <= s; c++)
            cout << " ";
        s++;
        for (c = 1 ; c <= 2*(n - k) - 1; c++)
            cout << "c";
        cout << endl;
    }
    getch();
}
