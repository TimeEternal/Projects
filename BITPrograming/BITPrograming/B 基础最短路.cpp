#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 207;
const int INF = 0x3f3f3f3f;//防止后面溢出，这个不能太大
int start,finish;
bool vis[MAXN];
int map[207][207];
int dist[207];
void Dijkstra(int n, int beg)
{
	dist[beg] = 0;
	for (int j = 0; j < n; j++)
	{
		int k = -1;
		int Min = INF;
		for (int i = 0; i < n; i++)
			if (!vis[i] && dist[i]<Min)
			{
				Min = dist[i];
				k = i;
			}
		if (k == -1)break;
		vis[k] = true;
		for (int i = 0; i < n; i++)
			if (!vis[i] && dist[k] + map[k][i]<dist[i])
			{
				dist[i] = dist[k] + map[k][i];
			}
	}
}

int main()
{
	int m, n;
	while (cin >> m >> n) {
		memset(vis, 0, sizeof(vis));
		memset(map, INF, sizeof(map));
		memset(dist, INF, sizeof(dist));
		for (int i = 0; i < n; i++) {
			int s, e, cost;
			cin >> s >> e >> cost;
			if (map[s][e] > cost) {//坑死 多条路径 先给小 后给大
				map[s][e] = cost;
				map[e][s] = cost;
			}
		}
		cin >> start >> finish;
		Dijkstra(m, start);
		if (dist[finish]==INF) cout << "-1" << endl;
		else cout << dist[finish] << endl;
	}
	return 0;
}