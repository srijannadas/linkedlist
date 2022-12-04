#include <iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		Node *prev;
		
	Node(int d)
	{
		this->data=d;
		this->next=	NULL;
		this->prev=NULL;
	}
	

};
	
void push(Node* &head,Node* &tail,int d)
{
	if(head==NULL)
	{
		Node* temp=new Node(d);
		head=temp;
		tail=temp;
	}
	else
	{
		Node* temp=new Node(d);
		temp->next=head;
		head->prev=temp;
		head=temp;
		
	}
}

void movetofrnt(Node* &head)
{
	if(head==NULL || head->next==NULL)
	{
		cout<<head->data<<endl;
	}
	Node *temp =NULL;
	Node *last =head;
	while(last->next!= NULL)
	{
		temp=last;
		last=last->next;
	}
	temp->next=NULL;
	last->next=head;
	head=last;
}

void sum(Node* &head)
{
	int sum=0;
	Node* curr=head;
	while(curr!=NULL)
	{
		sum=curr->data+sum;
		curr=curr->next;
	}
	cout<<" Sum of the list :"<<sum<<endl;
}

void search(Node* &head , int ele)
{
    Node* temp=head;
    while(temp!=NULL)
    {
	if(temp->data==ele)
	{
	  cout<<"Found"<<endl;	
	}
	temp=temp->next;
}
    if(temp->data != ele)
    {
    cout<<"NUNU mixed with 2 bichi !"<<endl;
}
}
void print(Node* &head)
{
  Node* temp=head;
  while(temp!=NULL)
  {
  	cout<<temp->data<<" ";
  	temp=temp->next;
	  }	
	  cout<<endl;
}

int main()
{
    Node* head=NULL;
	Node* tail=NULL;
	push(head , tail , 9);
	push(head , tail , 19);
	push(head , tail , 90);
	push(head , tail , 10);
	push(head , tail , 56);
	print(head);
	movetofrnt(head);
	print(head);
	sum(head);
	search(head , 10);
	//cout<<head->data<<endl;
//	cout<<tail->data<<endl;
}
