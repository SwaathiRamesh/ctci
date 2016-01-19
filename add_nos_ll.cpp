#include<iostream>
using namespace std;
struct node{
int n;
node * next;
};
node * add( node * h1, node *h2, int &carryreturn)
{
	int y, c2=0;
	if( h1 == NULL && h2==NULL)
		return NULL;
	if( h1==NULL)
		return h2;
	if(h2==NULL)
		return h1;

	node *p=add( h1->next, h2->next,c2), *r=new(node);

	//cout<<"\n Adding "<<h1->n<<","<<h2->n<<" getting carry "<<c2;
	if(!p) 
	{
		y= h1->n+h2->n;
		carryreturn=y/10;

		r->next=NULL;
		r->n=y%10;
	
	}
	else
	{
		y=h1->n+h2->n+c2;
		carryreturn = y/10;

		r->next=p;
		r->n=y%10;
	
	}
	return r;
}
void insert( node *&p, int n)
{
	if(!p)
	{
		p=new(node);
		p->next=NULL;
		p->n=n;
		return;
	}
	node *q=p;
	while(q->next) 
		q=q->next;
	q->next=new(node);
	q=q->next;
	q->n=n;
	q->next=NULL;
}
void print( node *h)
{
	while(h)
	{
		cout<<endl<<h->n;
		h=h->next;
	}
}
main()
{
node *h1, *h2, *h3;
h1=NULL;
h2=NULL;
int carry;
// h1-345
//insert(h1, 3);
insert(h1, 4);
insert(h1,5);
// h2-127
insert(h2,1);
insert(h2,2);
insert(h2,7);
cout<<"\n First Number";
	print(h1);
	cout<<"\n Second Number";
	print(h2);
	cout<<"\n Addition Result:";	
	node *i= add(h1,h2,carry);
	if( carry){
	h3=new(node);
	h3->next=add(h1,h2,carry);
	h3->n=carry;
	print(h3);}
	else
		print(i);
cout<<"\n----\n";
}
