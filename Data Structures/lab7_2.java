/*********************************************************************
 Carlos Chitty
 Data Structures - Lab 7.2 Non-Primitive Data types in Java.
 Program keeps scores of studens and calculates final grade.
*/
import java.io.*;
class Lab7_2{
 
   public static void main(String[] args)
	{
		double[][] scores;
		int size;
						
		System.out.println("Enter the number of students: ");
	   size = MlmIn.readInt();
		scores = new double[size][4];	
	
		for( int i=0; i<size; i++ )
		{			
			System.out.println("Enter Midterm grade for student "+i );
			scores[i][0] = MlmIn.readDouble();
			System.out.println("Enter Final test grade for student "+i );
			scores[i][1] = MlmIn.readDouble();
			System.out.println("Enter Project grade for student "+i );
			scores[i][2] = MlmIn.readDouble();
			scores[i][3] = getFinal( scores[i] );
		}
		
		for (int i=0; i<size; i++)
			System.out.println("Final grade for student "+i+"= "+scores[i][3] );
	}
	
	public static double getFinal( double[] array )
	{
		double finalGrade=0;
		
		finalGrade = array[0]*.35+array[1]*.4+array[2]*.25;
		return finalGrade;
	}
}