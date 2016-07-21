#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}*linklist,lnode;

int n;

void swap(int & a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

linklist init_list()
{
	linklist l; lnode *p; int x;
	scanf("%d", &n);
	l = (lnode *)malloc(sizeof(lnode));
	l->next = NULL;
	for (int i = 0; i < n; i++)
	{
		p=(lnode *)malloc(sizeof(lnode));
		scanf("%d", &x);
		p->data = x;
		p->next = l->next;
		l->next = p;
	}
	return l;
}

bool sort_list(linklist &l)
{
	lnode *p, *q;
	p = l->next;
	while (p)
	{
		q = p->next;
		while (q)
		{
			if (q->data < p->data)
				swap(q->data, p->data);
			q = q->next;
		}
		p = p->next;
	}
	return 1;
}

void display_list(linklist l)
{
	lnode *p;
	p = l->next;
	while (p)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
}

int main()
{
	linklist l;
	l = init_list();
	sort_list(l);
	display_list(l);
	return 1;
}