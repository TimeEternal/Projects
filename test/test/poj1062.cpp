/* http://www.cnblogs.com/rainydays/archive/2011/02/01/1948670.html */
/*题意：每个人都有一个物品，对应一定的钱数，想要得到此物品可以直接出钱，也可以通过用其他人的物品并添加一些钱来交换，问要得到酋长的物品最少需要多少钱？另外，每个人都有一个等级，要求和你交易的人中不能有任何两人的等级相差m以上。

分析：我们可以把本题理解为，我们要买一号物品，而一个物品的一部分价值可以转化为别的物品，我们通过购买别的物品和加钱来购买获得一号物品。所以我们可以把需要加的钱数作为该物品到别的物品的一条边，走过这条边，我们要花一些钱，然后我们只需要购买现在所在结点的物品即可。这样就把问题转化为最短路问题，用dijkstra就可以了。

本题还有个等级制度的问题。我们可以每次枚举一个宽为m的等级区间，忽略不在区间内的点，进行dijkstra。

我wrong answer是因为第一次没处理起始点不在枚举的区间内的情况。*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 101, inf = 1000000000;

struct Item
{
	int p, l;
} item[maxn];

struct Edge
{
	int v, w;
	Edge(){}
	Edge(int vv, int ww) :v(vv), w(ww){}
} e[maxn * maxn];

int map[maxn], level[maxn], levelnum = 0, dist[maxn];
int n, m;
bool vis[maxn];

void dijkstra(int floor)
{
	int best = 0, besti = 0;
	int d[maxn];

	for (int i = 0; i <n; i++)
	{
		d[i] = inf;
		vis[i] = false;
	}
	d[0] = 0;
	while (besti != -1)
	{
		vis[besti] = true;
		for (int i = map[besti]; i < map[besti + 1]; i++)
		{
			if (d[e[i].v] > best + e[i].w && item[e[i].v].l >= floor && item[e[i].v].l <= floor + m)
			{
				d[e[i].v] = best + e[i].w;
			}
		}
		best = inf;
		besti = -1;
		for (int i = 0; i < n; i++)
			if (!vis[i] && d[i] < best)
			{
				best = d[i];
				besti = i;
			}
	}
	for (int i = 0; i < n; i++)
		if (dist[i] > d[i])
			dist[i] = d[i];
}

int main()
{
	//freopen("D:\\t.txt", "r", stdin);
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
		dist[i] = inf;
	map[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d%d%d", &item[i].p, &item[i].l, &temp);
		level[levelnum++] = item[i].l;
		map[i + 1] = map[i] + temp;
		for (int j = 0; j < temp; j++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			a--;
			e[map[i] + j] = Edge(a, b);
		}
	}
	sort(level, level + levelnum);
	levelnum = unique(level, level + levelnum) - level;
	for (int i = 0; i < levelnum; i++)
		if (item[0].l >= level[i] && item[0].l <= level[i] + m)
			dijkstra(level[i]);
	int ans = inf;
	for (int i = 0; i < n; i++)
		if (ans > dist[i] + item[i].p)
			ans = dist[i] + item[i].p;
	printf("%d\n", ans);
	return 0;
}