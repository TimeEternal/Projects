#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int m, n;
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;//防止后面溢出，这个不能太大
bool vis[MAXN];
int pre[MAXN];
int map[107][107];
int dist[107];
void Dijkstra(int n, int beg)
{
	for (int i = 1; i<=n; i++)
	{
		dist[i] = INF; 
		vis[i] = false; 
		pre[i] = -1;
	}
	dist[beg] = 0;
	for (int j = 1; j<=n; j++)
	{
		int k = -1;
		int Min = INF;
		for (int i = 1; i<=n; i++)
			if (!vis[i] && dist[i]<Min)
			{
				Min = dist[i]; 
				k = i;
			}
		if (k == -1)break; 
		vis[k] = true;
		for (int i = 1; i<=n; i++)
			if (!vis[i] && dist[k] + map[k][i]<dist[i])
			{
				dist[i] = dist[k] + map[k][i];
				pre[i] = k;
			}
	}
	cout << dist[m] << endl;
}

int main()
{
	int dist[107];
	while (cin >> m >> n&&m != 0 && n != 0) {
		memset(map, INF, sizeof(map));
		memset(dist, INF, sizeof(dist));
		for (int i = 0; i < n; i++) {
			int s, e, cost;
			cin >> s >> e >> cost;
			map[s][e] = cost;
			map[e][s] = cost;
		}
		Dijkstra(m, 1);
	}
	return 0;
}