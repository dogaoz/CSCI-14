//
// diamond.cpp
//
// Doga Ozkaracaabatlioglu
// 3/22/2018
// Assignment 7 Program 2 - Diamond
// Gets a number from the user until the value is legal.
// Then draws a diamond by using that value as its size.
//
#include <iostream>
using namespace std;

int GetNRows( void );
void DrawShape( int nRows );
int nSpaces( int nRows, int row );
int nStars( int nRows, int row );
void PrintChars( int n, char c );

int main()
{
    DrawShape(GetNRows());
    return 0;
}

// get the number of rows from the user, assuring legal and odd,
// then return it to the caller
int GetNRows()
{
    int nRows;

    cout << "Please enter number of rows: " << endl;
    cin >> nRows;

    // Validation loop to prevent user to enter too small or too big numbers.
    while (nRows < 3 || nRows > 23)
    {
        if (nRows < 3)
        {
            cout << "Too few rows to make a diamond. " << endl
                 << "Please enter a new number of rows: " << endl;
            cin >> nRows;
        }
        else if (nRows > 23)
        {
            cout << "Too many rows to make a diamond. " << endl
                 << "Please enter a new number of rows: " << endl;
            cin >> nRows;
        }
    }

    if (nRows % 2 == 0)
    {
        nRows++;
    }

    return nRows;
}

// draw the shape, using helper functions as needed.
void DrawShape( int nRows )
{
    for (int i=0; i<nRows; i++)
    {
        PrintChars(nSpaces(nRows, i), ' ');
        PrintChars(nStars(nRows, i), '*');
        cout << endl;
    }
}

// calculate number of spaces given current row and row number
int nSpaces( int nRows, int row )
{
    return (nRows - nStars(nRows, row )) / 2;
}

// calculate number of stars given current row and row number
int nStars( int nRows, int row )
{
     if (row > nRows/2)
        return (nRows - row) * 2 - 1;
    else
        return (row * 2) + 1;
}

// print n copies of character c on the current row
void PrintChars( int n, char c )
{
    for (int i=0; i<n; i++)
    {
        cout << c;
    }
}
