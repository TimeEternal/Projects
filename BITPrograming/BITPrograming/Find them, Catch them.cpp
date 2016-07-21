#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct point {
	int x, y;
	int father;
}p[1007];
int rak[1007],n,d;
bool useful[1007] = { 0 };
void set(int i, int x, int y) {
	p[i].x = x;
	p[i].y = y;
	p[i].father = i;
	rak[i] = 0;
}

int find(int x) {
	if (p[x].father != x)
		p[x].father = find(p[x].father);
	return p[x].father;
}

void merge(int x, int y) {//��ȻҪ�������� ����һ��
	int rx = find(x),ry=find(y);
	if (rx == ry) return;
	if ((p[x].x - p[y].x)*(p[x].x - p[y].x) + (p[x].y - p[y].y)*(p[x].y - p[y].y) > d*d) return;
	if (rak[rx] > rak[ry])   //���x������ȱ�y���y���ӵ�x��
	{
		p[ry].father = rx;
	}
	else if (rak[rx] < rak[ry])
	{

		p[rx].father = ry;

	}
	else if (rak[rx] == rak[ry])  //�����������һ��
	{
		p[rx].father = ry;
		rak[ry]++;
	}
}
int main()
{
	int i=1,x,y;
	cin >> n >> d;
	while (i<=n) {
		cin >> x >> y;
		set(i, x, y);
		i++;
	}
	char op;
	while (cin >> op) {
		if (op == 'O') {
			int t;
			cin >> t;
			useful[t] = 1;
			for (int i = 1; i <= n; i++) {
				if (i != t&&useful[i])
					merge(i, t);
			}
		}
		else {
			cin >> x >> y;
			if (find(x) == find(y))
				cout << "SUCCESS" << endl;
			else cout << "FAIL" << endl;
		}
	}
	return 0;
}
