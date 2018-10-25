//
// diamonds.cpp
//
// Doga Ozkaracaabatlioglu
// 2/27/2018
// Assignment 6
// Prompts for a number of rows (nRows) from the user and prints a diamond.
//
#include <iostream>
using namespace std;

int main()
{
    int rows, spaces, stars, aftermiddle = 0;

    cout << "Please enter number of rows: " << endl;
    cin >> rows;

    // Validation loop to prevent user to enter too small or too big numbers.
    while (rows < 3 || rows > 23)
    {
        if (rows < 3)
        {
            cout << "Too few rows to make a diamond. " << endl
                 << "Please enter a new number of rows: " << endl;
            cin >> rows;
        }
        else if (rows > 23)
        {
            cout << "Too many rows to make a diamond. " << endl
                 << "Please enter a new number of rows: " << endl;
            cin >> rows;
        }
    }


    if (rows % 2 == 0)
    {
        rows++;
    }
    // Set starting values for stars and spaces depending on the row count
    stars = 1;
    spaces = (rows-1)/2;

    for (int i=0;i<rows;i++)
    {
        // Print spaces and stars in order
        for (int k=0;k<spaces;k++)
        {
            cout << ' ' << flush;
        }
        for (int m=0;m<stars;m++)
        {
            cout << '*' << flush;
        }
        // Continue adding to stars until it reaches to row number then reverse
        if (stars < rows && aftermiddle==0)
        {
            stars += 2;
            spaces--;
        }
        else
        {
            spaces++;
            stars -= 2;
            aftermiddle = 1;
        }
        cout << endl;
    }

    return 0;
}
