//
// printascii.cpp
//
// Doga Ozkaracaabatlioglu
// 2/19/2018
// Assignment 5 Program 1
// Prints ascii characters from whitespace to tilde by iterating
//
#include <iostream>
using namespace std;

int main()
{
    char s_char = ' ';
    char e_char = '~';

    for (int i=1;(int) s_char <= (int) e_char;i++)
    {
       if (i % 15 == 0)
       {
           cout << "\n";
       }
       else
       {
       cout << s_char << ' ' << flush;
       (int) s_char++;
       }
    }

    cout << endl;

    return 0;
}
