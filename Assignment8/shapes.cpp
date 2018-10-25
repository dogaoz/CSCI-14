//
// shapes.cpp
//
// Doga Ozkaracaabatlioglu
// 3/22/2018
// Assignment 8 - Shapes
// Asks user to pick the shape from the menu to draw until the value is legal.
// Then, asks for "how many rows" until the value is legal.
// Finally, draws the shape by using that row number as the shape's size.
//
#include <iostream>
using namespace std;

int GetShape( void );
int GetNRows( int shape );
void DrawShape( int shape, int nRows );
int CalcNSpaces( int shape, int nRows, int row );
int CalcNStars(int shape, int nRows, int row );
void PrintChars( int n, char c );

int main()
{
    int shape;
    while(shape != 6)
    {
        shape = GetShape();
        if (shape != 6)
        DrawShape(shape,GetNRows(shape));
    }
    return 0;
}
// get the shape or 'quit' command returning the user's option
int GetShape()
{
        int shape;
        cout << "Which shape do you want to draw?" << endl
             << "1 - Diamond" << endl
             << "2 - Triangle" << endl
             << "3 - Parallelogram" << endl
             << "4 - Pyramid" << endl
             << "5 - Hourglass" << endl
             << "6 - Quit program" << endl;
        cin >> shape;
        if (shape < 1 || shape > 6)
        {
            cout << "Invalid Option. Please enter a number from the menu."
                 << endl;
            return GetShape();
        }
        else
        {
            return shape;
        }
}
// get number of rows for that shape, assuring legal, and return
int GetNRows(int shape)
{
    int nRows;
    cout << "Please enter number of rows between 3-23: " << endl;
    cin >> nRows;

    // Validation loop to prevent user to enter too small or too big numbers.
    while (nRows < 3 || nRows > 23)
    {
        if (nRows < 3)
        {
            cout << "Too few rows to make the shape. " << endl
                 << "Please enter a new number of rows: " << endl;
            cin >> nRows;
        }
        else if (nRows > 23)
        {
            cout << "Too many rows to make the shape. " << endl
                 << "Please enter a new number of rows: " << endl;
            cin >> nRows;
        }
    }
    // Don't increase for pyramid and triangle.
    // They don't have two separate parts.
    if (shape != 4 && shape != 2 && nRows % 2 == 0)
    {
        nRows++;
    }

    return nRows;
}
// draw the shape, using helper functions as needed.
void DrawShape(int shape, int nRows )
{
    for (int i=0; i<nRows; i++)
    {
        PrintChars(CalcNSpaces(shape, nRows, i), ' ');
        PrintChars(CalcNStars(shape, nRows, i), '*');
        cout << endl;
    }
}
// calculate number of spaces given current row and row number
int CalcNSpaces(int shape, int nRows, int row )
{
    switch (shape)
    {
    case 1: // Diamond
         return (nRows - CalcNStars(shape,nRows, row )) / 2;
        break;
    case 2: // Triangle
         return row;
        break;
    case 3: // Parallelogram
        if (row < nRows/2)
            return (nRows/2) - row;
        else
            return 0;
        break;
    case 4: // Pyramid
        return ((2*nRows) - CalcNStars(shape,nRows, row )) / 2;
        break;
    case 5: // Hourglass
        return (nRows - CalcNStars(shape,nRows, row )) / 2;
        break;
    }

}
// calculate number of stars given current row and row number
int CalcNStars(int shape, int nRows, int row )
{
    switch (shape)
    {
    case 1: // Diamond
        if (row > nRows/2)
            return (nRows - row) * 2 - 1;
        else
            return (row * 2) + 1;
        break;
    case 2: // Triangle
        return nRows - row;
        break;
    case 3: // Parallelogram
        if (row > nRows/2)
            return nRows - row;
        else
            return 1 + row;
        break;
    case 4: // Pyramid
        return 1 + (row * 2);
        break;
    case 5: // Hourglass
        if (row > nRows/2)
            return (nRows - 2 * (nRows - row)) + 2 ;
        else
            return nRows - (2*row) ;
        break;
    }
}

// print n copies of character c on the current row
void PrintChars( int n, char c )
{
    for (int i=0; i<n; i++)
    {
        cout << c;
    }
}
