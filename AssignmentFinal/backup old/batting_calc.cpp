//
// batting_calc.cpp
//
// Doga Ozkaracaabatlioglu
// 5/8/2018
// Final Assignment
//
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
void loadStats(PLAYER players[], istream &fin);
void loadNames(PLAYER player[], istream &fin);
void printStats(PLAYER players[], ostream &os);
const int MAX = 20;
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
      //sorted
   }
}



int findPlayerLocInArray (PLAYER players[], int player_no)
{
    for (int i=0;i < MAX;i++)
        if (players[i].player_no == player_no)
            return i;
    return -1;
}


int main()
{
    ifstream fin;
    PLAYER players[MAX];
    string ifilename_players, ifilename_stats = "";
    string output_filename = "output_data.txt";
    cout << "Enter file name players: " << endl;
    //cin >> ifilename_players;
    ifilename_players = "players_team1.txt";
    fin.open(ifilename_players);
    // Check for open failure.
    if( !fin )
    {
       cout << "Input file open failed\n";
       return -2;
    }
    int i = 0;

    loadNames(players, fin);
    fin.close();
    cout << "Enter file name for stats: " << endl;
    //cin >> ifilename_stats;
    ifilename_stats = "stats_season1.txt";
    fin.open(ifilename_stats);
    loadStats(players, fin);
    fin.close();

    // Print out everything
    printStats(players,cout);
    cout << "Input file name for players: " << ifilename_players << endl;
    cout << "Input file name for statistics: " << ifilename_stats << endl;
    cout << "Output filename: " << output_filename << endl;
    cout << "#########" << endl;
    cout << "SORTED BY ALPHABETICALLY" << endl;
    cout << "#########" << endl;
    sort(players, 0); // sortAlphabetically
    printStats(players,cout);
    cout << "#########" << endl;
    cout << "SORTED BY BATTING AVERAGE" << endl;
    cout << "#########" << endl;
    sort(players, 1); //sortByBattingAvg
    printStats(players,cout);
    PLAYER best_hitter = players[0];
    cout << "#########" << endl;
    cout << "SORTED BY ON BASE PERCENTAGE" << endl;
    cout << "#########" << endl;
    sort(players, 2); //sortByOnBasePercentage
    printStats(players,cout);
    PLAYER best_base_runner = players[0];
    cout << "Best Hitter: " << best_hitter.lastName << " " << best_hitter.firstName << " " << best_hitter.base_avg << endl;
    cout << "Best Base Runner: " << best_base_runner.lastName << " " << best_base_runner.firstName << " " << best_base_runner.base_avg << endl;
    cout << "The team batting avg: " << "123" << endl;
    cout << "The team on-base avg" << "456" << endl;
    cout << "Batting avg of the worst hitter: " << "Name" << " Lastname" << " Batting avg" << endl;
    cout << "On-base percentage of the worst base runner" << "Name" << " Lastname" << " on-base percentage" << endl;
    cout << "#########" << endl;
    cout << "SORTED BY PLAYER NO" << endl;
    cout << "#########" << endl;
    sort(players, 3); // sortByPlayerNo
    printStats(players,cout);

    return 0;
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

void loadStats(PLAYER players[], istream &fin)
{
    int player, hits, walks, outs;
    char comma;
    while (fin)
    {
            fin >> player >> comma >> hits >> comma >> walks >> comma >> outs;
            // Array bounds check
            if (player  >= 0 && player < MAX)
            {
            addGameToPlayer(players, findPlayerLocInArray(players, player), hits, walks, outs);
            }
            //fin.ignore(); // For Windows
        }
}
void loadNames(PLAYER player[], istream &fin)
{
    int i = 0;
    while (fin && i < MAX)
    {
        fin >> player[i].lastName;
        fin >> player[i].firstName;
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
void printStats(PLAYER players[], ostream &os)
{
    os << left << fixed << setprecision(3)
                << "Index" << '\t' << setw(5) << "No" << '\t'
                << setw(10) << "Lastname" << '\t'
                << setw(10) << "Firstname" << '\t'
                << setw(5) << "hits" << '\t'
                << setw(5) << "walks" << '\t'
                << setw(5) << "outs" << '\t'
                << setw(9) << "batt_avg" << '\t'
                << setw(8) << "base_avg" << '\t'
                << setw(5) << "games_played" << endl;
    for (int i=0;i<20;i++)
    {
        os << i << '\t' << setw(5) << players[i].player_no << '\t'
                  << setw(10) <<  players[i].lastName << '\t'
                  << setw(10) <<  players[i].firstName << '\t'
                  << setw(5) <<  players[i].hits << '\t'
                  << setw(5) << players[i].walks << '\t'
                  << setw(5) <<  players[i].outs << '\t'
                  << setw(9) <<  players[i].batting_avg << '\t'
                  << setw(8) << players[i].base_avg << '\t'
                  << setw(5) << players[i].games_played << '\t'
                  << endl;
    }
}
