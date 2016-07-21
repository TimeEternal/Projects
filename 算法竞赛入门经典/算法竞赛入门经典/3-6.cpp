#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100 + 2;
struct node{
	int id;
	char s[MAXN];
}dat[100];

int r, c;

char m[MAXN][MAXN];
int order[MAXN][MAXN];

void init()
{
	cin >> r >> c;
	memset(order, 0, sizeof(order));
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> m[i][j];
	for (int i = 0; i <= c + 1; i++) { m[0][i] = '*'; m[r + 1][i] = '*'; }
	for (int i = 1; i <= r; i++) { m[i][0] = '*'; m[i][c + 1] = '*'; }
}

void posnum()
{
	int n = 1;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if ((m[i - 1][j] == '*' || m[i][j - 1] == '*')&&m[i][j]!='*') order[i][j] = n++;
}

void rowprint()//行（hang） 我直接进行的输出 把cout改成对dat的输入就可以了 pos更改
{
	bool first = 1,line = 0;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c+1; j++)
			if (m[i][j]!='*')  
				if (first&&order[i][j]) { cout << order[i][j] << m[i][j]; first = 0; line = 0; }
				else cout << m[i][j];
			else 
				if (!line) { cout << endl; first = 1; line = 1; }
				else first = 1;
	cout << endl;
}
bool cmp(struct node x,struct node y)
{
	return x.id < y.id;
}
void coloumprint()//列先排序在输出就可以达到效果 机智啊
{
	bool first = 1, line = 0;
	int n = 0,pos=0;
	for (int j = 1; j <= c; j++)
		for (int i = 1; i <= r + 1; i++)
			if (m[i][j] != '*')
				if (first&&order[i][j]) { dat[n].id = order[i][j]; dat[n].s[pos++] = m[i][j]; first = 0; line = 0; }
				else dat[n].s[pos++] = m[i][j];
			else 
				if (!line) { first = 1; n++; pos = 0; line = 1; }
				else { first = 1; pos = 0;}
	sort(dat, dat + n, cmp);
	for (int i = 0; i < n; i++)
		cout << dat[i].id << dat[i].s << endl;

}
int main()
{
	init();
	posnum();
	rowprint();
	coloumprint();
	return 0;
}

