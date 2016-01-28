
int bet(int Chips)
{
	int bet;
	cout << "It's your time to act, press 0 to check, f to fold or just\nEnter bet: ";
	
	do
	{
		cin >> bet;
		if ( bet>Chips || (bet!=0 && bet<5) )
			cout << "Invalid bet amount!\n";
		else if ( bet == Chips )
	    	cout << "Oh baby your all in!\n";
	    else
		    cout << "You betted " << bet << endl;
	}while( bet>Chips || (bet!=0 && bet<5) );
	
	return bet;

}
