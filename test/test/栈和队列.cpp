#include<iostream>
#include<cstdlib>
#include <iomanip>
using namespace std;
int n; float charge; int ci=0;
struct snode
{
	int num;
	float fee;
}fees[100];
typedef bool status;
typedef struct
{
	int num;
	int time;
}carinf;
typedef struct
{
	carinf *base;
	carinf *top;
	int stacksize;
}sqstack;
typedef struct node
{
	carinf car;
	node *next;
}qnode,*qnodeptr;
typedef struct
{
	qnode *front;
	qnode *rear;
}queue;
status initstack(sqstack &s)
{
	s.base = (carinf*)malloc(100 * sizeof(carinf));
	if (!s.base) exit(0);
	s.top = s.base;
	s.stacksize = 100;
	return 1;
}
status gettop(sqstack &s, carinf &e)
{
	if (s.base == s.top) return 0;
	e = *(s.top - 1);
	return 1;
}
status push(sqstack &s, carinf e)
{
	if (s.top - s.base >= 100)
	{
		s.base = (carinf *)realloc(s.base, (s.stacksize+10)* sizeof(carinf));
		if (!s.base) exit(0);
		s.top = s.base + s.stacksize;
		s.stacksize += 10;
	}
	*s.top++ = e;
	return 1;
}
status pop(sqstack &s,carinf &e)
{
	if (s.base == s.top) return 0;
	e = *--s.top;
	return 1;
}
status initqueue(queue &q)
{
	q.front = q.rear = (qnodeptr)malloc(sizeof(qnode));
	if (!q.front) return 0;
	q.front->next = NULL;
	return 1;
}
status enqueue(queue &q, carinf e)//enter
{
	qnodeptr p;
	p = (qnodeptr)malloc(sizeof(qnode));
	p->car = e; p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	return 1;
}
status dequeue(queue &q,carinf &e)//depart
{
	qnodeptr p;
	if (q.front == q.rear) return 0;
	p = q.front->next;
	e = p->car;
	q.front->next = p->next;
	if (q.rear == p) q.rear = q.front;
	free(p);
	return 1;
}
status enparkinglot(sqstack &s,queue &q,carinf e)
{
	if (s.top - s.base >= n) enqueue(q, e);
	else push(s, e);
	return 1;
}
status deparkinglot(sqstack &s, queue &q,carinf e)
{
	carinf t; sqstack temp; 
	initstack(temp);
	while (gettop(s, t) && t.num != e.num) { pop(s, t); push(temp, t); }
	if (s.base == s.top)
	{   while (pop(temp, t))
		 push(s, t);
    	while (dequeue(q, t)&&(t.num != e.num))
	    {
			enqueue(q, t);
	    } 
		return 1;
	}
	else 
	{
		pop(s, t);
		//cout << t.num << ' ' << charge*(e.time - t.time)<<endl;
		fees[ci].num=t.num; fees[ci].fee=charge*(e.time - t.time);ci++;
		while (pop(temp, t)) push(s, t);
		if (dequeue(q, t)) push(s, t);
	}
	return 1;
}
status display(sqstack &s, queue &q)
{
	carinf t; sqstack temp;
	initstack(temp);
	while (pop(s, t)) push(temp, t);
	cout << "½á¹û£º" << endl;
	for(int i=0;fees[i].num!=0;i++)
		cout << fees[i].num << ' ' <<setiosflags(ios::fixed)<<setprecision(2)<<fees[i].fee<<endl;
	while (pop(temp, t)) cout << t.num<<' '; cout << endl;
	while (dequeue(q, t)) cout << t.num<<' '; cout << endl;
	return 1;
}

int main()
{
	carinf car; status io; sqstack s; queue q;
	initstack(s);  initqueue(q);
	memset(fees,0,sizeof(s));
	cin >> n >> charge;
	while (cin >> io >> car.num >> car.time&&!(io == 0 && car.num == 0 && car.time == 0))
	{
		if (io == 0) enparkinglot(s,q,car);
		else deparkinglot(s,q,car);
	}
	display(s,q);
	system("pause");
	return 1;
}