//
// test2.cpp
//
// Martin Santos, Doga Oz
// March 13, 2018
// Lab 7
// Answers for 3b
//
#include <iostream>
using namespace std;

int main()
{
    int i, n;
    cin >> n;
    i = 1;
    do
    {
        cout << i << " ";
        i *= 2;
    } while( i <= n );
    cout << endl;

    cout << "b) using a while loop:" << endl;

    i = 0;
    n = 0;
    //int i, n;
    cin >> n;
    i = 1;

    if (n < 1)
    n = 1;

    while (i <= n)
    {
        cout << i << " ";
        i *= 2;
    }
    cout << endl;

    return 0;
}
