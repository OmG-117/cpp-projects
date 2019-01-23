
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void generate_num(char num[8])
{
  for (int i = 0; i < 8; i++)
  {
    randomize();
    num[i] = random(10);
  }
}

int check_answer(char num[8], char answer[8])
{
  for (int i = 0; i < 8; i++)
  {
    if (answer[i] != num[i])
      return 0;
  }
  return 1;
}

int main()
{
  clrscr();
  cout << "Welcome to Memory Game!" << endl;
  cout << "Press any key to begin "; getch();
  cout << endl;

  char num[8], answer[8];
  int score;

  while (1)
  {
    generate_num(num);
    cout << "You will see a number for 10 seconds. Remember it." << endl;
    delay(2000);

    cout << endl << "The number is: " << endl;
    puts(num);
    delay(10000);

    clrscr();
    cout << "What was the number you just saw?" << endl; cin >> answer;

    if (check_answer(num, answer))
    {
      score++;
      cout << endl << "Correct answer!" << endl;
    }
    else
      cout << "Sorry, that was incorrect." << endl;

    cout << endl << "Your score is " << score << endl;
    cout << "Do you want to continue playing? (Y/N): "; q = tolower(getch());
    if (q != 'y')
      break;
  }

  cout << endl << endl << "Bye!";
}
