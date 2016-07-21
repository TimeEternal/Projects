#include<stdio.h>
#include<malloc.h>
int m, i, n;
typedef struct node
{
	int num;
	int min;
	struct node *next;
}LinkList;
LinkList *create()
{
	LinkList *L, *p, *q, *r=NULL;
	int min;
	L = (LinkList *)malloc(sizeof(LinkList));
	p = L;
	for (i = 1; i <= n; i++)
	{
		q = (LinkList *)malloc(sizeof(LinkList));
		scanf("%d", &min);
		q->min = min;
		if (i == 1) 
		{
			r = q;
		}
		q->num = i;
		p->next = q;
		p = q;
		if (i == n) 
		{
			p->next = r;
		}

	}
	return r;
}
void main()
{
	LinkList *r, *p;
	int k = 0;
	scanf("%d%d", &m, &n);
	r = create();
	for (i = 2; i <= m; i++) 
	{
		if (r->next != r)
		{
			p = r;
			r = r->next;
			if (i == m)
			{
				printf("%d ", r->num);
				k++;
				m = r->min;
				if (m == 1)
				{
					m = m + n - k;
				}
				p->next = r->next;
				free(r);
				r = p->next;
				i = 1;

			}

		}
		else 
		{
			printf("%d\n", r->num);
			break;
		}
	}
}