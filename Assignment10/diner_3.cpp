//
// diner_3.cpp
//
// Doga Ozkaracaabatlioglu
// 4/10/2018
// Assignment 10 - Program 3
// It fetches products data from a file, parses it contents, and loads them into
// an array. Then, it prints array items as a menu. prompts for user selection
// to get the list of what user wants to buy. Then calculates total amount due.
// Finally, it prints how many items are selected and the check.
//
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct MenuItem
{
    char name[255];
    float price;
};
void ReadItem(MenuItem &menuItem, ifstream &is);
void PrintItem(MenuItem menuItem, ostream &os);
void PrintItems(MenuItem menuItems[], int selectedItems[], bool isForCheck);
int PromptForSelection(MenuItem menuItems[], int selectedItems[]);
void PrintCheck(MenuItem menuItems[], int selectedItems[],
                int selected_cnt, ostream &os);
const int MAX = 11;

int main()
{
    ifstream fin;
    MenuItem menuItems[MAX];
    int selectedItems[MAX] = {0};
    int sel_cnt = 0;
    fin.open( "products.txt");
    // Check for open failure.
    if( !fin )
    {
       cout << "Input file open failed\n";
       return -2;
    }
    // Load 10 Products from a file into MenuItems Array
    for (int i=1;i<MAX;i++)
    {
        ReadItem(menuItems[i], fin);
    }
    PrintItems(menuItems, selectedItems, false);
    sel_cnt = PromptForSelection(menuItems,selectedItems);
    PrintCheck(menuItems, selectedItems, sel_cnt, cout);
    fin.close();
    return 0;
}

void PrintItems(MenuItem menuItems[], int selectedItems[], bool isForCheck)
{
    // Print 10 Products from MenuItems Array
    // depending on if its for menu or the check
    for (int i=1;i<MAX;i++)
    {
        if (isForCheck && selectedItems[i] == 1)
            PrintItem(menuItems[i], cout);
        else if (!isForCheck)
        {
            cout << i <<" : " << flush;
            PrintItem(menuItems[i], cout);
        }
    }
}
// Prompt for user to select items to buy
// Store values in selectedItems array
// Use returned value which shows how many items have been selected
int PromptForSelection(MenuItem menuItems[], int selectedItems[])
{
    int all_selected = 0, selection = 0, selection_count = 0;
    while (all_selected != 1 && selection != -1)
    {
        // Assume all selected. If one of them is not selected, keep going.
        all_selected = 1;
        for (int i=1;i<MAX;i++)
        {
            if (selectedItems[i] != 1)
                all_selected = 0;
        }
        if (all_selected == 0)
        {
            cout << "Enter a product number to add into cart." << endl;
            cin >> selection;
            // Check selection boundaries before inserting selection into array.
            if (selection >= 1 && selection < MAX)
            {
                if (selectedItems[selection] == 1)
                    cout << "You have already selected this item." << endl;
                else
                    selectedItems[selection] = 1;
            }
            else if (selection != -1)
                cout << "Selected item doesn't exist."<< endl ;
        }
    }
    //Count selections and return
    for (int i=1;i<MAX;i++)
    {
        if (selectedItems[i] == 1)
            selection_count++;
    }
    return selection_count;
}
void PrintCheck(MenuItem menuItems[], int selectedItems[],
                int selected_cnt, ostream &os)
{
    float sum = 0;
    os << "## " << selected_cnt << " items selected. ##" << endl;
    // Print Items for Check
    PrintItems(menuItems, selectedItems, true);
    // Calculate sum(total price) of selected items
    for (int i=1;i<MAX;i++)
    {
        if (selectedItems[i] == 1)
            sum += menuItems[i].price;
    }
    os << "## "<< "Total amount due: $" << fixed << setprecision(2)
       << sum << " ##" << endl;
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
