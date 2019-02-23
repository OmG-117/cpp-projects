//https://www.codechef.com/problems/MAGARR

#include <iostream>

using namespace std;

struct Boundary
{
    int pos;
    int val;
};

//Returns the number of a particular digit left in the list
int getAmount(int num_list[], int tgt)
{
    int count = 0;
    for (int i = 0; num_list[i] != -2 && i < 10000; i++)
    {
        if (num_list[i] == tgt)
            count++;
    }
    return count;
}

//Returns 1 if there is at least one of every digit up to num in the list
int canReachZero(int num_list[], int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        if (!getAmount(num_list, i))
            return 0;
    }
    return 1;
}

//Returns tgt and deletes it from the list; if tgt is not found returns -1
int findAndPop(int num_list[], int tgt)
{
    for (int i = 0; num_list[i] != -2 && i < 10000; i++)
    {
        if (num_list[i] == tgt)
        {
            num_list[i] = -1;
            return tgt;
        }
    }
    return -1;
}

//Sequence generator loop
void generateLine(int num_list[], int seq[], Boundary &active_bound, int &direction)
{
    int val;
    while (true)
    {
        val = findAndPop(num_list, active_bound.val); //Try to get next digit
        if (val == -1) //If the required digit wasn't in the list...
        {
            if (direction > 0 && !canReachZero(num_list, active_bound.val))
                break; //...and it is impossible to reach zero, break loop
            active_bound.val -= direction; //Now try and find the previous digit
            val = findAndPop(num_list, active_bound.val);
            if (active_bound.val == 0 && val != -1) //But if it was zero...
            {
                active_bound.val -= direction; //...try and conserve it...
                val = findAndPop(num_list, active_bound.val); //(and find a one)
                for (int i = 0; num_list[i] != -2; i++) //...by putting it back
                {
                    if (num_list[i] == -1)
                    {
                        num_list[i] = 0;
                        break;
                    }
                }
                if (val == -1) //In case there are no more ones...
                {
                    active_bound.val += direction; //...just get zero instead
                    val = findAndPop(num_list, active_bound.val);
                }
            }
            else if (val == -1) //If there are no more of the previous digit...
            {
                active_bound.val -= direction; //...get the previous to previous
                val = findAndPop(num_list, active_bound.val);
                if (val == -1) //If there are none of those either, break loop
                    break;
            }
            direction *= -1; //Switch the direction of progression
        }
        //Whatever digit was finally obtained, put it in the appropriate
        //position and update both the position and active digit for next time
        seq[active_bound.pos] = val; active_bound.val += direction;
        active_bound.pos += (active_bound.pos > 6000) ? (1) : (-1);
    }
}

int main()
{
    int T; cin >> T; //Get number of test cases
    while (T > 0) //Loop for all test cases
    {
        //Get all the digits and place them in a list, and fill the rest of the
        //list with -2 until the end
        int N; cin >> N;
        int k, num_list[10000];
        for (k = 0; k < N; k++)
            cin >> num_list[k];
        for (k = k; k < 10000; k++)
            num_list[k] = -2;

        //Initialize the array which will hold the final sequence to -1
        int seq[12000];
        for (int i = 0; i < 12000; i++)
            seq[i] = -1;

        //The two boundaries are for keeping track of the active position
        //and digit over both generator loops
        int is_sol = 1, direction = 1;
        Boundary lower = {5999, 1};
        Boundary upper = {6001, 1};

        //First sequence element is zero in the middle of the sequence
        seq[6000] = findAndPop(num_list, 0);
        if (seq[6000] == -1) //If there are no zeroes, just abort
        {
            cout << "No\n";
            T--;
            continue;
        }

        generateLine(num_list, seq, upper, direction); //First generator loop

        //After the first generator loop terminates, the second generator loop
        //should run in the other direction. Since it is impossible that a
        //valid sequence can require more than (n - 1) zeroes (where n is the
        //number of ones left), just dump all the excess zeroes in the middle
        int zero_count = getAmount(num_list, 0);
        int one_count = getAmount(num_list, 1);
        if (one_count == 0)
            one_count = 1;
        while (zero_count > one_count - 1)
        {
            seq[lower.pos] = findAndPop(num_list, 0);
            lower.pos--;
            zero_count--;
        }

        generateLine(num_list, seq, lower, direction); //Second generator loop

        //After the second generator loop terminates, if there are any digits
        //left in the list, a valid sequence must be impossible
        for (int i = 0; i < N; i++)
        {
            if (num_list[i] >= 0)
                is_sol = 0;
        }
        if (!is_sol)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
            for (int i : seq)
            {
                if (i != -1)
                    cout << i << " ";
            }
            cout << "\n";
        }

        T--;
    }
    return 0;
}
