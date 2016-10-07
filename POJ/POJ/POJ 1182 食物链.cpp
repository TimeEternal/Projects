#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 50005;
int p[150010];
//��˼·�е�ǿ  �е�ǿ��������
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
����N��K�ܴ󣬹����Ч��ά������֮��Ĺ�ϵ������ÿֻ����i����3��Ԫ��i-A��i-B��i-C��
������3*N��Ԫ�ؽ������鼯��������鼯ά��������Ϣ��
1.i-x��ʾ��i��������x��
2.���鼯�ﵽ��ÿһ�����ʾ��������Ԫ�ش���������ͬʱ�������߲�����

���磬���i-A��j-B��ͬһ������ͱ�ʾ���i��������A��ôjһ����������B��
��֮��Ȼ����ˣ�����ÿһ����Ϣ��ֻ�谴�����²������ɣ�
1.x��yͬ�ࡪ�����ϲ�x-A��y-A��x-B��y-B��x-C��y-C
2.x��y�����������ϲ�x-A��y-B��x-B��y-C��x-C��y-A

ע�⣺�ںϲ�֮ǰ����Ҫ���жϺϲ��Ƿ�����ì�� ��

*/