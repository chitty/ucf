/**********************************************************************
 Carlos Chitty
 Data Structures - Lab 7.4 Non-Primitive Data types in Java.
 Program determines if a word is a palindrome or not. Using vectors
*/
import java.io.*;
import java.util.*;
class Lab7_4{
 
  public static void main(String[] args) throws IOException
  {
	 Vector v;
	 v = new Vector(5); 
	 boolean palindrome = true;
	 char a;
	 int ans=1;		
		
	 while ( ans == 1 )
    {
		System.out.println("Enter the word (place a period at the end): ");
		do{
			a = MlmIn.readChar();
			if ( a != '.' )
				v.addElement( new Character(a) );
			else
				break;
		}while( a != '.' );
		System.in.skip(2);
		
   	// Test to see if the word is a palindrome.
    	for( int i=0; i < v.size(); i++ )
		{
			System.out.print(v.elementAt(v.size()-1-i));
			if( ( (Character)v.elementAt(i)).charValue() != ( (Character)v.elementAt(v.size()-1-i) ).charValue() )
				palindrome = false;
		}
		
		if ( palindrome ) 
			System.out.println("\nThe word entered is a palindrome!");
		else
			System.out.println("\nThe word entered is NOT a palindrome!");
		
		System.out.println("Would you like to enter another word? (1=yes, 0=no)");	
		ans = MlmIn.readInt();
		v.removeAllElements();
		palindrome = true;
	 }
		
  }
}