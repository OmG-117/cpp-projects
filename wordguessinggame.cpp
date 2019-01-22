#include <iostream> //CHANGE ALL THIS BEFORE SUBMITTING
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>

using namespace std;

char word_list[40][20] = {"triangle", "abnormal", "pressure", "glass",
                          "remunerate", "summary", "volunteer", "fisherman",
                          "pioneer", "pity", "survival", "answer",
                          "improve", "layout", "ivory", "bleed",
                          "distance", "deprive", "spider", "knee",
                          "ruin", "jury", "preoccupation", "forum",
                          "terrify", "execution", "bottom", "bland",
                          "float", "particle", "minimize", "smell",
                          "harvest", "ghostwriter", "minister", "lifestyle",
                          "split", "sulphur", "royalty", "relaxation"};

void print_word(char word[])
{
  for (int i = 0; word[i] != '\0'; i++)
  {
    if (word[i] ==  'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
      cout << word[i];
    else
      cout << '_';
  }
  cout << endl;
}

int check_word(char word[], char guess[])
{
  for (int i = 0; word[i] != '\0'; i++)
  {
    if (word[i] != guess[i])
      return 0;
  }
  return 1;
}

int main() //CHANGE
{
  char word[20], guess[20], q;
  int tries, score = 0;

  cout << "Welcome to the Word Guessing Game!" << endl;
  cout << "Press any key to begin. "; getch();

  while (1)
  {
    srand(time(NULL)); //CHANGE TO "randomize()"
    strcpy(word, word_list[rand() % 40]); // CHANGE "rand % 40" to "random(40)"
    tries = 5;

    while (1)
    {
      cout << endl << endl;
      print_word(word);
      cout << tries << " tries remaining." << endl;
      cout << "Enter your guess: "; cin >> guess;

      if (check_word(word, guess))
      {
        score++;
        cout << endl << "You guessed correctly!" << endl;
        break;
      }
      else
      {
        tries--;
        cout << endl << "Incorrect guess!" << endl;
      }

      if (tries == 0)
      {
        cout << "You are out of tries for this word. Better luck next time." << endl;
        break;
      }
    }

    cout << endl << "Your score is " << score << endl;
    cout << "Do you want to continue playing? (Y/N): "; q = tolower(getch());
    if (q != 'y')
      break;
  }

  cout << endl << endl << "Bye!";
  return 0; //REMOVE
}
