/************************************************************************
 Carlos Chitty
 Data Structures - Lab 7 Non-Primitive Data types in Java.
 Program determines if a word is a palindrome or not.
*/
import java.io.*;
class Lab7{
 
   public static void main(String[] args) throws IOException
	{
		char[] forth;
		char[] back;
		int size;
		boolean palindrome = true;
						
		System.out.println("Enter the length of the word: ");
	   size = MlmIn.readInt();
		forth = new char[ size*2 ];	
		back = new char[ size*2 ];
		System.out.println("Enter the word: ");
		
		for( int i=0; i < size; i++ )
		{
			forth[i] = MlmIn.readChar();
			back[ size-1-i ] = forth[i];
		}
		System.in.skip(2);
		
		// Test to see if the word is a palindrome.
		for( int i=0; i < size; i++ )
		{
			if( forth[i] != back[i] )
				palindrome = false;
		}
				
		if ( palindrome ) 
			System.out.println("The word entered is a palindrome!");
		else
			System.out.println("The word entered is NOT a palindrome!");

	}
}