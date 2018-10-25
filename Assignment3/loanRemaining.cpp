//
// loanRemaining.cpp
//
// Doga Ozkaracaabatlioglu
// 2/1/2018
// Assignment 3
// Calculates monthly interest rate and remaining balance
// after first 3 payments for the loan.
//
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    // Define variables and get required values from user
    double pmt_amount, interest_rate, number_of_payments, monthly_interest,
           calc1, calc2, calc3 = 0;
    cout << "Enter payment amount:" << endl;
    cin >> pmt_amount;
    cout << "Enter interest rate (9% as 0.09):" << endl;
    cin >> interest_rate;
    cout << "Enter number of payments:" << endl;
    cin >> number_of_payments;

    // Monthly interest calculation to be used below with cout as output and
    // also to calculate remaining balance in calc1, calc2, calc3
    monthly_interest = interest_rate / 12.0;

    // Calculate the remaining balance after first, second, and third payment
    calc1 = pmt_amount * ((1 - pow(1 + monthly_interest, 1 - number_of_payments)
                          )/monthly_interest);
    calc2 = pmt_amount * ((1 - pow(1 + monthly_interest, 2 - number_of_payments)
                          )/monthly_interest);
    calc3 = pmt_amount * ((1 - pow(1 + monthly_interest, 3 - number_of_payments)
                          )/monthly_interest);

    // Format the output and print out calculations to user
    cout << "Payment entered was $" << pmt_amount << "" << endl
         << "Interest rate is " << interest_rate << " which is "
         << monthly_interest << " per month" << endl
         << "Number of payments is " << number_of_payments << endl
         << setprecision(2) << showpoint << fixed
         << "Payment #1 leaves a balance of $" << calc1 << endl
         << "Payment #2 leaves a balance of $" << calc2 << endl
         << "Payment #3 leaves a balance of $" << calc3 << endl;
    return 0;
}
