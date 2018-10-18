package Algos;

import java.util.Scanner;

public class FenwickTree {
	
	private int []fenwicktree;
	
	FenwickTree(int []input){
		this.fenwicktree = new int[input.length+1];
		CreateTree(input);
	}
	
	private void CreateTree(int []input){
		for(int i=1;i<=input.length;i++){
			this.UpdateValue(i, input[i-1]);
		}
		
	}
	private int GetParent(int index){
		return index - (index & -index);
	}
	
	private int GetNext(int index){
		return index + (index & -index);
	}
	
	public int GetSum(int index){
		index+=1;
		int sum = 0;
		while(index>0){
			sum+=this.fenwicktree[index];
			index = GetParent(index);
		}
		
		return sum;
	}
	
	public void UpdateValue(int index,int val){
		while(index<this.fenwicktree.length){
			this.fenwicktree[index]+=val;
			index=GetNext(index);
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int []a = new int[n];
		for(int i=0;i<n;i++)a[i]=in.nextInt();
		FenwickTree ft = new FenwickTree(a);
		System.out.println(ft.GetSum(3));
	}

}
