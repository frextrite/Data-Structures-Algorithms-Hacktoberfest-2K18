#include <iostream>
#include <stack>
using namespace std;

void print(stack<int> s){

	while(!s.empty()){

		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}

void pushBottom(stack<int> &s, int top){

	// if the list is empty, push the top element
	if(s.empty()){
		s.push(top);
		return;
	}

	// else if the list is not empty
	// push the top element using recursion
	int t = s.top();
	s.pop();
	pushBottom(s,top);
	s.push(t);
}

void reverseStack(stack<int> &s){

	if(s.empty())
		return;

	// Store the top element
	int top = s.top();
	s.pop();

	// Recursive call on stack
	reverseStack(s);

	//push the top element
	pushBottom(s,top);

}

int main(){

	stack<int> s;
	for (int i=0;i<5;i++)
		s.push(i);

	print(s);
	reverseStack(s);

	print(s);


}