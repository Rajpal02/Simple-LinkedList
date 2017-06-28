
#include<bits/stdc++.h>
using namespace std;
void create();
void display();
void insert();
void del();

struct node{
	int data;
	struct node *next;
};
node *head=NULL;
int main()
{
	char ch;
	do{
	cout<<"Enter 1 to create:\n"
		<<"Enter 2 to insert:\n"
		<<"Enter 3 to delete:\n"
		<<"Enter 4 to display\n";
		
		cin>>ch;
		
	if (ch=='1')
		create();
		
	else if(ch=='2')
		insert();
		
	else if(ch=='3')
		del();
	
	else if(ch=='4')
		display();	
	else
		cout<<"Invalid Input\n";
	}while(ch!='0');
}

void create()
{
	node *p=new node;
	cout<<"Enter data:";
	cin>>p->data;
	p->next=NULL;
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		node *q=head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		
			q->next=p;
	}
}

void display()
{
	int c=0;

	if(head==NULL)
	cout<<"list is empty\n";
	
	else{
			node *q=head;
			while(q!=NULL)
	{
		
		cout<<q->data<<"\n";
		q=q->next;
		c++;
	}
	}
	cout<<"number of nodes are:"<<c;
	cout<<endl;
	
}

void insert()
{
	int k=1,pos;
	cout<<"Enter pos u wana insert:\n";
	cin>>pos;
	node *p=new node;
	cout<<"enter data:\n";
	cin>>p->data;
	p->next=NULL;
	
	if(pos==1||head==NULL)
	{
		p->next=head;
		head=p;
	}
	else
	{
		node *q=head;
		while(q->next!=NULL&&k<pos-1)
		{
			k++;
			q=q->next;
		}
		if(q->next==NULL)
		{
			q->next=p;
		}
		else
		{
			p->next=q->next;
			q->next=p;
		}
	}
}
void del()
{
	if (head==NULL)
	cout<<"list is empty";
	else
	{
		int n;
		node *q=head;
		node *p=head;
		cout<<"Enter the data you want to delete:";
		cin>>n;
		if (head->data==n)
		{
			q=head;
			head=head->next;
		}
		while(q->data!=n&&q!=NULL)
		{
			p=q;
			q=q->next;
		}
		if(q==NULL)
		cout<<"Data not found";
		
		else
		p->next=q->next;
		
		free(q);
	}
}
