package Algos;

import java.util.LinkedList;
import java.util.Scanner;

public class BinaryTree {

	private class Node {
		int data;
		Node left;
		Node right;

		Node(int data) {
			this.data = data;
			this.left = null;
			this.right = null;
		}
	}

	Node root;
	int size;

	BinaryTree() {
		Scanner s = new Scanner(System.in);
		this.root = takeInput(s, null, false);

	}

	private Node takeInput(Scanner s, Node Parent, boolean isleftorright) {
		if (Parent == null) {
			System.out.println("Enter the data for root node");
		} else {
			if (isleftorright) {
				System.out.println("Enter the data for left child of " + Parent.data);
			} else {
				System.out.println("Enter the data for right child of " + Parent.data);
			}
		}

		int nodeData = s.nextInt();
		Node node = new Node(nodeData);
		boolean choice = false;
		System.out.println("Do you have a left child");
		choice = s.nextBoolean();

		if (choice) {
			node.left = takeInput(s, node, true);
		}
		choice = false;
		System.out.println("Do you have a right child");
		choice = s.nextBoolean();
		if (choice) {
			node.right = takeInput(s, node, false);
		}

		return node;
	}

	public void Display() {
		Display(this.root);
	}

	private void Display(Node node) {
		if (node.left != null) {
			System.out.print(node.left.data + "==>");

		} else {
			System.out.print("END==>");
		}

		System.out.print(node.data);

		if (node.right != null) {
			System.out.print("==>" + node.right.data);

		} else {
			System.out.print("==>END");
		}

		System.out.println();

		if (node.left != null) {
			this.Display(node.left);
		}
		if (node.right != null) {
			this.Display(node.right);
		}
	}

	public int retSize() {
		return SizeVar(this.root) + 1;
	}

	private int SizeVar(Node node) {
		int count = 0;

		if (node.left != null) {
			count++;
		}
		if (node.right != null) {
			count++;
		}
		if (node.left != null) {
			count += SizeVar(node.left);
		}

		if (node.right != null) {
			count += SizeVar(node.right);
		}

		return count;
	}

	public int Max() {
		return RetMax(this.root);
	}

	private int RetMax(Node node) {
		int max = node.data;

		int tmax = 0;

		if (node.left != null) {
			tmax = this.RetMax(node.left);
			if (tmax > max) {
				max = tmax;
			}
		}

		if (node.right != null) {
			tmax = this.RetMax(node.right);
			if (tmax > max) {
				max = tmax;
			}
		}

		return max;
	}

	public int Height() {
		return RetHeight(this.root);
	}

	private int RetHeight(Node node) {

		int height = -1;
		int theight = 0;

		if (node.left != null) {
			theight = this.RetHeight(node.left);
			if (theight > height) {
				height = theight;
			}
		}

		if (node.right != null) {
			theight = this.RetHeight(node.right);
			if (theight > height) {
				height = theight;
			}
		}
		return height + 1;

	}

	public boolean Find(int x) {
		return Find(this.root, x);
	}

	private boolean Find(Node node, int x) {
		if (node.data == x)
			return true;

		boolean bool = false;
		if (node.left != null) {
			bool = Find(node.left, x);
		}

		if (node.right != null && !bool) {
			bool = Find(node.right, x);
		}
		return bool;

	}

	public void PrintPreOrder() {
		PrintPreOrder(this.root);
	}

	private void PrintPreOrder(Node node) {

		System.out.print(node.data + "==>");
		if (node.left != null) {
			this.PrintPreOrder(node.left);
		}
		if (node.right != null) {
			this.PrintPreOrder(node.right);
		}

	}

	public void PrintPostOrder() {
		PrintPostOrder(this.root);
	}

	private void PrintPostOrder(Node node) {

		if (node.left != null) {
			this.PrintPostOrder(node.left);
		}
		if (node.right != null) {
			this.PrintPostOrder(node.right);
		}

		System.out.print(node.data + "==>");
	}

	public void PrintInOrder() {
		PrintInOrder(this.root);
	}

	private void PrintInOrder(Node node) {

		if (node.left != null) {
			this.PrintInOrder(node.left);
		}

		System.out.print(node.data + "==>");

		if (node.right != null) {
			this.PrintInOrder(node.right);
		}
	}

	public void PreOrderIterative() {
		LinkedList<Node> stack = new LinkedList<>();
		stack.addFirst(this.root);

		while (!stack.isEmpty()) {
			Node temp = stack.removeFirst();
			System.out.print(temp.data + "==>");
			if (temp.right != null) {
				stack.addFirst(temp.right);
			}
			if (temp.left != null) {
				stack.addFirst(temp.left);
			}

		}

	}

	public int LeastAncestor(int n1, int n2) {
		return LeastAncestor(this.root, n1, n2).data;
	}

	private Node LeastAncestor(Node node, int n1, int n2) {

		if (node == null) {
			return null;
		}

		if (node.data == n1 || node.data == n2) {
			return node;
		}

		Node ll = this.LeastAncestor(node.left, n1, n2);
		Node rr = this.LeastAncestor(node.right, n1, n2);

		if (ll != null && rr != null)
			return node;
		else if (ll != null)
			return ll;
		else if (rr != null)
			return rr;
		else
			return null;

	}

	public boolean isBST() {

		return isBST(this.root);
	}

	private boolean isBST(Node node) {

		boolean bool = false;

		if (node.left != null && node.right != null) {
			if (node.left.data < node.data && node.right.data > node.data)
				bool = true;

			bool = isBST(node.left);
			bool = isBST(node.right);
		}

		else if (node.left != null && node.right == null) {
			if (node.left.data < node.data) {
				bool = true;
			}
		}

		else if (node.right != null && node.left == null) {
			if (node.right.data > node.data) {
				bool = true;
			}
		}

		else {
			bool = true;
		}
		return bool;
	}

}
