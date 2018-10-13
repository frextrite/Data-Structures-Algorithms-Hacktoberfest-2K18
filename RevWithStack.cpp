#include <iostream>
#include <cstring>
using namespace std;

#define MAX 50

struct Stack{
	int top;
public:
	char a[MAX];
	Stack();
	bool isEmpty();
	bool isFull();
	char pop();
	void push(char x);
	void display();
	void peek();
	void reverse(char* str[50], struct Stack* S);
};

Stack::Stack(){
	top = -1;
}

bool Stack::isEmpty(){
	return(top == -1);
}

bool Stack::isFull(){
	return(top == MAX - 1);
}

void Stack::push(char x){
	if(top <= MAX - 1){
		top++;
	a[top] = x;
	}
	else{
		cout << "stack overflow";
	}
}

char Stack::pop(){
	if(top >= -1){
		char x = a[top];
	top--;
	return x;
	}
	else{
		cout << "stack underflow";
	}
}

void Stack::display(){
	for(int i = top; i > -1; i--){
		cout << a[i];
	}
}

void Stack::peek(){
	cout << a[top] << endl;
}

void reverse(char* str, int len){
	struct Stack S;
	int i = 0;
	while(str[i] != '\0'){
		S.push(str[i]);
		i++;
	}
	int k = 0;
	for(int j = S.top; j > -1; j--){
		char c = S.pop();
		str[k] = c;
		k++;
	}
/*	for(int i = 0; i < len; i++){
		str[i] = S.pop();
	}*/
}
 
int main(){
	char* name;
	name = new char[50];
	cin >> name;
	int len = strlen(name);
	//struct Stack S;
	reverse(name, len);
	cout << name;
	return 0;
}