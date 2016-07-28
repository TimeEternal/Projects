# include<iostream>
# include<cstdio>
# include<queue>
# include<cstring>
# include<algorithm>
using namespace std;
# define LL long long
# define REP(i,s,n) for(int i=s;i<n;++i)
# define CL(a,b) memset(a,b,sizeof(a))
# define CLL(a,b,n) fill(a,a+n,b)

const int N = 105;
const int INF = 1 << 30;
const double inf = 1e10;

struct Edge
{
	int fr, to;
	double d, r;
	bool operator < (const Edge &a) const 
	{
		if (r == a.r) return d<a.d;
		return r<a.r;
	}
};
Edge e[N * 100];
int n, m, fa[N], vis[N], pre[N];
double G[N][N], dis[N], ansr;

int findFa(int u)
{
	if (fa[u] != u)
		return fa[u] = findFa(fa[u]);
	return u;
}

void kruskal(int s, int t)
{
	REP(i, 0, n) fa[i] = i;
	REP(i, 0, n) REP(j, 0, n) G[i][j] = inf;
	REP(i, 0, m) {
		ansr = e[i].r;
		int fr = e[i].fr;
		int to = e[i].to;
		int u = findFa(fr);
		int v = findFa(to);
		if (u != v)
			fa[u] = v;
		if (findFa(s) == findFa(t))
			break;
	}
	REP(i, 0, m) if (e[i].r <= ansr)
		G[e[i].fr][e[i].to] = G[e[i].to][e[i].fr] = min(G[e[i].fr][e[i].to], e[i].d);
}

void dijkstra(int s)
{
	CLL(dis, inf, n);
	REP(i, 0, n) pre[i] = i;
	dis[s] = 0.0;
	queue<int>q;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		REP(i, 0, n) {
			if (dis[i]>dis[u] + G[u][i]) {
				dis[i] = dis[u] + G[u][i];
				pre[i] = u;
				if (!vis[i]) {
					vis[i] = 1;
					q.push(i);
				}
			}
		}
	}
}

void print(int u)
{
	if (pre[u] == u) {
		printf("%d", u + 1);
	}
	else {
		print(pre[u]);
		printf(" %d", u + 1);
	}
}

int main()
{
	int s, t;
	while (~scanf("%d%d", &n, &m))
	{
		scanf("%d%d", &s, &t);
		REP(i, 0, m) {
			cin >> e[i].fr >> e[i].to >> e[i].r >> e[i].d;
			--e[i].fr, --e[i].to;
		}
		sort(e, e + m);
		kruskal(s - 1, t - 1);
		dijkstra(s - 1);
		print(t - 1);
		printf("\n");
		printf("%.1lf %.1lf\n", dis[t - 1], ansr);
	}
	return 0;
}