#include<iostream>
using namespace std;
struct node{
	int n;
	node * next;
};
void print( node *start);
node * sort_around_x ( int x, node * start)
{
	if( ! start) return NULL;
	int no_of_x=0;
	node *p=start, *smaller, *bigger, *s1, *b1;
	smaller=bigger=NULL;
	s1=smaller;
	b1=bigger;

	while(p)
	{
	if(p->n==x) 
		{
			no_of_x++;
		}
	else if( p->n >x)
		{
			if( !bigger)
			{
				bigger=new(node);
				bigger->next=NULL;
				bigger->n=p->n;
				b1=bigger;
			}
			else
			{
				b1->next=new(node);
				b1=b1->next;
				b1->n=p->n;
				b1->next=NULL;
			}
		}
	else
		{
			if( !smaller)
			{
				smaller=new(node);
				smaller->next=NULL;
				smaller->n=p->n;
				s1=smaller;
			}
			else
			{
				s1->next=new(node);
				s1=s1->next;
				s1->n=p->n;
				s1->next=NULL;
			}
		}
	p=p->next;
	}

	cout<<"\n Smaller is ";
	print(smaller);
	cout<<"\n Biigegr is";
	print(bigger);
	cout<<"\n Attaching :\n";
	
	while(no_of_x)
	{
		s1->next=new(node);
		s1=s1->next;
		s1->n=x;
		no_of_x--;
	}
	s1->next=bigger;
	
	cout<<"\n--";
	print(s1);
	cout<<"\n=====";
	return smaller;

}	
void print( node *start)
{
node *p=start;
while(p)
{
	cout<<endl<<p->n;
	p=p->next;
}
}
void insert( node *p, int x)
{
	node *r=p;
	while(r->next) r=r->next;
	r->next=new(node);
	r=r->next;
	r->n=x;
	r->next=NULL;

}
main()
{
node * start=new(node), *p;
start->n=10;
/*
start->next=new(node);
p=start->next;
p->n=19;
p->next=new(node);
p=p->next;
p->n=5;
p->next=new(node);
p=p->next;
p->n=11;
p->next=new(node);
p=p->next;
p->n=34;
p->next=new(node);
p->n=11;
p->next=NULL;*/
start->next=NULL;
int i;
for(i=1;i<=5;i++)
{
	insert(start, 5*i);
	
}
insert(start, 3);
insert(start,4);
cout<"\n Initial state:\n";
print(start);
cout<<"\n After the sort:\n";
print(sort_around_x(10,start));
}
