//
// eratosthenes.cpp
//
// Doga Ozkaracaabatlioglu
// 4/10/2018
// Assignment 9 - the Sieve of Eratosthene
// Finds all prime numbers and prints into output.txt
//
#include <iostream>
#include <fstream>
using namespace std;

const int limit = 10001;

int main()
{
    // try to open file
    ofstream fout( "output.txt" );
    // check if failed while opening file and quit.
    if( !fout )
    {
        cout << "Output file open failed\n";
        return -1;
    }

    int a[limit];
    // Assume all the numbers are prime.
    // 1 means prime, 0 means not prime.
    for (int i=0;i<limit;i++)
    {
        a[i] = 1;
    }
    // 0 and 1 cannot be prime.
    a[0] = 0;
    a[1] = 0;

    // Mark non-prime numbers in the array.
    for (int n=2; n < limit; n++)
    {
        if (a[n] == 1)
        {
            for (int j=2; j <= limit/2; j++)
            {
                if (n*j > limit)
                    break;
                else
                {
                    a[n*j] = 0;
                }
            }
        }
    }

    // Print prime numbers using the modified array.
    // Eight numbers in one line without trailing characters in any line.
    int posInLine = 1;
    int newLine = 1;
    for (int i = 2;i < limit; i++)
    {
        if (a[i] == 1 && posInLine <= 7 )
        {
            if (newLine)
            {
                fout << i;
                newLine = 0;
            }
            else
            {
                fout << '\t' << i;
            }
            posInLine++;
        }
        else if (a[i] == 1 && posInLine == 8)
        {
            posInLine = 1;
            fout << '\t' << i << '\n';
            newLine = 1;
        }
    }
    // Close the file
    fout.close();
    return 0;
}
