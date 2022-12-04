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

void search(Node* &head,int d)
{
	Node* temp = head;
    while(temp!=NULL)
    {
    	if(temp->data=d)
    	{
    		cout<<"Found";
    		return ;
		}
		temp=temp->next;
	}
	cout<<"no";
}

void reverse(Node* &head)
{
	Node* prev=NULL;
	Node* curr=head;
	Node*temp=NULL;
	
	while(curr!= NULL)
	{
		temp= curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	head=prev;
}
int main()
{
	Node *head=NULL;
	
	push(head ,8);
	push(head , 9);
	push(head , 10);
	print(head);

	reverse(head);
	print(head);
	
	
	
}
