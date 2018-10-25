//
// convertCelsius.cpp
//
// Doga Ozkaracaabatlioglu
// 2/15/2018
// Assignment 2
// This converts temperature degree celsius to degree fahrenheit.
//

#include <iostream>
using namespace std;

int main()
{
    int sum, input = 0;

    do
    {


        cout << "Keep entering numbers to sum," << endl
             << "enter negative or zero to end program" << endl;

        cin  >> input;

        sum += input;

        cout << "sum is " << sum << endl;

          if (input <= 0)
            break;

    } while (true);

    return 0;
}
