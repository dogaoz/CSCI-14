//
// batting_calc.cpp
//
// Doga Ozkaracaabatlioglu
// 5/8/2018
// Final Assignment - Baseball Game Statistics Calculator
// Gets two input files and processes names and stats and it calculates
// averages, best players, worst players and prints out into an output file.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

struct PLAYER
{
    int player_no;
    char lastName[25];
    char firstName[25];
    int games_played;
    float hits ;
    float walks;
    float outs;
    float batting_avg;
    float base_avg;
};
void addGameToPlayer(PLAYER player[], int no, int hits, int walks, int outs);
bool loadStats(PLAYER players[], istream &fin);
void loadNames(PLAYER player[], istream &fin);
void printStats(PLAYER players[], ostream &os, bool omitInactive);
int getWorst(PLAYER players[], int option);
float getAvg(PLAYER players[], int option);
void exchange( PLAYER &a, PLAYER &b );
int findPlayerLocInArray (PLAYER players[], int player_no);
void sort(PLAYER a[], int option);
const int MAX = 20;

int main()
{
    bool no_statistics = false;
    ifstream fin;
    PLAYER players[MAX];
    string ifilename_players, ifilename_stats = "";
    string output_filename = "output_data.txt";
    cout << "Enter file name players: " << endl;
    cin >> ifilename_players;
    fin.open(ifilename_players);
    // Check for open failure.
    if( !fin )
    {
       cout << "Input file open failed\n";
       return -2;
    }

    loadNames(players, fin);
    fin.close();
    cout << "Enter file name for stats: " << endl;
    cin >> ifilename_stats;
    fin.open(ifilename_stats);
    // Check for open failure.
    if( !fin )
    {
       cout << "Input file open failed\n";
       return -2;
    }
    no_statistics = loadStats(players, fin);
    fin.close();
    ofstream fout(output_filename);
    // Check for open failure.
    if( !fout )
    {
       cout << "Output file open failed\n";
       return -2;
    }
    // Print out everything
    fout << "Input file name for players: " << ifilename_players << endl;
    fout << "Input file name for statistics: " << ifilename_stats << endl;
    fout << "Output filename: " << output_filename << endl;
    fout << "######### SORTED BY ALPHABETICALLY #########" << endl;
    sort(players, 0); // sortAlphabetically
    printStats(players, fout, true);
    fout << "######### SORTED BY BATTING AVERAGE #########" << endl;
    sort(players, 1); //sortByBattingAvg
    printStats(players, fout, true);
    PLAYER best_hitter = players[0];
    fout << "######### SORTED BY ON BASE PERCENTAGE #########" << endl;
    sort(players, 2); //sortByOnBasePercentage
    printStats(players, fout, true);
    if (no_statistics)
    {
      fout << "Statistics file is empty. There are no games played. "
           << "Therefore there is no best or worst player etc." << endl;
    }
    else
    {
        PLAYER best_base_runner = players[0];
        fout << "Best Hitter: " << best_hitter.lastName << " " << best_hitter.firstName << " " << best_hitter.base_avg << endl;
        fout << "Best Base Runner: " << best_base_runner.lastName << " " << best_base_runner.firstName << " " << best_base_runner.base_avg << endl;
        fout << "The team batting avg: " << getAvg(players, 0) << endl;
        fout << "The team on-base avg: " << getAvg(players, 1) << endl;
        fout << "Batting avg of the worst hitter: "
        << players[getWorst(players, 0)].firstName << " "
        << players[getWorst(players, 0)].lastName << " - with Batting Avg: "
        << players[getWorst(players, 0)].batting_avg << endl;
        fout << "On-base percentage of the worst base runner: "
        << players[getWorst(players, 1)].firstName << " "
        << players[getWorst(players, 1)].lastName << " - with on base percentage: "
        << players[getWorst(players, 1)].base_avg << endl;
        fout << "######### SORTED BY PLAYER NO #########" << endl;
        sort(players, 3); // sortByPlayerNo
        printStats(players, fout, false);
    }
    fout.close();
    return 0;
}

void exchange( PLAYER &a, PLAYER &b )
{
    PLAYER t = a;
    a = b;
    b = t;
}

void sort(PLAYER a[], int option)
{
    // option: 0 sortAlphabetically - option: 1 sortByBattingAvg
    // option: 2 sortByOnBasePercentage - option: 3 sortByPlayerNo
    bool sorted = false;
    int k = 0;
    while( !sorted )
    {
      sorted = true;
      for(int i = 0; i < MAX - 1; i++ )
      {
             if ( (option == 0 && strcmp(a[i].lastName, a[i+1].lastName) > 0 )
                 || (option == 1 && a[i].batting_avg < a[i+1].batting_avg )
                 || (option == 2 && a[i].base_avg < a[i+1].base_avg )
                 || (option == 3 && a[i].player_no > a[i+1].player_no) )
             {
                sorted = false;
                exchange( a[i], a[i+1] );
             }
      }
   }
}

int findPlayerLocInArray (PLAYER players[], int player_no)
{
    for (int i=0;i < MAX;i++)
        if (players[i].player_no == player_no)
            return i;
    return -1;
}

float getAvg(PLAYER players[], int option)
{
  // option 0 : batting_avg - option 1: onbase_avg
    float total = 0;
    for (int i=0;i<MAX;i++)
    {
        if (option == 0)
            total += players[i].batting_avg;
        else if (option == 1)
            total += players[i].base_avg;
    }
    return total/MAX;
}
int getWorst(PLAYER players[], int option)
{
    // option 0 : worst hitter - option 1: worst base runner.
    int index = 0;
    for (int i=1;i<MAX;i++)
    {
        if ( (players[index].batting_avg > players[i].batting_avg
              && players[i].batting_avg != 0 && option == 0)
            || (players[index].base_avg > players[i].base_avg
              && players[i].base_avg != 0 && option == 1))
            index = i;
    }
    return index;
}

void addGameToPlayer(PLAYER player[], int no, int hits, int walks, int outs)
{
    player[no].hits += hits;
    player[no].walks += walks;
    player[no].outs += outs;
    player[no].batting_avg = player[no].hits / (player[no].hits + player[no].outs);
    player[no].base_avg = ( (player[no].hits + player[no].walks) / (player[no].hits + player[no].outs + player[no].walks) );
    player[no].games_played++;
}

bool loadStats(PLAYER players[], istream &fin)
{
    int player, hits, walks, outs;
    int i = 0;
    char comma;
    while (fin)
    {
        fin >> player >> comma >> hits >> comma >> walks >> comma >> outs;
        // Array bounds check also end of data/sentinel check -1
        if (player  >= 0 && player < MAX)
        {
            addGameToPlayer(players, findPlayerLocInArray(players, player),
                            hits, walks, outs);
        i++;
        }
        if (i==0)
        {
            return true;
        }
        //fin.ignore(); // For Windows
    }
    return false;
}
void loadNames(PLAYER player[], istream &fin)
{
    int i = 0;
    while (fin && i < MAX)
    {
        fin >> player[i].firstName;
        fin >> player[i].lastName;
        fin.ignore();
        player[i].hits = 0;
        player[i].walks = 0;
        player[i].outs = 0;
        player[i].games_played = 0;
        player[i].batting_avg = 0;
        player[i].base_avg = 0;
        player[i].player_no = i+1;
        i++;
    }
}
void printStats(PLAYER players[], ostream &os, bool omitInactive)
{
    os << left << fixed << setprecision(3)
                << "P.No" << '\t'
                << setw(10) << "Lastname" << '\t'
                << setw(10) << "Firstname" << '\t'
                << setw(5) << "hits" << '\t'
                << setw(5) << "walks" << '\t'
                << setw(5) << "outs" << '\t'
                << setw(7) << "battAvg" << '\t'
                << setw(7) << "baseAvg" << '\t'
                << setw(4) << "gPlayed" << endl;
    for (int i=0;i<20;i++)
    {
        if (players[i].games_played != 0 && omitInactive
            || omitInactive == false)
        {
          os << players[i].player_no << '\t'
                    << setw(10) <<  players[i].lastName << '\t'
                    << setw(10) <<  players[i].firstName << '\t'
                    << setw(5) <<  players[i].hits << '\t'
                    << setw(5) << players[i].walks << '\t'
                    << setw(5) <<  players[i].outs << '\t'
                    << setw(5) <<  players[i].batting_avg << '\t'
                    << setw(5) << players[i].base_avg << '\t'
                    << setw(4) << players[i].games_played << '\t'
                    << endl;
        }
    }
}
