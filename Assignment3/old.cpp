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

double remaining_balance(double payment_number, double pmt_amount, double number_of_payments, double monthly_interest);

int main()
{
    // Get required values from user.
    double pmt_amount, interest_rate, number_of_payments, monthly_interest;
    cout << "Enter payment amount:" << endl;
    cin >> pmt_amount;
    cout << "Enter interest rate (9% as 0.09):" << endl;
    cin >> interest_rate;
    cout << "Enter number of payments:" << endl;
    cin >> number_of_payments;

    // Monthly interest calculation to be used below with cout as output and
    // also to pass it into remaining_balance function.
    monthly_interest = interest_rate / 12.0;

    // Print out details to user.
    cout << "Payment entered was $" << pmt_amount << "" << endl
         << "Interest rate is " << interest_rate << " which is " << monthly_interest << " per month" << endl
         << "Number of payments is " << number_of_payments << endl
         << "Payment #1 leaves a balance of $" << remaining_balance(1,pmt_amount, number_of_payments, monthly_interest) << endl
         << "Payment #2 leaves a balance of $" << remaining_balance(2,pmt_amount, number_of_payments, monthly_interest) << endl
         << "Payment #3 leaves a balance of $" << remaining_balance(3,pmt_amount, number_of_payments, monthly_interest) << endl;
    return 0;
}

// This function calculates the remaining balance
// after payment_number amount of payments
// from the values given by user in main function.

double remaining_balance(double payment_number, double pmt_amount, double number_of_payments, double monthly_interest)
{
    return pmt_amount * ((1 - pow(1 + monthly_interest, payment_number - number_of_payments))/monthly_interest);
}
