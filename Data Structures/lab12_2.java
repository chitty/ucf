/**
  Carlos Chitty
  Data Structures - Lab 12
  Part 2 Queue
*/
import java.io.*;
import java.util.*;

interface Queue
{
	public Object front() throws QueueEmptyException; 
	public int size();
	public void enqueue(Object element) throws QueueFullException;
	public Object dequeue() throws QueueEmptyException;
}

class ArrayQueue implements Queue
{
	public static final int CAPACITY = 1000; 
	private int capacity; 
	private Object S[]; 
	private int back = -1; 
	
	public ArrayQueue()
	{
		this(CAPACITY); 
	}

	public ArrayQueue(int cap)
	{
		capacity = cap;
		S = new Object[capacity];
	}
	
	public int size()
	{
		return (back+1);
	}
	
	public Object front() throws QueueEmptyException
	{
		if (size() == 0)
			throw new QueueEmptyException("EMPTY");
		return S[0];
	}

	public void enqueue(Object obj) throws QueueFullException
	{
		if (size() == capacity)
			throw new QueueFullException("OVERFLOW");
		S[++back] = obj;
	}

	public Object dequeue() throws QueueEmptyException
	{
		Object elem;
		if (size() == 0)
			throw new QueueEmptyException("EMPTY");
		elem = S[0];
		for(int j=0;j<size();j++){
			S[j]=S[j+1];
		}
		return elem;
	}

	public void Print()
	{
		System.out.println(" QUEUE ");
		for(int k=0; k<size() ; k++)
			if(S[k]!=null)
				System.out.println(S[k]);	
		System.out.println("");
	}
}

class QueueEmptyException extends RuntimeException
{
	public QueueEmptyException(String err)
	{
		super(err);
	}
}

class QueueFullException extends RuntimeException
{
	public QueueFullException(String err)
	{
		super(err);
	}
}

public class lab12_2
{
	public static void main(String[] args)
	{

		ArrayQueue A = new ArrayQueue();
		for(int i=0;i<5;i++)
		{
			System.out.println("Enter flight information: ");
			A = InputRead(A);
		}

		Delay(60);
		System.out.println(A.dequeue()+" has landed");
		A.Print();
		Delay(60);
		System.out.println(A.dequeue()+" has landed");
		A.Print();
		Delay(60);
		System.out.println(A.dequeue()+" has landed");
		A.Print();
		Delay(60);
		System.out.println(A.dequeue()+" has landed");
		A.Print();
		Delay(60);
		System.out.println(A.dequeue()+" has landed");	
		A.Print();	
	}

	static ArrayQueue InputRead(ArrayQueue A)
	{
		String temp=MlmIn.readString();
		A.enqueue(temp);
		A.Print();
		return A;
	}

	static void Delay(int ms)
	{
		try
		{
			Thread.sleep (ms);
		}
		catch (Exception e)
		{}
	}
}
