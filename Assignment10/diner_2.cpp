//
// diner_2.cpp
//
// Doga Ozkaracaabatlioglu
// 4/10/2018
// Assignment 10 - Program 2
// Fetches products data from a file, parses it contents, and loads them into
// an array. Then, it prints array items.
//
#include <iostream>
#include <fstream>
using namespace std;

struct MenuItem
{
    char name[255];
    float price;
};
void ReadItem(MenuItem &menuItem, ifstream &is);
void PrintItem(MenuItem menuItem, ostream &os);
const int MAX = 11;

int main()
{
    MenuItem menuItems[MAX];
    ifstream fin;
    fin.open( "products.txt");
    // Check for open failure.
    if( !fin )
    {
       cout << "Input file open failed\n";
       return -2;
    }

    for (int i=1;i<MAX;i++)
        ReadItem(menuItems[i], fin);

    for (int i=1;i<MAX;i++)
    {
        cout << i <<" : " << flush;
        PrintItem(menuItems[i], cout);
    }
    fin.close();
    return 0;
}

void PrintCheck(MenuItem menuItems[], int selectedItems[], ostream &os)
{
    float sum = 0;
    for (int i=1;i<MAX;i++)
    {
        if (selectedItems[i] == 1)
            PrintItem(menuItems[i], os);
    }
    for (int i=1;i<MAX;i++)
    {
        if (selectedItems[i] == 1)
            sum += menuItems[i].price;
    }
    os << "Total amount due is : $" << sum << endl;
}

void ReadItem(MenuItem &menuItem, ifstream &is)
{
    is.getline(menuItem.name, 255, '\n' );
    is >> menuItem.price;
    is.ignore();
}

void PrintItem(MenuItem menuItem, ostream &os)
{
    os << menuItem.name << " -- $" << menuItem.price << endl;
}
