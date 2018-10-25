//
// paycheck.cpp
//
// Doga Ozkaracaabatlioglu
// 2/19/2018
// Assignment 5 Program 2
// Prompts the user for a number of days, then prints each
// day's pay in pennies, followed by the total accrued pay
// in dollars at the end.
//
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int days;
    int last_payment = 1;
    double total_pay = 0;

    cout << "Enter how many days will employee work: " << flush;
    cin >> days;

    for (int i=1;i<=days;i++)
    {
        cout << "For the day " << i << ": " << last_payment << endl;
        total_pay += last_payment;
        last_payment *= 2;

    }

    cout << "Lump sum paycheck: $" << showpoint << fixed
         << setprecision(2) << total_pay / 100 << endl;

    return 0;
}
