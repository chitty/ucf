/**
  Carlos Chitty
  Data Structures - Lab 12
  Part 3 Linked List
*/

import java.io.*;
import java.util.*;

class TreeNode
{
	public int element;
	public TreeNode left, right;
	TreeNode(int newElement)
	{
		element = newElement;
	}
}

class BinTree
{
	public TreeNode root=null;
	
	private TreeNode Insert(TreeNode tree, int newElement)
	{
		if (tree == null)
			return new TreeNode(newElement);
		
		else if (newElement < tree.element)
			tree.left = Insert(tree.left, newElement);
		
		else		
			tree.right = Insert(tree.right, newElement);
				
		return tree;
	}
	public void Insert(int newElement)
	{
		root = this.Insert(root, newElement);
	}
	public void BTSearch(int number)
	{
		TreeNode temp = root;
		while (number != temp.element)
		{
			if (temp.left!=null && number < temp.element)
				temp=temp.left;
			else if (temp.right!=null && number > temp.element)
				temp=temp.right;
			else
				break;
		}
		if (temp.element == number)
			System.out.println(number+" is in tree");
		else
			System.out.println(number+" does not exist in this tree");
	}
}

public class lab12_4
{
	public static void main (String[] args)
	{
		BinTree t = new BinTree();
		int num;
		
		t.Insert(12);
		t.Insert(34);
		t.Insert(9);
		t.Insert(27);
		t.Insert(17);
		t.Insert(97);
		t.Insert(98);
		t.Insert(99);
		t.Insert(23);
		t.Insert(51);
		t.Insert(3);
		t.Insert(28);
		t.Insert(28);
		t.Insert(19);
		
		System.out.println("Enter a number to search for: ");
		for (int j=0; j<10; j++)
		{	
			num = MlmIn.readInt(); 	
			t.BTSearch(num);
		}
	}
}
