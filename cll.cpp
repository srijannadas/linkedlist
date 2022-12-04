#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node* Next;
	Node(int d)
	{
		this->data=d;
		this->Next=NULL;
		}	
		~Node()
		{
			int value=this->data;
			if(this->Next!=NULL)
			{
				delete Next;
				Next=NULL;
			}
		}
};

void insert(Node* &tail,int element , int d)
{
	if(tail == NULL)
	{
		Node* temp=new Node(d);
		tail=temp;
		temp->Next=temp;
	}
	else
	{
	     Node* curr=tail;
	     while(curr->data!= element)
	     {
	     	curr=curr->Next;
		 }
		Node* temp=new Node(d);
	   	temp->Next=curr->Next;
		curr->Next=temp;
	}
}

void Delete(Node* &tail,int value)
{
	if(tail==NULL)
	{
		cout<<"Empty,laura!"<<endl;
		return;
	}
	else
	{
		Node* prev=tail;
		Node* curr=prev->Next;
		while(curr->data!=value)
		{
			prev=curr;
			curr=curr->Next;
		}
		prev->Next=curr->Next;
		if(curr==prev)
		{
			tail=NULL;
		}
		else if(tail==curr)
		{
			tail=prev;
		}
		curr->Next=NULL;
		delete curr;
	}
}
void print(Node* &tail)
{
	Node* temp=tail;
	if(tail==NULL)
	{
		cout<<"List Is Empty";
		return;
	}
	do
	{
		cout<<tail->data<<" ";
		tail=tail->Next;
	}while(tail!=temp);
	cout<<endl;
}

int main()
{
	Node* tail=NULL;
	insert(tail,5,3);
	print(tail);
	insert(tail,3,5);
	print(tail);
	Delete(tail,5);
	print(tail);
	return 0;
}
