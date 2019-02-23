#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int main()
{
    int T, Ns[10];
    cout << "Enter number of test cases (max 10): "; cin >> T;
    cout << "Enter number of digits for each test case\n";

    ofstream file("input.txt", ios::trunc);
    file << T << "\n\n";
    file.close();

    for (int i = 0; i < T; i++)
    {
        cout << i + 1 << ": ";
        system("python debug.py");
    }

    cout << "\nWorking...\n";
    chrono::high_resolution_clock::time_point init = chrono::high_resolution_clock::now();
    system("magicseq.exe < input.txt > output.txt");
    chrono::high_resolution_clock::time_point final = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time = chrono::duration_cast<chrono::duration<double>>(final - init);
    cout << "Output generated in output.txt.\n";

    cout << "\nExecuted successfully.\n";
    cout << "Time elapsed: " << elapsed_time.count() << " seconds.\n";
    system("output.txt");
    return 0;
}
