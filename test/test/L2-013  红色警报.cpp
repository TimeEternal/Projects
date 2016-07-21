/*每次调用并查集求连通块的个数  改变了连通性也不算被侵占*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int vis[505];
struct edge
{
	int x;
	int y;
};
edge e[5005];
int father[505];
int rak[505];
int find1(int x)
{
	if(x != father[x])//路径压缩
	{
		father[x] = find1(father[x]);
	}
	return father[x];
}
void merge1(int x, int y)
{
	int fx = find1(x);
	int fy = find1(y);
	if (fx == fy) return;
	if (rak[fx] > rak[fy]) {
		father[fy] = fx;
	}
	else if (rak[fx] < rak[fy]) {
		father[fx] = fy;
	}
	else {
		father[fx] = father[fy];
		rak[fy]++;
	}
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++) father[i] = i;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &e[i].x, &e[i].y);
		merge1(e[i].x, e[i].y);
	}
	int count = 0;
	for (int i = 0; i<n; i++)
	{
		if (father[i] == i) count++;
	}
	int k, x;
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &x);
		vis[x] = 1;
		for (int i = 0; i<n; i++)
		{
			father[i] = i;
		}
		for (int i = 1; i <= m; i++)
		{
			if (vis[e[i].x] || vis[e[i].y])
				continue;
			merge1(e[i].x, e[i].y);
		}
		int count1 = 0;
		for (int i = 0; i<n; i++)
		{
			if (father[i] == i) count1++;
		}
		if (count + 1 == count1 || count == count1) printf("City %d is lost.\n", x);
		else printf("Red Alert: City %d is lost!\n", x);
		count = count1;
	}
	count = 0;
	for (int i = 0; i<n; i++)
	{
		if (vis[i]) count++;
	}
	if (count == n) printf("Game Over.\n");
	return 0;
}
