//
// coffeeshop.cpp
//
// Doga Oz, Van Dang
// April 3, 2018
// Lab 8
// Our coffee shop that calculates and prints items with costs,
// subtotal, tax, and grant total of the bill based on the user input.
//
#include <iostream>
#include <iomanip>
using namespace std;

void get_input(int& coffee, int& bagel, int& danish);
void calculate (int &coffee, int &bagel, int &danish,
                float &coffeeTotal, float &bagelTotal, float &danishTotal,
                float &subtotal, float &tax, float &grandtotal);
void print_output(int &coffee, int &bagel, int &danish,
                float &coffeeTotal, float &bagelTotal, float &danishTotal,
                float &subtotal, float &tax, float &grandtotal);
int main()
{

    int coffee, bagel, danish = -1;
    float coffeeTotal, bagelTotal, danishTotal, subtotal, tax, grandtotal = 0;

    get_input(coffee, bagel, danish);

    calculate(coffee, bagel, danish, coffeeTotal, bagelTotal,
              danishTotal, subtotal, tax, grandtotal);

    print_output(coffee, bagel, danish, coffeeTotal, bagelTotal,
                 danishTotal, subtotal, tax, grandtotal);

    return 0;

}

void get_input(int& coffee, int& bagel, int& danish)
{
    do
    {
        cout << "Enter the coffee: ";
        cin  >> coffee;
    } while (coffee <0);

    do
    {
        cout << "Enter the bagels: ";
        cin  >> bagel;
    } while (bagel <0);

    do
    {
        cout <<"Enter the danish: ";
        cin  >> danish;
    } while (danish <0);

    return;

}

void calculate (int &coffee, int &bagel, int &danish,
                float &coffeeTotal, float &bagelTotal, float &danishTotal,
                float &subtotal, float &tax, float &grandtotal)
{
    coffeeTotal = coffee * 1.25;
    bagelTotal = bagel * 1.50;
    danishTotal = danish * 2.25;

    subtotal = coffeeTotal + bagelTotal + danishTotal;
    tax = 0.09 * subtotal;
    grandtotal = subtotal + tax;

    return;

}

void print_output(int &coffee, int &bagel, int &danish,
                  float &coffeeTotal, float &bagelTotal, float &danishTotal,
                  float &subtotal, float &tax, float &grandtotal)
{
    cout << "\tOur Coffee shop" << endl;
    cout << "Item\tQuantity\tPrice" << endl;
    cout << showpoint << fixed << setprecision(2);
    cout << "Coffee\t"<< coffee << "\t\t" << "$" << coffeeTotal << endl;
    cout << "Bagel\t"<< bagel << "\t\t" << "$" << bagelTotal << endl;
    cout << "Danish\t" << danish << "\t\t" << "$" << danishTotal << endl;
    cout << endl;
    cout << "Subtotal \t\t$" << subtotal << endl;
    cout << endl;
    cout << "Tax \t\t\t$" << tax << endl;
    cout << endl;
    cout << "Total \t\t\t$" << grandtotal << endl;
}


