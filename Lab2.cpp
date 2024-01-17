#include <iostream>
using namespace std;

int main() {
  cout << "Welcome to the Number Guessing Game!\n";
  int random_number, guess, try_count = 0;
  string choice;
  bool replay = true;
  while (replay == true) {
    cout << "I’m thinking of a number between 1 and 100. Try to guess it.";
    random_number = rand() % 100 + 1;
    while (true) {
      cout << random_number << endl;
      cout << "Enter your guess:";
      cin >> guess;
      if (guess < random_number) {
        cout << "Your guess is too low. Try again." << endl;
        try_count++;
        continue;
      } else if (guess > random_number) {
        cout << "Your guess is too high. Try again." << endl;
        try_count++;
        continue;
      } else {
        cout << "Congratulations! You guessed the number in " << try_count
             << " attempts." << endl;
        cout << "Do you want to play again? (yes/no): ";
        cin >> choice;
        if (choice == "yes") {
          replay = true;
          break;
        } else {
          replay = false;
          break;
        }
      }
    }
  }
}