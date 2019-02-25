//https://www.codechef.com/problems/MAGARR

#include <iostream>

using namespace std;

int L;
struct Boundary
{
    int pos;
    int val;
};

//Returns the number of a particular digit left in the list
int getAmount(int num_list[], int tgt)
{
    int count = 0;
    for (int i = 0; num_list[i] != -2; i++)
    {
        if (num_list[i] == tgt)
            count++;
    }
    return count;
}

//Returns the highest valued digit in the list
int max(int num_list[])
{
    int max;
    for (int i = 0; num_list[i] != -2; i++)
    {
        if (num_list[i] > max)
            max = num_list[i];
    }
    return max;
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
    for (int i = 0; num_list[i] != -2; i++)
    {
        if (num_list[i] == tgt)
        {
            num_list[i] = -1;
            return tgt;
        }
    }
    return -1;
}

//Places num back into the list
void place(int num_list[], int num)
{
    for (int i = 0; i < 12000; i++)
    {
        if (num_list[i] == -1)
        {
            num_list[i] = num;
            break;
        }
    }
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
            int top = 0;
            if (L && direction > 0 && !canReachZero(num_list, active_bound.val))
            {
                int pass = 0; //...and zero can't be reached from the current...
                while (seq[active_bound.pos + 1] > 0) //...pos, try backtracking
                {
                    pass = 0;
                    active_bound.pos += 1;
                    place(num_list, seq[active_bound.pos]);
                    seq[active_bound.pos] = -1;
                    if (canReachZero(num_list, active_bound.val))
                    {
                        pass = 1;
                        break;
                    }
                }
                top = active_bound.val;
                active_bound.val = seq[active_bound.pos + 1] + 1;
                if (!pass) //If even after backtracking, no dice...
                {
                    L = 0; generateLine(num_list, seq, active_bound, direction);
                    break; //...just fill as far as possible and break
                }
            }
            else if (!canReachZero(num_list, active_bound.val))
                break;
            active_bound.val -= direction; //Now try and find the previous digit
            val = findAndPop(num_list, active_bound.val);
            if (active_bound.val == 0 && val != -1) //But if it was zero...
            {
                active_bound.val -= direction; //...try and conserve it...
                val = findAndPop(num_list, active_bound.val); //(and find a one)
                place(num_list, 0); //...by putting it back
                if (val == -1) //In case there are no more ones...
                {
                    active_bound.val += direction; //...just get zero instead
                    val = findAndPop(num_list, active_bound.val);
                }
            }
            //But if there are no more of the previous digit or if the highest
            //digit cannot be reached now, get the previous to previous digit
            else if (val == -1 || !canReachZero(num_list, top))
            {
                place(num_list, val); //And put the previous digit back
                active_bound.val -= direction;
                val = findAndPop(num_list, active_bound.val);
                if (val == -1)
                    break;
            }
            direction *= -1; //Switch the direction of progression
        }
        //Whatever digit was finally obtained, put it in the appropriate
        //position and update both the position and active digit for next time
        seq[active_bound.pos] = val; active_bound.val += direction;
        active_bound.pos += (active_bound.pos > 12000) ? (1) : (-1);
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
        int k, num_list[12000];
        for (k = 0; k < N; k++)
            cin >> num_list[k];
        for (k = k; k < 12000; k++)
            num_list[k] = -2;

        //Initialize the array which will hold the final sequence to -1
        int seq[24000];
        for (int i = 0; i < 24000; i++)
            seq[i] = -1;

        //The two boundaries are for keeping track of the active position
        //and digit over both generator loops
        int is_sol = 1, direction = 1;
        Boundary lower = {11999, 1};
        Boundary upper = {12001, 1};

        //First sequence element is zero in the middle of the sequence
        seq[12000] = findAndPop(num_list, 0);
        if (seq[12000] == -1) //If there are no zeroes, just abort
        {
            cout << "No\n";
            T--;
            continue;
        }

        //Main generator loops
        L = 0; generateLine(num_list, seq, upper, direction);
        L = 1; generateLine(num_list, seq, lower, direction);

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
            /*
            for (int i : seq) //Testing code
            {
                if (i != -1)
                    cout << i << " ";
            }
            cout << "\n";
            for (int i = 0; num_list[i] != -2; i++)
            {
                if (num_list[i] != -1)
                    cout << num_list[i] << " ";
            }
            cout << "\n";
            */
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
}
