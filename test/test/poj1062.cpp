/* http://www.cnblogs.com/rainydays/archive/2011/02/01/1948670.html */
/*���⣺ÿ���˶���һ����Ʒ����Ӧһ����Ǯ������Ҫ�õ�����Ʒ����ֱ�ӳ�Ǯ��Ҳ����ͨ���������˵���Ʒ�����һЩǮ����������Ҫ�õ���������Ʒ������Ҫ����Ǯ�����⣬ÿ���˶���һ���ȼ���Ҫ����㽻�׵����в������κ����˵ĵȼ����m���ϡ�

���������ǿ��԰ѱ������Ϊ������Ҫ��һ����Ʒ����һ����Ʒ��һ���ּ�ֵ����ת��Ϊ�����Ʒ������ͨ����������Ʒ�ͼ�Ǯ��������һ����Ʒ���������ǿ��԰���Ҫ�ӵ�Ǯ����Ϊ����Ʒ�������Ʒ��һ���ߣ��߹������ߣ�����Ҫ��һЩǮ��Ȼ������ֻ��Ҫ�����������ڽ�����Ʒ���ɡ������Ͱ�����ת��Ϊ���·���⣬��dijkstra�Ϳ����ˡ�

���⻹�и��ȼ��ƶȵ����⡣���ǿ���ÿ��ö��һ����Ϊm�ĵȼ����䣬���Բ��������ڵĵ㣬����dijkstra��

��wrong answer����Ϊ��һ��û������ʼ�㲻��ö�ٵ������ڵ������*/

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