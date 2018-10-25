//
// lab7.cpp
//
// Martin Santos, Doga Oz
// March 13, 2018
// Lab 7
// Answers for 2a, 2b, and 3a.
//
#include <iostream>
using namespace std;
int main()
{
    int i, n;
    // 2
    cout << "Number 2 original code: " << flush;
    cin >> n;
    while( n > 0)  {
        cout << n << " ";
        n /= 2;
    }
    cout << endl;

    // 2a
    cout << "Number 2 Part A: " << flush;
    cin >> n;
    do
    {
        if (n > 0)
        {
            cout << n << " ";
            n /= 2;
        }
    } while (n > 0);
    cout << endl;

    // 2b
    cout << "Number 2 Part B: " << flush;
    cin >> n;
    for(n; n > 0; n /= 2)
    {
        cout << n << " ";
    }
    cout << endl;

    // 3
    cout << "Number 3: " << flush;
    cin >> n;
    i = 1;
    do
    {
        cout << i << " ";
        i *= 2;
    }  while( i <= n );
    cout << endl;

    // 3a
    cout << "Number 3 Part A: " << flush;
    cin >> n;
    if(i = 1 > n)
    {
        cout << i << " ";
        i *= 2;
    }
    else
    {
        for (i = 1; i <= n; i *= 2)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
