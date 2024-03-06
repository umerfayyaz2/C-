#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

bool isValidNum(int &number);

int main() {
    

    char playAgain;
    do {
        system("cls"); 
        cout << "<--------------------- Random Prize Give-Away Pool Game ------------------------>" << endl;

        int number_of_winners;

        do {
            if (!isValidNum(number_of_winners) || number_of_winners < 1 || number_of_winners > 10) {
                cout << "\nError: Invalid input. Please enter a number between 1 and 10 and avoid alphabets: ";
            }

        } while (number_of_winners < 1 || number_of_winners > 10);

        cout << "\nThe Number Of Lucky Winners: " << number_of_winners << endl;

        srand(time(0)); // seed for time

        for (int i = 0; i < number_of_winners; ++i) {
            int random_choice_generator = (rand() % 10) + 1; 

            switch (random_choice_generator) {

                case 1:
                    cout << "\nCongratulations! Pack your bags for a one-way vacation to Sahara.";
                    break;
                case 2: 
                    cout << "\nGreat news! You've won a Nokia. Welcome to 2005!";
                    break;
                case 3: 
                    cout << "\nWatch Openheimer with 2 of your friends. Popcorn not included.";
                    break;
                case 4:
                    cout << "\nLift up your mood! You won 2 tickets to the Abandoned Amusement Park.";
                    break;
                case 5: 
                    cout << "\nNow binge-watch your favorite series with a Netflix Gift-Card. Say goodbye to productivity!";
                    break;
                case 6:
                    cout << "\nSorry, better luck next time. The universe has trust issues with your randomness.";
                    break;
                case 7:
                    cout << "\nWelcome to Hell! You will now study C Programming Language for eternity.";
                    break;
                case 8:
                    cout << "\nThe time has come! Pack your bags, the Angel of Death is waiting for you.";
                    break;
                case 9:
                    cout << "\nCongratulations! You've escaped an infinite loop. Now try escaping this existential crisis.";
                    break;
                case 10:
                    cout << "\nSay no more! Your code won't have any bugs anymore. It's officially perfect. Maybe.";
                    break;
                default:
                    cout << "\nError: Try again. The universe is still figuring out what you want.";
            }

            cout << "\n----------------------------------------" << endl;
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing! Goodbye!";

    return 0;
}

bool isValidNum(int &number) {
    cout << "\nEnter the number of lucky winners (1-10): ";

    while (!(cin >> number) || cin.peek() != '\n' || number < 1 || number > 10) {
        cout << "\nError: Invalid input. Please enter a number between 1 and 10 and avoid alphabets: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return true;
}