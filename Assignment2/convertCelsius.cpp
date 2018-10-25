//
// convertCelsius.cpp
//
// Doga Ozkaracaabatlioglu
// 2/1/2018
// Assignment 2
// This converts temperature degree celsius to degree fahrenheit.
//

#include <iostream>
using namespace std;

int main()
{
    float celsius, fahrenheit;
    cout << "Enter temperature in degrees Celsius (dc):" << endl;
    cin >> celsius;

    //Fahrenheit to Celsius formula
    fahrenheit = 9.0f / 5.0f * celsius + 32.0f;

    cout << "you entered " << celsius << " degree celsius." << endl
         << "It's equivalent in degree fahrenheit (df) is " << fahrenheit << endl;
    return 0;
}
