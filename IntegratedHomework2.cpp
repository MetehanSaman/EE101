#include <iostream>
#include <cmath>

using namespace std;
bool game(int interval){
    srand(time(0));
    int number=0, guess=0,try_count=0,previous_guess = 0;
    string again_option;
    float score;
    bool try_again;
    bool done = false, guide = false;
    number = rand() % interval;
            while(!done){
                previous_guess = guess; 
                cout << "Enter your guess:";
                cin >> guess;
                try_count++;
                if(guess > interval){
                    cout << "Your guess is out of limit! The number is between 0-" << interval << endl;
                    try_count--;
                    guess = 0;
                }
                else if(number - guess>0){
                    if((previous_guess < guess) & previous_guess!=0){
                        cout << "Your guess is closer to the number than your previous guess and number is more than your current guess" << endl;
                        guide=true;
                    }
                    if(previous_guess > guess & previous_guess!=0){
                        cout << "Your previous answer was more close to the number and number is more than your current guess" << endl;
                        guide=true;
                    }
                    if(previous_guess == guess & previous_guess!=0){
                        cout << "You entered your previous guess" << endl;
                        guide=true;
                    }
                    if(abs(number - guess<5) & !guide){
                        cout << "Your guess is less than the number but you are very close." << endl;
                    }
                    else if(abs(number - guess)<15 & !guide){
                        cout << "Your guess is less than the number but you are close. Keep trying." << endl;
                    }
                    else if(abs(number - guess)<25 & !guide){
                        cout << "Your guess is less than the number and you are a little bit far from the number." << endl;
                    }
                    else if(!guide){
                        cout << "Your guess is less than the number and you are very far from the number." << endl;
                    }
                }
                else if(number - guess<0){
                    if(number-previous_guess > 0){
                        if(previous_guess < guess & previous_guess!=0){
                        cout << "Your guess is closer to the number than your previous guess and number is less than your current guess" << endl;
                        guide=true;
                        }
                        if(previous_guess > guess & previous_guess!=0){
                        cout << "Your previous answer was more close to the number and number is less than your current guess " << endl;
                        guide=true;
                        }
                        if(previous_guess == guess & previous_guess!=0){
                        cout << "You entered your previous guess" << endl;
                        guide=true;
                        }
                    }
                    else{
                        if(previous_guess > guess & previous_guess!=0){
                        cout << "Your guess is closer to the number than your previous guess and number is less than your current guess" << endl;
                        guide=true;
                        }
                        if(previous_guess < guess & previous_guess!=0){
                        cout << "Your previous answer was more close to the number and number is less than your current guess" << endl;
                        guide=true;
                        }
                        if(previous_guess == guess & previous_guess!=0){
                        cout << "You entered your previous guess" << endl;
                        guide=true;
                        }
                    }
                    if(abs(number - guess)<5 & !guide){
                        cout << "Your guess is more than the number but you are very close." << endl;
                    }
                    else if(abs(number - guess)<15 & !guide){
                        cout << "Your guess is more than the number but you are close. Keep trying." << endl;
                    }
                    else if(abs(number - guess)<25 & !guide){
                        cout << "Your guess is more than the number and you are a little bit far from the number." << endl;
                    }
                    else if(!guide){
                        cout << "Your guess is more than the number and you are very far from the number." << endl;
                    }
                }
                else{
                    score = 1.0/try_count*10000;
                    cout << "Good Job! You guessed the number. You tried " << try_count << " times. Your score is: " << ceil(score) << endl;
                    done = true;
                    number=0;
                    guess=0;
                    try_count=0;
                    previous_guess = 0;
                    cout << "Do you want to play again(yes/no): ";
                    cin >> again_option;
                    if(again_option == "yes"){
                        try_again=true;
                    }
                    else{
                        try_again=false;
                    }
                }
            }
    return try_again;
    }

int main(){
    cout << "Welcome to the Guessing Game" << endl;
    bool try_again=true;
    while(try_again){
        int choice, number=0, guess=0,try_count=0,previous_guess = 0;
        string again_option;
        float score;
        bool done = false, guide = false;
        cout << "1-Easy: Range of numbers is 1-50" << endl;
        cout << "2-Medium: Range of numbers is 1-100" << endl;
        cout << "3-Hard: Range of numbers is 1-200" << endl;
        cout << "Please choose a difficulty level:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            try_again=game(50);
            break;
        case 2:
            try_again=game(100);
            break;
        case 3:
            try_again=game(200);
            break;
        default:
            break;
        }
    }
}