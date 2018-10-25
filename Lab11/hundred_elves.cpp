//
// hundred_elves.cpp
//
// Doga Oz, Aaron Gerardo
// May 8, 2018
// Lab 11 - Hundred Elves
// Finds the amount of gold stolen every night
// Also, prints out which night the stolen gold is the most and
// which night the remaining gold goes under 50oz.
//

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    long double rem_gold = 100;
    long double stolen_gold = 0;
    int max_stolen_night = 0;
    long double max_stolen_night_rem_gold = 0;
    long double max_stolen_night_stolen_gold = 0;
    int night_gold_under_50 = -1;
    long double rem_gold_of_the_night_under_50 = 0;
    long double stolen_gold_of_the_night_under_50 = 0;

    ofstream fout( "hundred_elves.txt");
    // Check for open failure.
    if(!fout)
    {
       cout << "Output file open failed\n";
       return -2;
    }
    fout << "Day" << setw(20) << "\tStolen Gold"
                  << setw(20) << "\tRemaining Gold" << endl;
    for (int i=1; i < 101; i++)
    {
        stolen_gold = rem_gold * ((float)i/100);
        rem_gold -= stolen_gold;
        fout << i << setw(20) << stolen_gold << setw(20) << rem_gold << endl;
        if (stolen_gold > max_stolen_night_stolen_gold)
        {
            max_stolen_night = i;
            max_stolen_night_stolen_gold = stolen_gold;
            max_stolen_night_rem_gold = rem_gold;
        }
        if (rem_gold < 50 && night_gold_under_50 == -1)
        {
            night_gold_under_50 = i;
            stolen_gold_of_the_night_under_50 = stolen_gold;
            rem_gold_of_the_night_under_50 = rem_gold;
        }
    }
    fout << "######" << endl;
    fout << "The night when the stolen gold is MAX: " << max_stolen_night << endl;
    fout << "Stolen gold on that day: " << max_stolen_night_stolen_gold << endl;
    fout << "Remaining gold on that day: " << max_stolen_night_rem_gold << endl;
    fout << "######" << endl;
    fout << "The night when the gold goes under 50oz: " << night_gold_under_50 << endl;
    fout << "Stolen gold on that day: " << stolen_gold_of_the_night_under_50 << endl;
    fout << "Remaining gold on that day: " << rem_gold_of_the_night_under_50 << endl;
    fout.close();
    return 0;
}
