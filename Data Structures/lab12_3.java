/**
  Carlos Chitty
  Data Structures - Lab 12
  Part 3 Linked List
*/

import java.io.*;
class DoubleNode 
{
	private Object element; 
	private DoubleNode next; 
	private DoubleNode previous;
	DoubleNode()
	{
		this(null,null,null);
	}
	public DoubleNode(Object e, DoubleNode p, DoubleNode n) 
	{
		element = e;
		next = n;
		previous = p;
	}
	public void setElement(Object newElem) 
	{
		element = newElem;
	}
	public void setNext(DoubleNode newNext) 
	{
	next = newNext;
	}
	public void setPrevious(DoubleNode newPrev) 
	{
	previous = newPrev;
	}
	public Object getElement()
	{
		return element; 
	}
	public DoubleNode getNext()
	{
		return next; 
	}
	public DoubleNode getPrev()
	{ 
		return previous; 
	}

}

interface List 
{
	public int size();
	public boolean empty();
	public void insert(DoubleNode before);
	public void delete(DoubleNode n) throws ListEmptyException;
}

class LinkedList implements List 
{
	private DoubleNode head;
	private DoubleNode tail;
	private int size;
	public LinkedList() 
	{
		head = null;
		tail = null;
		size = 0;
	}
	public int size() 
	{
		return size;
	}
	public boolean empty() 
	{
		if(size==0)
			return true;
		else 
			return false;
	}
	public void insert(DoubleNode d)
	{
		if (empty())
		{
			head=d;
			tail=d;
		}
		else if(d.getElement().toString().compareTo(head.getElement().toString())<0)
		{
			head.setPrevious(d);
			d.setNext(head);
			head=d;
		}
		else if(d.getElement().toString().compareTo(head.getElement().toString())>0)
		{
			
			DoubleNode temp=head;
			if (head.getNext()==null)
			{
				head.setNext(d);
				d.setPrevious(head);
				tail=d;
			}
			else
			{
				temp=temp.getNext();
				while(d.getElement().toString().compareTo(temp.getElement().toString())>0 && temp.getNext()!=null)
				{
					temp=temp.getNext();
				}
				
				if (temp.getNext()==null)
				{
					d.setPrevious(temp);
					temp.setNext(d);
				}
				else
				{
					temp.getPrev().setNext(d);
					d.setPrevious(temp.getPrev());
					temp.setPrevious(d);
					d.setNext(temp);
				}
			}
					
		}
		size++;
	}
	public DoubleNode getHead()
	{
		return head;
	}
	public DoubleNode getTail()
	{
		return tail;
	}
	public void delete(DoubleNode n) throws ListEmptyException
	{
		if (size() == 0)
			throw new ListEmptyException("List is empty");
		DoubleNode temp=head;
		for (int x=0; x<size; x++)
		{
			if (temp.getElement()==n.getElement())
			{
				temp.getPrev().setNext(temp.getNext());
				temp.getNext().setPrevious(temp.getPrev());
			}
			else
				temp=temp.getNext();
		}
		size--;
	}
}

public class lab12_3 
{
	
		public static void main(String[] args) 
		{
			LinkedList A= new LinkedList();
			DoubleNode n1 = new DoubleNode();
			DoubleNode n2 = new DoubleNode();
			DoubleNode n3 = new DoubleNode();
			DoubleNode n4 = new DoubleNode();
			DoubleNode n5 = new DoubleNode();
			DoubleNode n6 = new DoubleNode();
			DoubleNode n7 = new DoubleNode();
			DoubleNode n8 = new DoubleNode();
			DoubleNode n9 = new DoubleNode();
			
			n1.setElement("Carlos");		
			A.insert(n1);
			print(A);
			System.out.println();
			n2.setElement("Jorge");		
			A.insert(n2);
			print(A);
			System.out.println();;
			n3.setElement("Miguel");		
			A.insert(n3);
			print(A);
			System.out.println();
			n4.setElement("John");		
			A.insert(n4);
			print(A);
			System.out.println();
			n5.setElement("Pedro");		
			A.insert(n5);
			print(A);
			System.out.println();
			n6.setElement("John");		
			A.insert(n6);
			print(A);
			System.out.println();
			n7.setElement("Alex");		
			A.insert(n7);
			print(A);
			System.out.println();
			n8.setElement("Zack");		
			A.insert(n8);
			print(A);
			System.out.println();
			n9.setElement("Alina");		
			A.insert(n9);
			print(A);
			System.out.println();		
		}
		public static void print(LinkedList list)
		{
			DoubleNode head = list.getHead();
			for(int cnt = 0; cnt < list.size();++cnt)
			{
				System.out.println(head.getElement());
				head = head.getNext();
			}
		}
}
class ListEmptyException extends RuntimeException
{
	public ListEmptyException(String err) 
	{
		super(err);
	}
}

