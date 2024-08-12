#include <iostream>
#include <cstdlib> // for rand()

using namespace std;

bool isCorrect(int, int); 

int main() {

    int answer; // randomly generated number
    int guess;  // user's guess
    char response; // 'y' or 'n' response

    // loop until user types 'n' to quit
    do {
       // generate random number between 1 and 100
       // 1 is shift, 100 is scaling factor
       answer = 1 + rand() % 100;

       cout << "Om's Number Game\n"
            << "I'm thinking of a  number between 1 and 100.\n" 
            << "Try to guess the number!\n" 
            << "Please type your first guess." << endl << "? ";
       cin >> guess;

       // loop until correct number
       while ( !isCorrect(guess, answer) ) {
           cin >> guess;
       }    

       // prompt for another game
       cout << "\nExcellent! You guessed the number!\n"
            << "Would you like to play again (y or n)? ";
       cin >> response;

       cout << endl;
    } while (response == 'y');
}

bool isCorrect(int g, int a) {
    
    // guess is correct
    if ( g == a ) {
        return true;
    }

    // guess is incorrect; display hint
    if ( g < a ) {
        cout << "Too low, you are " << (a - g) << " off.  Try again.\n? ";
    }
    else {
        cout << "Too high, you are " << (g - a) << " off.  Try again.\n? ";
    }
   return false;
}
