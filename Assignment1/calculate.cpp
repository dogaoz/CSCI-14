//
// calculate.cpp
//
// Doga Ozkaracaabatlioglu
// 1/18/2018
// Assignment 1
// calculate diameter, area, and circumference of a circle from given radius.
//

#include <iostream>
using namespace std;

const float pi = 3.14159f;

int main()
{
    float radius, diameter, area, circumference;
    cout << "Enter radius :" << endl;
    cin >> radius;
    diameter = 2 * radius;
    area = pi * radius * radius;
    circumference = 2 * pi * radius;

    cout << "you entered " << radius << " as radius. \n"
         << "diameter is " << diameter << " \n"
         << "area is " << area << " \n"
         << "circumference is " << circumference << " \n"
         << endl;

    return 0;
}
