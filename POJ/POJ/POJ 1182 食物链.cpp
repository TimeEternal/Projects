#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 50005;
int p[150010];
//这思路有点强  有点强啊！！！
int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

void unite(int x, int y)
{
	int u = find(x);
	int v = find(y);
	if (u != v) p[u] = v;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i<3 * n; i++) p[i] = i;
	int ans = 0;
	while (m--)
	{
		int id, x, y;
		scanf("%d%d%d", &id, &x, &y);
		if (x>n || y>n)
		{
			ans++;
			continue;
		}
		if (id == 1)
		{
			///x and y the same
			if (same(x, y + n) || same(x, y + 2 * n))
			{
				ans++;
			}
			else
			{
				unite(x, y);
				unite(x + n, y + n);
				unite(x + n * 2, y + n * 2);
			}
		}
		else
		{
			/// x eat y
			if (same(x, y) || same(x, y + 2 * n))
			{
				ans++;
			}
			else
			{
				unite(x, y + n);
				unite(x + n, y + 2 * n);
				unite(x + 2 * n, y);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
/*
由于N和K很大，故需高效的维护动物之间的关系，对于每只动物i创建3个元素i-A，i-B，i-C，
并用这3*N个元素建立并查集，这个并查集维护如下信息：
1.i-x表示“i属于种类x”
2.并查集里到达每一个组表示组内所有元素代表的情况都同时发生或者不发生

例如，如果i-A和j-B在同一个组里，就表示如果i属于种类A那么j一定属于种类B，
反之亦然。因此，对于每一条信息，只需按照如下操作即可：
1.x和y同类———合并x-A和y-A，x-B和y-B，x-C和y-C
2.x吃y—————合并x-A和y-B，x-B和y-C，x-C和y-A

注意：在合并之前，需要先判断合并是否会产生矛盾 、

*/