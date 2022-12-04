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
	
	~Node()
{
	int value=this->data;
	if(this->next!=NULL)
{
	delete next;
	next=NULL;
}
	
}
};

void insertAthead(Node* &head,Node* &tail,int d)
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

void insertAttail(Node* &head ,Node* &tail , int d)
{
	if(tail==NULL)
	{
  Node* temp=new Node(d);
  head=temp;
  tail=temp;
}
else
{
	Node *temp=new Node(d);
	temp->prev=tail;
	tail->next=temp;
	tail=temp;
}
}
void insertAtposition(Node* &head,Node* &tail,int position,int d)
{
	if(position==1)
	{
		insertAthead(head,tail,d);
		return;
	}
	int cnt=1;
	Node* temp=head;
	while(cnt<position-1)
	{
		temp=temp->next;
		cnt++;
	}
 if(temp->next == NULL)
 { 
   insertAttail(head ,tail, d);
   return;
 }
 
	Node* Nodetoinsert=new Node(d);
	Nodetoinsert->next=temp->next;
	temp->next->prev=Nodetoinsert;
	temp->next=Nodetoinsert;
	Nodetoinsert->prev=temp;
}

void Delete(Node* &head , Node* &tail, int pos)
{
	if(pos==1)
	{
		Node* temp=head;
		head=temp->next;
		temp->next=NULL;
		delete temp;
	}
	else
	{
		Node* curr=head;
		Node* prev=NULL;
		int cnt=1;
		
		while(cnt<pos)
		{
			prev=curr;
			curr=curr->next;
			cnt++;
		}
		if(curr->next==NULL)
		{
			tail=prev;
		}
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
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
	print(head);
	insertAthead(head,tail,12);
	insertAthead(head,tail,2);
	print(head);
	insertAttail(head,tail,89);
	print(head);
	insertAtposition(head,tail,2,10);
	print(head);
	Delete(head , tail , 4);
	print(head);
	cout<<head->data<<endl;
	cout<<tail->data<<endl;
	cout<<tail->prev->prev->data<<endl;
	cout<<head->next->prev->data<<endl;
}

