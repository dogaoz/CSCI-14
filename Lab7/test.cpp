//
// test.cpp
//
// Martin Santos, Doga Oz
// March 13, 2018
// Lab 7
// Answers for 1a, 1b
//
#include <iostream>
using namespace std;

int main()
{

    int i, n = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "1. (a) while-loop " << endl;

    i = 0;
    n = 0;
    //int i,n;
    cin >> n;
    while ((n > 0) && (i < n))
    {
        cout << i << " ";
        i++;
    }
    cout << endl;

    cout << "1. (b) do-while loop (careful: handle the user entering n<= 0) "
         << endl;

    i = 0;
    n = 0;
    //int i,n;
    cin >> n;
    do
    {
        if (n<= 0)
        break;

        cout << i << " ";
        i++;
    } while (i < n);

    cout << endl;

    return 0;
}

