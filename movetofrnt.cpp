#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		
		Node(int d)
		{
			this->data=d;
			this->next=NULL;
		}
};

void push(Node* &head , int d)
{
	
	if(head == NULL)
	{
		Node *temp= new Node(d);
		head=temp;
	}
	
	else
	{
		Node *temp= new Node(d);
		temp->next=head;
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

void print(Node* &head)
{
	Node *temp =head;
	while(temp!= NULL)
	{
		cout<<temp->data<< " ";
		temp=temp->next;
	}
	
	cout<<endl;
}

int main()
{
	Node *head=NULL;
	push(head ,5);
	push(head ,8);
	push(head,6);
	push(head , 10);
	print(head);
	movetofrnt(head);
	print(head);
}
