#include "poker.h"
#include "winner.h"

	int main(){

	int won;
	char again='n';

	cout<< "Poker Game:\n\nThis is the Official Beta Version 1.0 of the game";
	cout<< " 'Simplified Texas Hold'em'\nin this game there is no Straigh or Flush,";
	cout<< " the computer will always call your\nbet. There is no raise or fold.\n\n";
	system("pause");

  do{
	  
	system("CLS");
	// Antes
	potSize = 10;
	CPUchips -= 5;
	chips -= 5;

    forbidden[0] = barajas();
    forbidden[2] = barajas();
    forbidden[1] = barajas();
    forbidden[3] = barajas();

	
	cout << "\t\tPot Size = $" << potSize << endl;
	// Reparte las cartas
    user(0,2);
	cout << "\t\tUser chips = $" << chips << endl;
	cpu();
	cout << "\t\tCPU chips = $" << CPUchips << endl;
	
	// Betting round 1
	betTime();
	if ( chips == 0 || CPUchips == 0 )
	{
		printInfo(FLOP);
		printInfo(TURN);
		printInfo(RIVER);
	}
	else
	{
		printInfo(FLOP);
	
		// Betting round 2
		betTime();
		if ( chips == 0 || CPUchips == 0 )
		{
			printInfo(TURN);
		    printInfo(RIVER);
		}
		else
		{
			printInfo(TURN);
		    // Betting round 3
	        betTime();
			printInfo(RIVER);
			if ( chips == 0 || CPUchips == 0 )
				;
			else
			{
				// Final betting round
            	betTime();
	            printInfo(RIVER);
			}
		}
	}

	system("pause");
	system("CLS");
	cout << "\t\tPot Size = $" << potSize << endl;
	river();
	user(0,2);
	cout << "\t\tUser chips = $" << chips << endl;
	user(1,3);
	cout << "\t\tCPU chips = $" << CPUchips << endl;

    won=hand();

	winner(won);

	if ( chips == 0 )
	{
		cout << "You lost all your chips.\nBye\n";
		again ='n';
	}
	else if ( CPUchips == 0 )
	{
		cout << "WOW! you took all of the CPU Chips great!\nYou're walking away with $" << chips << endl;
		again ='n';
	}
	else
	{
		cout << "Press 'y' to play next hand\n";
	    cin >> again;
	}
	  
  }while(again=='y' || again=='Y');

  return 0;
}
