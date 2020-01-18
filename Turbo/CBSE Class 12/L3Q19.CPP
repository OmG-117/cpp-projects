/*
Program No. : L3Q19
Developed by: Om Gupta
Date        : 13 August 2019
*/

#include <fstream.h>
#include <conio.h>

class Account
{
    int accno;
    char name[20];
    float balance;
public:
    void init()
    {
        cout << "Enter account number, name and balance: ";
        cin >> accno >> name >> balance;
    }
    void show()
    {
        cout << "Account number: " << accno << " | ";
        cout << "Account name: " << name << " | ";
        cout << "Account balance: " << balance << "\n";
    }
    void deposit(int amt) {balance += amt;}
    void withdraw(int amt) {balance -= amt;}
    int rAccno() {return accno;}
    float rBalance() {return balance;}
};

void registerAccs()
{
    int N;
    cout << "Enter number of accounts to register: "; cin >> N;
    Account acc;
    fstream f;
    f.open("Accounts.dat", ios::out | ios::binary);
    for (int i = 0; i < N; i++)
    {
        cout << "Account " << i + 1 << " - "; acc.init();
        f.write((char*)&acc, sizeof(Account));
    }
    f.close();
}

void transact()
{
    int mode, accno;
    float amt;
    cout << "Enter transaction type (1 = deposit, 2 = withdraw): "; cin >> mode;
    cout << "Enter account number and transfer amount: "; cin >> accno >> amt;
    mode = (mode == 1) ? (1) : (-1);
    Account acc;
    fstream f;
    f.open("Accounts.dat", ios::in | ios::out | ios::binary);
    while (f.read((char*)&acc, sizeof(Account)))
    {
        if (acc.rAccno() == accno)
        {
            if (acc.rBalance() + amt*mode < 500)
            {
                cout << "Transaction failed. Account must have balance >500.\n";
                f.close();
                return;
            }
            else
            {
                if (mode == 1)
                    acc.deposit(amt);
                else
                    acc.withdraw(amt);
            }
            f.seekp(-sizeof(Account), ios::cur);
            f.write((char*)&acc, sizeof(Account));
            cout << "Transaction successful.\n";
            f.close();
            return;
        }
    }
    cout << "Transaction failed. Account number not found.\n";
    f.close();
    return;
}

void displayAll()
{
    Account acc;
    fstream f;
    f.open("Accounts.dat", ios::in | ios::binary);
    while (f.read((char*)&acc, sizeof(Account)))
        acc.show();
    f.close();
}

void main()
{
    int opt, cont = 1;
    while (cont)
    {
        cout << "1. Register | ";
        cout << "2. Transact | ";
        cout << "3. Display all | ";
        cout << "4. Exit\n";
        cout << "Enter your choice: "; cin >> opt;
        cout << "\n";
        switch(opt)
        {
            case 1: registerAccs();
                break;
            case 2: transact();
                break;
            case 3: displayAll();
                break;
            case 4: cont = 0;
        }
        cout << "\n";
    }
}

/*
OUTPUT:
1. Register | 2. Transact | 3. Display all | 4. Exit
Enter your choice: 1

Enter number of accounts to register: 5
Account 1 - Enter account number, name and balance: 101 Rob 24579.53
Account 2 - Enter account number, name and balance: 102 May 53912.19
Account 3 - Enter account number, name and balance: 104 Jon 31031.87
Account 4 - Enter account number, name and balance: 107 Ash 82691.66
Account 5 - Enter account number, name and balance: 108 Ren 10538.51

1. Register | 2. Transact | 3. Display all | 4. Exit
Enter your choice: 2

Enter transaction type (1 = deposit, 2 = withdraw): 1
Enter account number and transfer amount: 104 5205.64
Transaction successful.

1. Register | 2. Transact | 3. Display all | 4. Exit
Enter your choice: 3

Account number: 101 | Account name: Rob | Account balance: 24579.5
Account number: 102 | Account name: May | Account balance: 53912.2
Account number: 104 | Account name: Jon | Account balance: 36236.9
Account number: 107 | Account name: Ash | Account balance: 82691.7
Account number: 108 | Account name: Ren | Account balance: 10538.5

1. Register | 2. Transact | 3. Display all | 4. Exit
Enter your choice: 2

Enter transaction type (1 = deposit, 2 = withdraw): 2
Enter account number and transfer amount: 107 82500
Transaction failed. Account must have balance >500.

1. Register | 2. Transact | 3. Display all | 4. Exit
Enter your choice: 2

Enter transaction type (1 = deposit, 2 = withdraw): 1
Enter account number and transfer amount: 205 5320
Transaction failed. Account number not found.

1. Register | 2. Transact | 3. Display all | 4. Exit
Enter your choice: 3

Account number: 101 | Account name: Rob | Account balance: 24579.5
Account number: 102 | Account name: May | Account balance: 53912.2
Account number: 104 | Account name: Jon | Account balance: 36236.9
Account number: 107 | Account name: Ash | Account balance: 82691.7
Account number: 108 | Account name: Ren | Account balance: 10538.5

1. Register | 2. Transact | 3. Display all | 4. Exit
Enter your choice: 4
*/
