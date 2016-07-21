#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN = 200000 + 7;
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
	if (father[x] != x) {
		father[x] = find(father[x]);
	}
	return father[x];
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return 0;
	if (rak[x] > rak[y]) { father[y] = x; }
	else if (rak[x] < rak[y]) { father[x] = y; }
	else { father[x] = y; rak[y]++; }
	return 1;
}

bool cmp(edge x, edge y)
{
	return x.w > y.w;
}
int main()
{
	int k,t=1; cin >> k;
	while (t<=k) {
		int m, n;
		while (cin >> m >> n && !(m == 0 && n == 0))
		{
			int ans = 0;
			init(m);
			for (int i = 0; i < n; i++) {
				cin >> Edge[i].u >> Edge[i].v >> Edge[i].w;
			}
			sort(Edge, Edge + n, cmp);
			for (int i = 0, num = 0; i < n&&num<m - 1; i++) {
				if (merge(Edge[i].u, Edge[i].v)) {
					ans = Edge[i].w;
					num++;
				}
			}
			cout <<"Case #"<<t<<": "<< ans << endl;
			t++;
		}
	}
	return 0;
}