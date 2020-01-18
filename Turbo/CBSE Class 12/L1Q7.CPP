/*
Program No. : L1Q7
Developed by: Om Gupta
Date        : 16 April 2019
*/

#include <iostream.h>
#include <conio.h>
#include <string.h>

void enter(char list[][40], int &N)
{

	cout << "Enter country to be added: ";
	cin >> list[N++];
	cout << "Country registered at position " << N << ".\n";
}

void display(char list[][40], int N)
{
	cout << "Enter index to display country from: ";
	int I; cin >> I;
	if (--I < N)
		cout << "Country found: " << list[I] << ".\n";
	else
		cout << "There is no country registered at that index.\n";
}

void sort(char list[][40], int N)
{
	int max;
	char T[40];
	for (int i = 0; i < N; i++)
	{
		max = 0;
		for (int j = i + 1; j < N; j++)
		{
			if (strcmp(list[j], list[max]) > 0)
				max = j;
		}
		strcpy(T, list[i]);
		strcpy(list[i], list[max]);
		strcpy(list[max], T);
	}
	cout << "List sorted.\n";
}

int search(char list[][40], int N, char tgt[40])
{
	for (int i = 0; i < N; i++)
	{
		if (!strcmp(list[i], tgt))
			return i;
	}
	return -1;
}

void main()
{
	clrscr();
	int max_pos = 0;
	char countries[20][40];
	while (1)
	{
		int option;
		cout << "\nEnter function to perform\n";
		cout << "1: Enter country\n2: Display country\n3: Sort\n4: Search\n";
		cout << "Your input: "; cin >> option;
		if (option != 1 && option != 2 && option != 3 && option != 4)
		{
			cout << "Invalid input. Try again.\n";
			continue;
		}
		else if (option == 1)
			enter(countries, max_pos);
		else if (option == 2)
			display(countries, max_pos);
		else if (option == 3)
			sort(countries, max_pos);
		else if (option == 4)
		{
			char search_term[40];
			cout << "Enter country to search for: ";
			cin >> search_term;
			int result = search(countries, max_pos, search_term);
			if (result == -1)
				cout << "Country has not been registered.";
			else
				cout << "Country has been registered at index " << result + 1 << ".\n";
		}
		char quit = 'n';
		cout << "\nDo you want to quit? (Y/N): "; cin >> quit;
		if (quit == 'Y' || quit == 'y')
			break;
	}
}

/*
OUTPUT:

Enter function to perform
1: Enter country
2: Display country
3: Sort
4: Search
Your input: 1
Enter country to be added: India
Country registered at position 1.

Do you want to quit? (Y/N): n

Enter function to perform
1: Enter country
2: Display country
3: Sort
4: Search
Your input: 1
Enter country to be added: USA
Country registered at position 2.

Do you want to quit? (Y/N): n

Enter function to perform
1: Enter country
2: Display country
3: Sort
4: Search
Your input: 1
Enter country to be added: Canada
Country registered at position 3.

Do you want to quit? (Y/N): n

Enter function to perform
1: Enter country
2: Display country
3: Sort
4: Search
Your input: 2
Enter index to display country from: 1
Country found: India.

Do you want to quit? (Y/N): n

Enter function to perform
1: Enter country
2: Display country
3: Sort
4: Search
Your input: 3
List sorted.

Do you want to quit? (Y/N): n

Enter function to perform
1: Enter country
2: Display country
3: Sort
4: Search
Your input: 4
Enter country to search for: India
Country has been registered at index 2.

Do you want to quit? (Y/N): y

*/
