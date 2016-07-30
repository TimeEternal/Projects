#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN = 20000 + 7;
const int INF = 0x3f3f3f3f;
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
	return x.w < y.w;
}
int main()
{
	int m, n, t;
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> m >> n;
		init(m);
		for (int i = 0; i < n; i++) {
			cin >> Edge[i].u >> Edge[i].v >> Edge[i].w;
		}
		sort(Edge, Edge + n, cmp);
		for (int i = 0; i < n; i++) {
			if (merge(Edge[i].u, Edge[i].v))
			{
				ans = Edge[i].w;
			}
		}
		cout << ans << endl;
	}
	return 0;
}