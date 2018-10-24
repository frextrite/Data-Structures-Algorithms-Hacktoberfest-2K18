#include<iostream>
#include<queue>
using namespace std;

// Reverse a queue
void reverse(queue<int> &q){
	if (q.empty())
		return;
	int t = q.front();
	q.pop();
	reverse(q);
	q.push(t);
}

//Print queue
void print(queue<int> q){

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}
int main(){

	int d;
	queue<int> q;
	cin>>d;
	while(d!=-1){
		q.push(d);
		cin>>d;
	}
	print(q);
	reverse(q);
	print(q);

	return 0;
}