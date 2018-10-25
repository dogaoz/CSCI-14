//
// cntNumbers.cpp
//
// Davin Benson - Doga Ozkaracaabatlioglu
// 2/15/2018
//
// Lab6 - Second program
// Count numbers between given two integers regardless of direction
//

#include <iostream>
using namespace std;

int main()
{
    // Initialize variables and get input from user.
    int no1, no2 = 0;
    cout << "Enter two numbers to be counted between:" << endl;
    cin  >> no1;
    cin  >> no2;
    cout << "First number is: " << no1 << endl;
    cout << "Second number is: " << no2 << endl;

    if( no1 >= no2 )
    {
        while (no1 >= no2)
        {
            // print higher value, decrement until equal to lower value
            cout << no1 << " " << flush;
            no1--;
        }
    }
    else
    {   while (no1 <= no2)
        {
            // print lower value, increment until higher value
            cout << no1 << " " << flush;
            no1++;
        }
     }


    return 0;
}
