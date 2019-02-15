#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

int chkPrime(const long int &num, int const prime_list[])
{
    long int num_sqrt = sqrt(num) + 1;
    if (!prime_list)
    {
        for (int i = 2; i < num_sqrt; i++)
        {
            if (!(num % i))
                return 0;
        }
        return 1;
    }
    else
    {
        for (int i = 0; prime_list[i] < num_sqrt; i++)
        {
            if (!(num % prime_list[i]))
                return 0;
        }
        return 1;
    }
}

int main()
{
    int task;
    while (true)
    {
        cout << "Select function: \n1. Check single number\n2. Find primes upto number\n";
        cout << "Your input: "; cin >> task; cout << "\n";
        if (task == 1 || task == 2)
            break;
        else
            cout << "Invalid input. Try again.\n";
    }
    long int tgt_num;
    cout << "Enter target number: "; cin >> tgt_num;

    if (task == 1)
    {
        cout << "\nWorking...";
        if (chkPrime(tgt_num, nullptr))
            cout << "\rThe number is a prime!\n";
        else
            cout << "\rThe number is not a prime!\n";
        cout << "\n"; system("pause");
    }
    else if (task == 2)
    {
        cout << "\nStarting...\n";
        long int tgt_num_sqrt = sqrt(tgt_num) + 1;
        long int prime_count = 0;
        int *const prime_list_ptr_og = new int[tgt_num];
        int *prime_list_ptr = &(*prime_list_ptr_og);

        chrono::high_resolution_clock::time_point init = chrono::high_resolution_clock::now();

        *prime_list_ptr = 2; prime_list_ptr++; prime_count++;
        //cout << 2 << "\n";
        for (int i = 3; i < tgt_num; i++)
        {
            if (chkPrime(i, prime_list_ptr_og))
            {
                *prime_list_ptr = i; prime_list_ptr++; prime_count++;
                //cout << i << "\n";
            }
        }

        chrono::high_resolution_clock::time_point final = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_time = chrono::duration_cast<chrono::duration<double>>(final - init);

        delete[] prime_list_ptr_og;
        cout << "Done!\n\n";
        cout << "Primes found: " << prime_count << "\n";
        cout << "Time elapsed: " << elapsed_time.count() << " seconds.\n";
        cout << "\n"; system("pause");
    }
    return 0;
}
