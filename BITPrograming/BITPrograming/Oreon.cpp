#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN = 100000 + 7;
int father[MAXN], rak[MAXN];
struct edge {
	int u, v, w;
}Edge[MAXN];
void init(int n)
{
	for (int i = 0; i <= n; i++) {
		father[i] = i;
		rak[i] = 0;
	}
}

int find(int x) {
	if (x != father[x]) {
		father[x] = find(father[x]);
	}
	return father[x];
}

bool merge(int x, int y) {
	int xx = find(x);
	int yy = find(y);
	if (xx == yy) return 0;
	if (rak[xx] > rak[yy]) { father[yy] = xx; }
	else if (rak[xx] < rak[yy]) { father[xx] = yy; }
	else { father[xx] = yy; rak[yy]++; }
	return 1;
}

bool cmp(edge x, edge y)//×ÖµäÐò ±»¿ÓµÄ²»Ç³°¡
{
	if (x.w < y.w) return 1;
	if (x.w == y.w&&x.u<y.u) return 1;
	if (x.w == y.w&&x.u == y.u&&x.v < y.v) return 1;
	return 0;
}
int main()
{
	int k,t=1;
	scanf("%d", &k);
	while (t<=k) {
		int n, num = 0;
		scanf("%d", &n);
		init(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
			{
				int x;
				if (j == 0) scanf("%d", &x);
				else scanf(", %d", &x);
				if (x != 0) {
					Edge[num].u = i;
					Edge[num].v = j;
					Edge[num].w = x;
					num++;
				}
			}
			getchar();
		}
		sort(Edge, Edge + num, cmp);
		int i, ans = 0,sum = 0;
		printf("Case %d:\n", t++);
		for (i = 0; i < num&&sum < n - 1; i++) {
			if (merge(Edge[i].u, Edge[i].v))
			{
				int temp;
				/*if (Edge[i].v < Edge[i].u) {
					t = Edge[i].v;
					Edge[i].v = Edge[i].u;
					Edge[i].u = t;
				}*/
				sum++;
				printf("%c-%c %d\n", Edge[i].u + 'A', Edge[i].v + 'A', Edge[i].w);
			}
		}
	}
	return 0;
}