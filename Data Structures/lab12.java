/**
  Carlos Chitty
  Data Structures - Lab 12
  Part 1 Stack
*/

import java.lang.*;
interface Stack 
{
	public Object top() throws StackEmptyException; // returns the top element
	public int size();
	public void push(Object element) throws StackFullException;
	public Object pop() throws StackEmptyException;
}
class StackEmptyException extends RuntimeException
{
	public StackEmptyException(String err)
	{
		super(err);
	}
}
class StackFullException extends RuntimeException
{
	public StackFullException(String err)
	{
		super(err);
	}
}

class ArrayStack implements Stack 
{
	public static final int CAPACITY = 1000; // default capacity of stack
	private int capacity; // actual capacity of stack if not 1000
	private Object S[]; // array that holds the items in the stack
	private int top = 0; // the top element of the stack
	public ArrayStack() 
	{
		this(CAPACITY); // default constructor
	}
	public ArrayStack(int cap) 
	{
		capacity = cap;
		S = new Object[capacity];
	}
	public int size() 
	{
		return (top + 1);
	}
	public void push(Object obj) 
	{
		if (size() == capacity)
			throw new StackFullException("Stack overflow");
		S[++top] = obj;
	}
	public Object top() throws StackEmptyException 
	{
		// why is it passing the buck, and to which methods is it passing it???
		if (size() == 0)
			throw new StackEmptyException("Stack is empty");
		return S[top];
	}
	public Object pop() throws StackEmptyException 
	{
		// why is it passing the buck, and to which methods???
		Object elem;
		if (size() == 0)
			throw new StackEmptyException("Stack is empty");
		elem = S[top];
		S[top--] = null;
		return elem;
	}
}

public class lab12
{
	public static void main(String[] args)
	{
		ArrayStack name = new ArrayStack();
		name.push(new Character('C'));
		name.push(new Character('a'));
		name.push(new Character('r'));
		name.push(new Character('l'));
		name.push(new Character('o'));
		name.push(new Character('s'));
		
		System.out.println( ((Character)name.pop()).charValue() );
		System.out.println( ((Character)name.pop()).charValue() );
		System.out.println( ((Character)name.pop()).charValue() );
		System.out.println( ((Character)name.pop()).charValue() );
		System.out.println( ((Character)name.pop()).charValue() );
		System.out.println( ((Character)name.pop()).charValue() );
	}
}