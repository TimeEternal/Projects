#include<stdio.h>
#include<stdlib.h>
typedef bool status;
typedef struct node
{
	int num;
	int data;
	struct node *next;
}lnode, *linklist;

linklist list;
int n; int m;
status init_list()
{
	lnode *p, *q; int x;
	p = (lnode*)malloc(sizeof(lnode));
	list = p;
	scanf("%d", &x);
	p->num = 1;
	p->data = x;
	p->next = p;
	for (int i = 1; i < n; i++)
	{
		q = p;
		p = (lnode*)malloc(sizeof(lnode));
		scanf("%d", &x);
		p->num = i + 1;
		p->data = x;
		p->next = q->next;
		q->next = p;
	}
	return 1;
}

status next_person(lnode *&p,lnode*&q)
{
	while (--m)
	{
		q = p;
		p = p->next;
	}
	q->next = p->next;
	printf("%d ", p->num);
	m=p->data;
	free(p);
	p=q->next;
	return 1;
}

status deal_list()
{
	lnode *p, *q;
	p = q = list;
	while (--m)
	{
		q = p;
		p = p->next;
	}
	q->next = p->next;
	printf("%d ", p->num);
	m=p->data;
	free(p);
	p=q->next;
	n--;
	while (n-- >= 1)
		next_person( p,q);
	return 1;
}

status main()
{
	scanf("%d%d", &m, &n);
	init_list();
	deal_list();
	return 1;
}