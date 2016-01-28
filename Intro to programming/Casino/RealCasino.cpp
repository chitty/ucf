/* Carlos Chitty
   COP 3223 section 0002
   Spring 2006
   Introduction to C - Programming Assignment #4
   Program simulates a casino for a single player
	Craps and Arup's Game are played at the casino */
	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

/* Functions Prototype */
void instructions();
void title(void);
void dados(int suma); /* Chitosky's implementation */
int pairofdice(void);  /* dice */
int craps();           /* craps */
int arupsdice();       /* Arup Dice */
int buychips(int *cash_ptr);
int sellchips(int numchips);
void statusreport(int numchips, int cash);

int main() {
  int y, x, choices, cash, chips=0, chips4sale, chips2bet;
  char choice;
  int total_cash = 1000;
  
  title();
  printf("\n\n\t\t\t\tBy:   CARLOS CHITTY\n");
  printf("\n\t\t\t\tWELCOME !!\n");
  
  do{  
  
  printf("\n\nHere are your choices:\n");
  printf("1) Buy Chips\n2) Sell Chips\n3) Play Craps\n4) Play Arup's Game of Dice\n5) Status Report\n6) Quit\n");
  printf(" \t--- for instructions press 'i' --- \n\n");
  scanf(" %c", &choice);

  if (choice == '1'){
    printf("How much cash do you want to spend for chips?\n");
    scanf("%d", &cash);
    if (cash > total_cash)
      printf("Sorry, you do not have that much money. No chips bought.\n");
	 else{
	   total_cash -= cash;
	   chips += buychips(&cash);
      total_cash += cash;
	 }
  }
  
  else if (choice == '2'){
    printf("How many chips do you want to sell?\n");
	 scanf("%d", &chips4sale);
	 if (chips4sale > chips)
	   printf("Sorry, you do not have that many chips. No chips sold.\n");
    else{
	   total_cash += sellchips(chips4sale);
		chips -= chips4sale;
	 }
  }		

 else if (choice == '3'){
   /* Craps Game */
   printf("How many chips would you like to bet?\n");
   scanf("%d", &chips2bet);
   if (chips2bet > chips)
     printf("Sorry, you do not have that many chips to bet. No game played.\n");
	else if(chips2bet <= 0)
	  printf("Sorry, that is not allowed. No game played.\n");
   else{
     x = craps();
     if (x == 1){
       printf("You win!\n");
	    chips += chips2bet;
	  }
     else{
       printf("Sorry, you have lost.\n");
	    chips -= chips2bet;
	  }
   }  
  /* END of Craps Game */
 }
 
 else if (choice == '4'){
   /* Arup Dice Game */
   printf("How many chips would you like to bet?\n");
   scanf("%d", &chips2bet);
   if (chips2bet > chips)
     printf("Sorry, you do not have that many chips to bet. No game played.\n");
	else if(chips2bet <= 0)
	  printf("Sorry, that is not allowed. No game played.\n");
	else{
     y = arupsdice();
     if (y == 1){
       printf("You win!\n");
		 chips += chips2bet;
	  }
     else{
       printf("Sorry, you have lost.\n");
		 chips -= chips2bet;
	  }
   }
   /* END of Arup Dice Game */
  }
  
  else if (choice == '5'){
    statusreport(chips, total_cash);
  }
  else if (choice == '6'){
    total_cash += sellchips(chips);
    printf("After selling your chips, you have $%d. Thanks for playing!\n", total_cash);  
	 break;
  }
  else if (choice == 'i' || choice == 'I' )
    instructions();
  else{
    printf("ERROR -- Invalid Input\n");
    continue;
    }
  	 
  }while (choice != '6');
    
  return 0;
}


// CHITOSKYS DADOSKYS
void dados(int suma){
     if(suma == 2){
	   // UNO
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 201,205,205,205,205,205,187,201,205,205,205,205,205,187);
      printf("\t%c     %c  %c     %c\n", 186,186,186,186);
      printf("\t%c  %c  %c  %c  %c  %c\n", 186,249,186,186,249,186);
      printf("\t%c     %c  %c     %c\n", 186,186,186,186);
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 200,205,205,205,205,205,188,200,205,205,205,205,205,188);
	 }
	 else if(suma == 3){
	   // TRES
      printf("\t%c%c%c%c%c%c%c\n", 201,205,205,205,205,205,187);
      printf("\t%c%c    %c\n\t%c  %c  %c\n\t%c    %c%c\n", 186,249,186,186,249,186,186,249,186);
      printf("\t%c%c%c%c%c%c%c\n", 200,205,205,205,205,205,188);
	 }
	 else if(suma == 4){
	   printf("\t%c%c%c%c%c%c%c\n", 201,205,205,205,205,205,187);
      printf("\t%c%c   %c%c\n\t%c     %c\n\t%c%c   %c%c\n", 186,249,249,186,186,186,186,249,249,186);
      printf("\t%c%c%c%c%c%c%c\n", 200,205,205,205,205,205,188);
	 }
	 else if(suma == 5){
	   // CINCO
      printf("\t%c%c%c%c%c%c%c\n", 201,205,205,205,205,205,187);
      printf("\t%c%c   %c%c\n\t%c  %c  %c\n\t%c%c   %c%c\n", 186,249,249,186,186,249,186,186,249,249,186);
      printf("\t%c%c%c%c%c%c%c\n", 200,205,205,205,205,205,188);
	 }
	 else if(suma == 6){
	   // SEIS
      printf("\t%c%c%c%c%c%c%c\n", 201,205,205,205,205,205,187);
      printf("\t%c%c   %c%c\n\t%c%c   %c%c\n\t%c%c   %c%c\n", 186,249,249,186,186,249,249,186,186,249,249,186);
      printf("\t%c%c%c%c%c%c%c\n", 200,205,205,205,205,205,188);
	 }
	 else if(suma == 7){
	   // SIETE == DOS Y CINCO
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 201,205,205,205,205,205,187,201,205,205,205,205,205,187);
      printf("\t%c%c   %c%c  %c%c    %c\n", 186,249,249,186,186,249,186);
      printf("\t%c  %c  %c  %c     %c\n", 186,249,186,186,186);
      printf("\t%c%c   %c%c  %c    %c%c\n", 186,249,249,186,186,249,186);
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 200,205,205,205,205,205,188,200,205,205,205,205,205,188);
	 }
	 else if(suma == 8){
	   // OCHO == TRES Y CINCO
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 201,205,205,205,205,205,187,201,205,205,205,205,205,187);
      printf("\t%c%c   %c%c  %c%c    %c\n", 186,249,249,186,186,249,186);
      printf("\t%c  %c  %c  %c  %c  %c\n", 186,249,186,186,249,186);
      printf("\t%c%c   %c%c  %c    %c%c\n", 186,249,249,186,186,249,186);
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 200,205,205,205,205,205,188,200,205,205,205,205,205,188);
	 }
	 else if(suma == 9){
	   // NUEVE == TRES Y SEIS
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 201,205,205,205,205,205,187,201,205,205,205,205,205,187);
      printf("\t%c%c   %c%c  %c%c    %c\n", 186,249,249,186,186,249,186);
      printf("\t%c%c   %c%c  %c  %c  %c\n", 186,249,249,186,186,249,186);
      printf("\t%c%c   %c%c  %c    %c%c\n", 186,249,249,186,186,249,186);
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 200,205,205,205,205,205,188,200,205,205,205,205,205,188);
	 }
	 else if(suma == 10){
	   // DIES == CUATRO Y SEIS
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 201,205,205,205,205,205,187,201,205,205,205,205,205,187);
      printf("\t%c%c   %c%c  %c%c   %c%c\n", 186,249,249,186,186,249,249,186);
      printf("\t%c%c   %c%c  %c     %c\n", 186,249,249,186,186,186);
      printf("\t%c%c   %c%c  %c%c   %c%c\n", 186,249,249,186,186,249,249,186);
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 200,205,205,205,205,205,188,200,205,205,205,205,205,188);
	 }
	 else if(suma == 11){
	   // ONCE
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 201,205,205,205,205,205,187,201,205,205,205,205,205,187);
      printf("\t%c%c   %c%c  %c%c   %c%c\n", 186,249,249,186,186,249,249,186);
      printf("\t%c%c   %c%c  %c  %c  %c\n", 186,249,249,186,186,249,186);
      printf("\t%c%c   %c%c  %c%c   %c%c\n", 186,249,249,186,186,249,249,186);
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 200,205,205,205,205,205,188,200,205,205,205,205,205,188);
	 }
	 else if(suma == 12){
	   // DOCE
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 201,205,205,205,205,205,187,201,205,205,205,205,205,187);
      printf("\t%c%c   %c%c  %c%c   %c%c\n", 186,249,249,186,186,249,249,186);
      printf("\t%c%c   %c%c  %c%c   %c%c\n", 186,249,249,186,186,249,249,186);
      printf("\t%c%c   %c%c  %c%c   %c%c\n", 186,249,249,186,186,249,249,186);
      printf("\t%c%c%c%c%c%c%c  %c%c%c%c%c%c%c\n", 200,205,205,205,205,205,188,200,205,205,205,205,205,188);
	 }
	 else
	   printf("\n");	 
  

}

// Precondition: None.
// Postcondition: Generates two random numbers in between 
//             one and six inclusive and returns their sum.
int pairofdice(){
  int sum;
  char r;
  scanf("%c", &r);
  
  srand(time(0));	 	 
  sum = 2 + (rand()%6) + (rand()%6);
   	 	 
  return sum;
}

// Precondition: None.
// Postcondition: Plays one game of Craps and returns 
//                PLAYER_WON if the player won and 
//                PLAYER_LOST if they lost.
int craps(){
  int PLAYER_WON=1, PLAYER_LOST=0, k=0, roll;
  char r;
  
  printf("Hit enter for your first roll.\n");
  scanf("%c", &r);
  roll = pairofdice();
  dados(roll);
  printf("You rolled a %d \n", roll);
  if ( (roll == 7) || (roll == 11) )
    return PLAYER_WON;
  else if ( (roll == 2) || (roll == 3) || (roll == 12) )
    return PLAYER_LOST;
  else {
    k = roll;
	 while ( (pairofdice() != 7) || (pairofdice() != k) ) {
	   printf("Hit enter for your next roll.\n");
      roll = pairofdice();
      dados(roll);
      printf("You rolled a %d \n", roll);

			 
	   if (roll == 7)
	     return PLAYER_LOST;
	   else if (roll == k)
	     return PLAYER_WON;
	 	 	 
    }
  }
}

// Precondition: None.
// Postcondition: Plays one game of Arup's game of dice and
//                returns PLAYER_WON if the player won and 
//                returns PLAYER+LOST if they lost.
int arupsdice(){
  int PLAYER_WON=1, PLAYER_LOST=0, k=0, roll, x;
  char r;
  
  printf("Hit enter for your first roll.\n");
  scanf("%c", &r);
  roll = pairofdice();
  dados(roll);
  printf("You rolled a %d \n", roll);
  
  if ( (roll == 12) || (roll == 11) )
    return PLAYER_WON;
  else if ( (roll == 2) )
    return PLAYER_LOST;
  else{
    k = roll;
	 printf("Hit enter for your next roll.\n");
	 scanf("%c", &r);
    roll = pairofdice();
    dados(roll);
    printf("You rolled a %d \n", roll);
 
	 if ( roll > k)
	   return PLAYER_WON;
    else
	   return PLAYER_LOST;
  }
}

// Precondition: cash is the address of the variable 
//               storing the amount of money the user  
//               wants to spend on chips.
// Postcondition: The number of chips purchased is returned
//                and the variable storing the amount of 
//                money the user paid for chips is adjusted
//                to equal the change left over after the
//                transaction.
int buychips(int *cash_ptr){
  int chips;

  chips = (*cash_ptr)/11;
  *cash_ptr = (*cash_ptr)%11;

  return chips;
}

// Preconditions: numchips > 0.
// Postconditions: Returns the cash obtained for selling 
//                 numchips number of chips.
int sellchips(int numchips){

  return (numchips*10);
}

// Precondition: The first parameter is the number of 
//               chips the user has, the second is how
//               much cash they currently have.
// Postcondition: A report detailing the number of chips 
//                and the amount of cash the user has is
//                printed.
void statusreport(int numchips, int cash){
  printf("You currently have $%d left and %d chips. \n", cash, numchips);
}


// CCH
void title(){
  FILE *ifp;
  char num;
  
  ifp = fopen("casino.txt","r");
  
  while (num != '.' ){
    fscanf(ifp, "%c", &num);
    printf("%c", num);
  }
}


// INSTRUCTIONS 
void instructions(){
  FILE *ifp;
  char ins, w;
  
  printf("HOW TO PLAY:\n");
  printf("Press 'a' for Arup's Game\nPress 'c' for Craps\n");
  scanf(" %c", &w);
  if ( w == 'a' || w == 'A' )
    ifp = fopen("iarup.txt","r");
  else if ( w == 'c' || w == 'C' )
    ifp = fopen("icraps.txt","r");
  else
    ifp = fopen("casino.txt","r");
  
  while (ins != '.' ){
    fscanf(ifp, "%c", &ins);
    printf("%c", ins);
  }
  
  printf("\n\nPress any key to display the Main Menu again\n");
  scanf(" %c", &w);
}