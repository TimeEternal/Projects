#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000 + 10;
const int MAX = 0xfffffff;
int map[N][N], cost[N][N];
int min_dis, min_cost;

void Dijkstra(int s, int t, int n)
{
	int dis[N], cost1[N];
	bool visit[N];
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= n; ++i)
	{
		dis[i] = map[s][i];
		cost1[i] = cost[s][i];
	}
	dis[s] = 0;
	visit[s] = true;
	for (int i = 1; i < n; ++i)
	{
		int min = MAX;
		int k=-1;
		for (int j = 1; j <= n; ++j)
		{
			if (!visit[j] && min > dis[j])
			{
				min = dis[j];
				k = j;
			}
		}
		if (k == -1) break;
		visit[k] = true;
		for (int j = 1; j <= n; ++j)
		{
			if (!visit[j] && dis[j] > dis[k] + map[k][j])
			{
				dis[j] = min + map[k][j];
				cost1[j] = cost[k][j] + cost1[k];
			}
			//下面这步判断极其重要
			else if (!visit[j] && dis[j] == dis[k] + map[k][j] && cost1[j] > cost[k][j] + cost1[k])
			{
				cost1[j] = cost[k][j] + cost1[k];
			}
		}
		/*if (visit[t])
		{
			min_dis = dis[t];
			min_cost = cost1[t];
			return;
		}*/
	}
	min_dis = dis[t];
	min_cost = cost1[t];
}

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) && (m || n))
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <i; ++j)
			{
				map[i][j] = map[j][i] = MAX;
				cost[i][j] = cost[j][i] = MAX;
			}
		while (m--)
		{
			int a, b, d, p;
			scanf("%d%d%d%d", &a, &b, &d, &p);
			if (map[a][b] > d)
			{
				map[a][b] = map[b][a] = d;
				cost[a][b] = cost[b][a] = p;
			}
		}
		int s, t;
		scanf("%d%d", &s, &t);
		Dijkstra(s, t, n);
		printf("%d %d\n", min_dis, min_cost);
	}
	return 0;
}