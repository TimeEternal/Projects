#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class linklist
{
public:
	linklist();
	~linklist();
	int length();				//求链表长度
	void get(int i);			//得到第i个元素
	void locate(int x);			//得到值为x的位置
	void insert(int i, int x);	//插入
	void cut(int i);			//删除
	void display();				//遍历
private:
	node* first;
};
linklist::linklist()			//头插法
{
	first = new node;
	first->next = NULL;
	node* s;
	while(1)
	{
		s = new node;
		cin >> s->data;
		if (s->data == 0) { delete s; break; }
		s->next = first->next;
		first->next = s;
	}
}
linklist::~linklist()         //析构
{
	node*q;
	while(first!=NULL);
	{
		q=first;
		first=first->next;
		delete q;
	}
}
int linklist::length()			//length
{
	int i = 0;
	node *q = first->next;
	while (q != NULL)
	{
		q = q->next;
		i++;
	}
	return i;
}
void linklist::get(int i)	   	//get
{
	node*q = first->next;
	int count = 1;
	while (q != NULL&&count<1)
	{
		q = q->next;
		count++;
	}
	if (NULL == q)
		cout << "位置有误" << endl;
	else
		cout << q->data << endl;
}
void linklist::locate(int x)      //locate
{
	node*q = first->next;
	int count = 1;
	while (q != NULL && (q->data) != x)
	{
		q = q->next;
		count++;
	}
	if (NULL == q)
		cout << "未找到" << endl;
	else
		cout << "第  " << count << "  位" << endl;
}
void linklist::insert(int i, int x) 	//insert
{
	node*q = first;
	int count = 0;
	while (q != NULL&&count<i - 1)
	{
		q = q->next;
		count++;
	}
	if (NULL == q)
		cout << "位置有误" << endl;
	else
	{
		node*n = new node;
		n->next = q->next;
		q->next = n;
		n->data = x;
	}
}
void linklist::cut(int i)			 //delete
{
	node*q = first;
	int count = 0;
	while (q != NULL&&count<i - 1)
	{
		q = q->next;
		count++;
	}
	if (NULL == q || q->next == NULL)
		cout << "位置有误" << endl;
	else
	{
		node*p = q->next;
		int x = p->data;
		q->next = p->next;
		cout << x << "被删除" << endl;
		delete p;
	}
}
void linklist::display()             //遍历
{
	node*q = first->next;
	while (q != NULL)
	{
		cout << q->data << " ";
		q = q->next;
	}
}
void main()
{
	linklist i;
	cout << i.length() << endl;
	i.get(5);
	i.locate(2);
	i.insert(1,6);
	i.cut(4);
	i.display();
}
