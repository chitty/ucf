// Header by Carlos Chitty
// Header generates random cards and neatly prints them out to the screen
// Works great for a Texas Hold'em program

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdlib>
using::srand;
using::rand;
#include <ctime>
using::time;
#include <iomanip>
using std::setw;

#define FLOP 1
#define TURN 2
#define RIVER 3
#define USER  1
#define CPU   0
#define SIZE  9

int forbidden[SIZE] = {0};
int chips = 1000, CPUchips = 1000, potSize = 10;

int  barajas();
int  equal(int numero);
void flop();
void turn();
void river();
void printFlop(int a,int b,int c);
void printInfo(int x);
void print(int d);
void top();
void bottom();
void printTopCorner(int card, int who);
void printBCorner(int card, int who);
void printSuit(int card);
void cpu();
void user(int card1, int card2);
void winner(int won);
void betTime();
int bet(int Chips);

// Function generates a random card and returns it
int barajas(){
  int suit, card, number;

  srand(time(0));
   
  do{ 

  card = 11*rand()%52;
  suit = 3 + card%4;
  number = card/4 + 1;
  
  }while(equal(card)); 
  

  return card;
}

// Function checks is the card being generated is equal to an already generated card
int equal(int numero){
   int i;
    for(i=0; i<SIZE; i++){
	  if (forbidden[i] == numero)
        return 1;
    }
    return 0;
}


// FLOP
void flop(){
  forbidden[4] = barajas();
  forbidden[5] = barajas();
  forbidden[6] = barajas();
  
  cout << "FLOP: \n";  
  printFlop(forbidden[4],forbidden[5],forbidden[6]);
  cout << "\n";
}

void printFlop(int a,int b,int c)
{
	top(),top(),top();
	cout <<"\n";
	printTopCorner(forbidden[4],USER),printTopCorner(forbidden[5],USER),printTopCorner(forbidden[6],USER);
	cout <<"\n";
	printSuit(forbidden[4]),printSuit(forbidden[5]),printSuit(forbidden[6]);
	cout <<"\n";
	printBCorner(forbidden[4],USER),printBCorner(forbidden[5],USER),printBCorner(forbidden[6],USER);
	cout <<"\n";
	bottom(),bottom(),bottom();      
}

// TURN
void turn(){
	forbidden[7] = barajas();
	forbidden[8] = barajas(); // Generates the card for the river
	cout << "TURN: \n";
	top(),top(),top(),top();
	cout <<"\n";
	printTopCorner(forbidden[4],USER),printTopCorner(forbidden[5],USER),printTopCorner(forbidden[6],USER),printTopCorner(forbidden[7],USER);
	cout <<"\n";
	printSuit(forbidden[4]),printSuit(forbidden[5]),printSuit(forbidden[6]),printSuit(forbidden[7]);
	cout <<"\n";
	printBCorner(forbidden[4],USER),printBCorner(forbidden[5],USER),printBCorner(forbidden[6],USER),printBCorner(forbidden[7],USER);
	cout <<"\n";
	bottom(),bottom(),bottom(),bottom(); 
	cout <<"\n";
}

// RIVER
void river(){
	cout << "RIVER: \n";
	top(),top(),top(),top(),top();
	cout <<"\n";
	printTopCorner(forbidden[4],USER),printTopCorner(forbidden[5],USER),printTopCorner(forbidden[6],USER);
	printTopCorner(forbidden[7],USER),printTopCorner(forbidden[8],USER);
	cout <<"\n";
	printSuit(forbidden[4]),printSuit(forbidden[5]),printSuit(forbidden[6]),printSuit(forbidden[7]);
	printSuit(forbidden[8]);
	cout <<"\n";
	printBCorner(forbidden[4],USER),printBCorner(forbidden[5],USER),printBCorner(forbidden[6],USER);
	printBCorner(forbidden[7],USER),printBCorner(forbidden[8],USER);
	cout <<"\n";
	bottom(),bottom(),bottom(),bottom(),bottom(); 
	cout <<"\n";
}

void printInfo(int x)
{
	system("pause");
	system("CLS");
	cout << "\t\tPot Size = $" << potSize << endl;
	switch(x)
	{
		case 1:
			{
				flop();
				break;
			}
		case 2:
			{
			    turn();
				break;
			}
		case 3:
			{
			    river();
				break;
			}
	};
	user(0,2);
	cout << "\t\tUser chips = $" << chips << endl;
	cpu();
	cout << "\t\tCPU chips = $" << CPUchips << endl;
}


/* *** Functions that neatly print outs cards *** */

void top()
{
	  cout << (char)201<<(char)205<<(char)205<<(char)205<<(char)187<<" ";
}

void bottom()
{
	  cout << (char)200<<(char)205<<(char)205<<(char)205<<(char)188<<" ";
}

void printTopCorner(int card, int who)
{
	int suit, number;

	suit = 3 + card%4;
    number = card/4 + 1;

	  
	if (number == 11)
		  cout << (char)186 << "J  " << (char)186 <<" ";
    else if (number == 12)
	  	  cout << (char)186 << "Q  " << (char)186 <<" ";
	else if (number == 13)
		  cout << (char)186 << "K  " << (char)186 <<" ";
	else if (number == 1)
		  cout << (char)186 << "A  " << (char)186 <<" ";
 	else if (number == 10)
		  cout << (char)186 << setw(2) << number <<  setw(2) << (char)186 <<" ";
    else
		  cout << (char)186 << number <<  setw(3) << (char)186 <<" ";
}

void printBCorner(int card, int who)
{
	int suit, number;

	suit = 3 + card%4;
    number = card/4 + 1;
	  
    if (number == 11)
	      cout << (char)186 << "  J" << (char)186 <<" ";
    else if (number == 12)
	      cout << (char)186 << "  Q" << (char)186 <<" ";
    else if (number == 13)
	      cout << (char)186 << "  K" << (char)186 <<" ";
	else if (number == 1)
		  cout << (char)186 << "  A" << (char)186 <<" ";
    else if (number == 10)
	      cout << (char)186 << setw(3) << number << (char)186 <<" ";
    else
	      cout << (char)186 << setw(3) << number << (char)186<<" ";
}

void printSuit(int card)
{
	int suit;

	suit = 3 + card%4;
	cout << (char)186 << setw(2) << (char)suit << setw(2)<< (char)186 <<" ";
}

void cpu()
{
	  cout << "CPU Cards: " << endl;
	  cout << (char)201<<(char)205<<(char)187<<" "<<(char)201<<(char)205<<(char)187<<endl;
	  cout << (char)186 << " " << (char)186<<" "<<(char)186 << " " << (char)186<< endl;
	  cout << (char)200<<(char)205<<(char)188<<" "<<(char)200<<(char)205<<(char)188<< endl;
}

void user(int card1, int card2)
{
	if (card1 == 0)
		cout << "\nUSER Cards: " << endl;
	else
		cout << "\nCPU Cards: " <<endl;
	top(),top();
	cout <<"\n";
	printTopCorner(forbidden[card1],USER),printTopCorner(forbidden[card2],USER);
	cout <<"\n";
	printSuit(forbidden[card1]),printSuit(forbidden[card2]);
	cout <<"\n";
	printBCorner(forbidden[card1],USER),printBCorner(forbidden[card2],USER);
	cout <<"\n";
	bottom(),bottom();
	cout <<"\n";
}

/* ************* *\
   *    BETS   *
\* ************* */

int bet(int Chips)
{
	int betAmount;
	cout << "It's your time to act, press 0 to check, f to fold or just\nEnter bet: ";
	
	do
	{
		cin >> betAmount;
		if ( betAmount>Chips || (betAmount!=0 && betAmount<5) || betAmount<0 )
			cout << "Invalid bet amount!\n";
		else if ( betAmount >= CPUchips )
		{
			betAmount = CPUchips;
	    	cout << "Oh baby CPU is all in!\n";
		}
		else if ( betAmount == Chips )
	    	cout << "Oh baby your all in!\n";
	    else
			if ( betAmount > 0)
				cout << "You betted $" << betAmount << endl;
			else 
				cout << "You checked\n";

	}while( betAmount>Chips || (betAmount!=0 && betAmount<5) );
	
	return betAmount;
}

void betTime()
{
	int bets;

	bets = bet(chips);
	chips -= bets;
	CPUchips -= bets;
	potSize += 2*bets;
}


/* ************* *\
 *     WINNER    *
\* ************* */

void winner(int won)
{
	if ( won == USER )
	{
		chips += potSize;
		cout << "\n\t\t\t********************\n\t\t\t  CONGRATULATIONS! \n\t\t\t   You Won $" << potSize; 
		cout <<"!  \n\t\t\t********************\n\n";
	}
	else if ( won == CPU )
	{
		CPUchips += potSize;
		cout << "You lost! CPU Won $" << potSize << endl;
	}
	else
	{
		chips += potSize/2;
	    CPUchips += potSize/2;
	}
}