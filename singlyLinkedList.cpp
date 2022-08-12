#include<iostream>

using namespace std;

struct node{
	int data;
	node* link;
};

node* head;
void insert(int data);
void insertatN(int data, int position);
void deleteatN(int position);
void print();
void reverseList();

int main(){
	
	int n, data;
	cout<<"How many numbers do you want to enter: ";
	cin>>n;
	
	head = NULL;
	for(int i = 0; i < n; i++){
		cout<<endl;
		cout<<"Enter num "<<(i+1)<<": ";
		cin>>data;
		insert(data);
 	    print();
	}
	reverseList();
	print();
	
	int k, newData;
	cout<<"\n\nEnter the position you want to add a new number: ";
	cin>>k;
	cout<<"\nEnter the number: ";
	cin>>newData;

	insertatN(newData, k);
	print();

	
	int deletepos;
	cout<<"\n\nEnter position to delete from: ";
	cin>>deletepos;
	if(deletepos < n){
		deleteatN(deletepos);
		print();
	}	
}
void insert(int data){
	node* temp = new node();
	temp->data = data;
	temp->link = NULL;

	if(head == NULL){
		head = temp;
		return;
	}
	
    node* temp2 = head;
	
	while(temp2->link != NULL){
		temp2 = (*temp2).link;
	}
	(*temp2).link = temp;
	
	
}
void insertatN(int data, int position){
	node* temp = new node();
	temp->data = data;
	temp->link = NULL;
	
	if(position == 1){
		temp->link = head;
		head = temp;
		return;
	}
	
	node* temp2 = head;
	for(int i = 0; i < position - 2; i++){
		temp2 = temp2->link;
	}
	temp->link = temp2->link;
	temp2->link = temp;
}
void deleteatN(int position){
	node* temp2 = head;
	for(int i = 0; i < position - 2; i++){
		temp2 = temp2->link;
	}
	temp2->link = (temp2->link)->link;
	
}
void print(){
	
	cout<<"The list is ";
	node* temp3 = head;
	cout<<temp3->data<<", ";
	while(temp3->link != NULL){
		temp3 = temp3->link; 
		cout<<temp3->data<<", ";
	}
	cout<<endl;
}
void reverseList(){
	node* next;
	node* prev = NULL;
	node* temp = head;
	
	while(temp != NULL){
		next = temp->link;
		temp->link = prev;
		prev = temp;
		temp = next;
	}
	head = prev;
}
