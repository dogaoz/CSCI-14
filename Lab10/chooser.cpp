//
// chooser.cpp
//
// Christian Prado, Doga Oz
// 4.23.18
// Chooser Program for Lab 10
// generate random number and have user guess within 8 tries.
//
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int K, guess, turns=1;
	bool found = false;	 //variables established
    //challenge prompt
	cout<<"You have 8 tries to guess my random number between 0-100."<<endl;
	srand(time(NULL) );				//create psuedo random number
	K= (rand()%100)+1;
	//give user 8 tries to find it
	//leave if answer is guessed
	while(turns<9 && found == false)
	{
		cout<<"Try number ("<< turns <<") ";
		cin>>guess;								//get guess
		if(guess == K)							//checks guess if correct
		{
			found = true;
		}
		else									//if not correct give advice
		{
			if(guess<K)		//check if guess bigger
			{
				cout << "Your guess is too small"<< endl << "\n";
				turns++;
			}
			else			//if not bigger, it must be smaller
			{
				cout<< "Your guess is too big"<< endl << "\n";
				turns++;
			}
		}
	}
	if (found == false)
	{
		cout << endl << 	//loss screen if key is never found
		"Sorry, you guessed eight times without getting the number, my number was "
		<< K << endl;
	}
	else
	{
		cout << endl << "Congratulations, you got my number in only " << turns
		<<" tries";		//win screen if key is found
	}
	return 0;
}


