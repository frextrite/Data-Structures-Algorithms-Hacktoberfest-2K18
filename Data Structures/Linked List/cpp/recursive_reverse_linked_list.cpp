#include <iostream>
using namespace std;

class node{

public:
	int data;
	node* next;

	node(int d){
		data = d;
		next = NULL;
	}
};

void insertAtFront(node* &head, int d){

	node* n = new node(d);
	n->next = head;
	head = n;
	
}

void takeInput(node* &head){

	int d;
	cin>>d;
	while(d!=-1){
		insertAtFront(head, d);
		cin>>d;
	}
}

void print(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

node* recReverse(node* &head){

    if(head == NULL || head->next == NULL)
        return head;

    node* newHead = recReverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main(){

	node* head = NULL;
	takeInput(head);
	print(head);
	node* newHead = recReverse(head);
    print(newHead);
	

  return 0;			
}
		