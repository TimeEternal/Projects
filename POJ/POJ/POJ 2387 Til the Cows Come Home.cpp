#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

struct edge {
	int cost, to;
	edge(int cc,int tt):cost(cc),to(tt){}
};

typedef pair<int, int> P;
vector<edge> G[1007];
int d[1007];

void dijskra(int s) {
	priority_queue<P, vector<P>, greater<P> > que;
	memset(d, 0x3f3f3f3f, sizeof(d));
	d[s] = 0;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;

		if (d[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

int main() 
{
	int T, N;
	scanf("%d%d", &T, &N);
	for (int i = 0; i < T; i++) {
		int s, e, c;
		scanf("%d%d%d", &s, &e, &c);
		G[s].push_back(edge(c, e));
		G[e].push_back(edge(c, s));
	}
	dijskra(1);
	printf("%d\n", d[N]);
	return 0;
}