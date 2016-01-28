#define HIGH_CARD 10
#define PAIR      20
#define TWO_PAIR  40
#define TRIO      250
#define STRAIGHT  300
#define FLUSH     400
#define FULL      520
#define POKER     640
#define S_FLUSH   760
#define R_FLUSH   1000


int hand(void);
int number(int card1, int card2);
int trio(int card1, int card2, int card);
int poker(int card1, int card2, int card);
int twoPair(int card1, int card2, int card);
int full(int card1, int card2, int card);
void output(int hand);

int hand()
{
	int suit1, suit2, number1, number2, numberCPU, numberCPU2, suitCPU, suitCPU2;
	int par, parPC;

	// User Cards
	suit1 = 3 + forbidden[0]%4;
    number1 = forbidden[0]/4 + 1;
	suit2 = 3 + forbidden[2]%4;
    number2 = forbidden[2]/4 + 1;

	// CPU Cards
	suitCPU = 3 + forbidden[1]%4;
    numberCPU = forbidden[1]/4 + 1;
	suitCPU2 = 3 + forbidden[3]%4;
    numberCPU2 = forbidden[3]/4 + 1;

	// USER Cards are checked
	par = number(number1, number2);
	cout << "You have ";
	output(par);

	// CPU Cards are checked
	parPC = number(numberCPU, numberCPU2);
	cout << "CPU has ";
	output(parPC);

	if ( par > parPC )
	{
		cout << "Yes!! You won! \n";
		return USER;
	}
	else
	{
		cout << "CPU won! \n";
		return CPU;
	}

}

int number(int card1, int card2)
{
	int i, j, a=0, b=0, c=0;

	if (card1 == card2)
		return trio( card1, card2, card1 );
	
	// Checks pairs on board
	for ( i=4; i<SIZE; i++)
		for ( j=(i+1); j<SIZE; j++)
			if ( (forbidden[i]/4 + 1) == (forbidden[j]/4 + 1) && (forbidden[j] != forbidden[i]) )
			    a = trio( card1, card2, (forbidden[i]/4 + 1) );
	//End of check board

	// Checks whole cards vs cards on the board
	for ( i=4; i<SIZE; i++)
	{
		if( card1 == (forbidden[i]/4 + 1) )
			b = trio( card1, card2, (forbidden[i]/4 + 1) );
		if( card2 == (forbidden[i]/4 + 1) )
			c = trio( card1, card2, (forbidden[i]/4 + 1) );
	}

	if( a >= b && a >= c )
		return a;
	else if( b >= a && b >= c )
		return b;
	else if( c >= a && c >= b )
		return c;
	else 
	    return HIGH_CARD;
}

int trio(int card1, int card2, int card)
{
	int i, count=0;
	
	// Checks pairs on board
	for ( i=4; i<SIZE; i++)
		if ( (forbidden[i]/4 + 1) == card )
		{
		    count++;
			if ( count == 3 )
				return poker( card1, card2, card );
		}

	//End of check board

	// Checks whole cards
	if( card1 == card )
	{
		    count++;
			if ( count == 3 )
				return poker( card1, card2, card );
	}
	if( card2 == card )
	{
	    count++;
		if ( count == 3 )
			return poker( card1, card2, card );
	}

	return twoPair( card1, card2, card );
}

int poker(int card1, int card2, int card)
{
	int i, count=0;
	
	// Checks pairs on board
	for ( i=4; i<SIZE; i++)
		if ( (forbidden[i]/4 + 1) == card )
		{
		    count++;
			if ( count == 4 )
				return POKER+card;
		}

	//End of check board

	// Checks whole cards
	if( card1 == card )
	{
		    count++;
			if ( count == 4 )
				return POKER+card;
	}
	if( card2 == card )
	{
	    count++;
		if ( count == 4 )
			return POKER+card;
	}

	return full( card1, card2, card );
}

int twoPair(int card1, int card2, int card)
{
	int i, j, par=card, par2;

	if (card1 == card2 && card1 != par )
		return TWO_PAIR;
	
	// Checks pairs on board
	for ( i=4; i<SIZE; i++)
		for ( j=(i+1); j<SIZE; j++)
			if ( (forbidden[i]/4 + 1) == (forbidden[j]/4 + 1) && (forbidden[j] != forbidden[i])
				&& (forbidden[i]/4 + 1) != par )
			{
				par2 = (forbidden[i]/4 + 1);
				if ( par == 1 )
					par = 15;
				else if ( par2 == 1 )
					par2 = 15;
				
				return TWO_PAIR+(13*par)+(par2);
			}
	//End of check board

	// Checks whole cards vs cards on the board
	for ( i=4; i<SIZE; i++)
	{
		if( card1 == (forbidden[i]/4 + 1) && card1 != par )
		{
				par2 = (forbidden[i]/4 + 1);
				if ( par == 1 )
					par = 15;
				else if ( par2 == 1 )
					par2 = 15;
				
				return TWO_PAIR+(13*par)+(par2);
		}
		if( card2 == (forbidden[i]/4 + 1) && card2 != par )
		{
				par2 = (forbidden[i]/4 + 1);
				if ( par == 1 )
					par = 15;
				else if ( par2 == 1 )
					par2 = 15;
				
				return TWO_PAIR+(13*par)+(par2);
		}
	}

	if ( card == 1 )
		return PAIR+15;
	else
		return PAIR+card;
}

int full(int card1, int card2, int card)
{
	int i, j, trio=card;

	if (card1 == card2 && card1 != trio )
		return FULL;
	
	// Checks pairs on board
	for ( i=4; i<SIZE; i++)
		for ( j=(i+1); j<SIZE; j++)
			if ( (forbidden[i]/4 + 1) == (forbidden[j]/4 + 1) && (forbidden[j] != forbidden[i])
				&& (forbidden[i]/4 + 1) != trio )
			    return FULL;
	//End of check board

	// Checks whole cards vs cards on the board
	for ( i=4; i<SIZE; i++)
	{
		if( card1 == (forbidden[i]/4 + 1) && card1 != trio )
			return FULL;
		if( card2 == (forbidden[i]/4 + 1) && card2 != trio )
			return FULL;
	}

	return TRIO+card;
}

// Neatly display who have which hand
void output(int hand)
{
	int pair1, pair2;

	if( hand >= PAIR && hand < TWO_PAIR)
		cout << "a pair of " << hand-PAIR <<"!\n";
	else if( hand >= TWO_PAIR && hand < TRIO)
	{
		pair1 = (hand-TWO_PAIR)/13;
	    pair2 = (hand-TWO_PAIR)%13;
		cout << "two pairs, " << pair1 <<" and " << pair2 << "!\n";
	}
	else if( hand >= TRIO && hand < FULL)
		cout << "three of a kind, " << hand-TRIO <<"!\n";
	else if( hand >= FULL && hand < POKER)
		cout << "Full House!\n";
	else if( hand >= POKER && hand < S_FLUSH)
		cout << "four of a kind, " << hand-POKER <<"!\n";
	else 
		cout << "shit!\n";
}
