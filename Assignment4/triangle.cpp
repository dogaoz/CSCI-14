//
// triangle.cpp
//
// Doga Ozkaracaabatlioglu
// 2/19/2018
// Assignment 4 Program 1
// Check if the given lengths for the three sides of a triangle
// forms a right triangle or not.
//
#include <iostream>
using namespace std;

int main()
{
    // Define variables and get required values from user
    int side1, side2, side3, length_of_hypo, longest_side = 0;
    bool is_right_triangle = 0;

    cout << "Enter Side 1 :" << endl;
    cin >> side1;
    cout << "Enter Side 2 :" << endl;
    cin >> side2;
    cout << "Enter Side 3 :" << endl;
    cin >> side3;

    // Find the longest side (hypotenuse) for the formula.
    longest_side = side1;
    length_of_hypo = (side2 * side2) + (side3 * side3);

    if (longest_side < side2)
    {
        longest_side = side2;
        length_of_hypo = (side1 * side1) + (side3 * side3);
    }
    if (longest_side < side3)
    {
        longest_side = side3;
        length_of_hypo = (side1 * side1) + (side2 * side2);
    }

    // Use formula to check if square of hypotenuse is
    // equal to sum of squares of sides.
    if (length_of_hypo == longest_side * longest_side)
    {
        is_right_triangle = 1;
        cout << "It is a right triangle" << endl;
    }
    if (is_right_triangle == 0)
    {
        cout << "It is NOT a right triangle" << endl;
    }

    return 0;
}
