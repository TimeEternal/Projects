#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

const int MAXN = 1010;
const int INF = 0x7f3f3f3f;//防止后面溢出，这个不能太大
bool vis[MAXN];
int map[MAXN][MAXN];
int dist[MAXN];
int pre[MAXN];

void Dijkstra(int n, int beg)
{
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
		vis[i] = false;
		pre[i] = -1;
	}
	dist[beg] = 0;

	for (int j = 1; j <= n; j++)
	{
		int k = -1;
		int Min = INF;
		for (int i = 1; i <= n; i++)
			if (!vis[i] &&dist[i]<Min)
			{
				Min = dist[i];
				k = i;
			}
		if (k == -1)break;
		vis[k] = true;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && dist[k] + map[k][i]<dist[i])
			{
				dist[i] = dist[k] + map[k][i];
				pre[i] = k;
			}
	}

	int maxn = -INF, pos = n;

	while (pre[pos] != -1) {
		if (map[pre[pos]][pos] > maxn)
			maxn = map[pre[pos]][pos];
		pos = pre[pos];
	}
	cout << dist[n] - maxn << endl;
	cout << dist[n] << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(map, INF, sizeof(map));
		memset(dist, INF, sizeof(dist));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == -1) map[i][j] = INF;
			}
			
		Dijkstra(n, 1);
	}
	return 0;
}