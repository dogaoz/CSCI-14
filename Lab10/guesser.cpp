//
// guesser.cpp
//
// Doga Oz, Christian Pradl
// April 24, 2018
// Lab 10 - Guesser
// Generate random number and have user guess within 8 tries.
//
//

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int guess = 0, k = 1, answer = 0, guess_min = 1, guess_max = 100;

    while (k != 9)
    {
        guess = ((guess_max + guess_min) / 2);

        cout << "I'm guessing the number is " << guess << endl
             << "Is my guess right or is it smaller or bigger?" << endl
             << "- Enter 0 if it is CORRECT " << endl
             << "- Enter 1 if it is TOO SMALL" << endl
             << "- Enter 2 if it is TOO BIG" << endl;
        cin >> answer;

        if (answer == 0)
        {
            cout << "I found it on " << k << "th try. It is " << guess << endl;
            break;
        }
        else if (k == 8)
        {
            cout << "Sorry, I couldn't find after " << k << " tries." << endl;
        }
        else if (answer == 1)
        {
            guess_min = guess + 1;
        }
        else if (answer == 2)
        {
            if (guess != 1)
                guess_max = guess - 1;
            else
                guess_max = guess;
        }

        k++;
    }



    return 0;
}
