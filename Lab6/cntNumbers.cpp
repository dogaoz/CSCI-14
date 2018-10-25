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
    cout << "Enter two numbers:" << endl;
    cin  >> no1;
    cin  >> no2;

    cout << "F" << endl;
    while (no1 > no2)
    {
    cin  >> no1;
    cout << "Enter two numbers:" << endl;
    }

    while (no2 > no1)
    {


    }

    return 0;
}
