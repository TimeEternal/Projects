#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;//防止后面溢出，这个不能太大
bool vis[MAXN];
int lowcost[MAXN], cost[MAXN][MAXN];
void Dijkstra(int n, int beg)
{
	for (int i = 1; i<=n; i++)
	{
		lowcost[i] = cost[0][i]; 
		vis[i] = false; 
	}
	vis[0] = 1;
	lowcost[beg] = 0;
	for (int j = 1; j<=n; j++)
	{
		int k = -1;
		int Min = INF;
		for (int i = 1; i<=n; i++)
			if (!vis[i] && lowcost[i]<Min)
			{
				Min = lowcost[i]; 
				k = i;
			}
		if (k == -1) break; 
		vis[k] = true;
		for (int i = 1; i<=n; i++)
			if (!vis[i] && lowcost[k] + cost[k][i]<lowcost[i])
			{
				lowcost[i] = lowcost[k] + cost[k][i];
			}
	}
}
int main()
{
	int t,s,d;
	while (cin >> t >> s >> d) {
		int maxp = 0;
		memset(cost, INF, sizeof(cost));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < t; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			maxp = max(max(x, y),maxp);
			if (cost[x][y] > z) {
				cost[x][y] = z;
				cost[y][x] = z;
			}
		}
		int start, finish[MAXN];
		for (int i = 0; i < s; i++) { cin >> start; cost[0][start] = 0; }
		for (int i = 0; i < d; i++) cin >> finish[i];
		Dijkstra(maxp, 0);
		int ans = INF;
		for (int i = 0; i < d; i++)
			if (lowcost[finish[i]] < ans)
				ans = lowcost[finish[i]];
		cout << ans << endl;
	}
	return 0;
}