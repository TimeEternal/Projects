#include<string>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;

typedef struct node {
	char book[30];
	node* child;
	node* bro;
}bnode;

string str;
stringstream ss;

void creat(bnode *&T) {
	char temp[30];
	if (ss >> temp){
		T = new bnode;
		strcpy(T->book, temp);
		T->bro = NULL;
		creat(T->child);
	}
	else {
		T = NULL;
		return;
	}

}
void insert(bnode *&T) {
	char temp[30];
	if (ss >> temp) {
		if (!strcmp(temp,T->book)) {
			insert(T->child);
		}
		else {
			bnode* p=T,*t;
			while (p->bro) p = p->bro;
			t = new bnode;
			strcpy(t->book, temp);
			t->child = NULL;
			t->bro = NULL;
			p->bro = t;
		}
	}
	else {
		T = NULL;
		return;
	}

}
void printt(bnode *T,int n) {
	if (T = NULL) return;
	for (int i = 0; i < 4 * n; i++) cout << " ";
	cout << T->book << endl;
	printt(T->child,n+1);
	printt(T->bro,n+1);
}
int main()
{
	bnode* T=NULL,*head=NULL;
	bool flag = 1;
	while (cin >> str) {
		if (str[0] == '0') { 
			printt(head, 1); 
			continue;
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '/') str[i] = ' ';
		}
		ss = stringstream(str);
		if (flag) { creat(T); flag = 0; head = T; }
		else insert(T);
	}
	return 0;
}