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

bool cmp(edge x, edge y)
{
	return x.w > y.w;
}
int main()
{
	int k;
	scanf("%d", &k);
	while (k--) {
		int n, m, r;
		scanf("%d%d%d", &n, &m, &r);
		init(m+n);
		for (int i = 0; i < r; i++) {
			scanf("%d%d%d", &Edge[i].u, &Edge[i].v, &Edge[i].w);
			Edge[i].v += n;
		}
		sort(Edge, Edge + r, cmp);
		int i, ans = 0;
		for (i = 0; i < r; i++) {
			if (merge(Edge[i].u, Edge[i].v))
			{
				ans += Edge[i].w;
			}
		}
		cout << (m + n) * 10000 - ans << endl;
	}
	return 0;
}