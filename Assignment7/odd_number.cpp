//
// odd_number.cpp
//
// Doga Ozkaracaabatlioglu
// 3/22/2018
// Assignment 7
// Prompts for a character, checks if the character is an odd digit or not.
//
#include <iostream>
using namespace std;

bool IsOddDigit(char);

int main()
{
    char character;
    cout << "Please enter a character: " << flush;
    cin >> character;

    if (IsOddDigit(character))
        cout << "The character you entered is an odd digit." << endl;
    else
        cout << "The character you entered is NOT an odd digit." << endl;

    return 0;
}

bool IsOddDigit(char ch)
{
    if (ch == '1' || ch == '3' || ch == '5' || ch == '7' || ch == '9')
        return true;
    else
        return false;
}
