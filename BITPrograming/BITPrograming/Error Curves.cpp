#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;//三分的题到底什么鬼
//因为a恒是大于0的 最大值所构成的曲线 必然先减后增
#define eps 1e-9
#define INF 1e15

struct Nod
{
	double a, b, c;
}node[10010];

int n;

double func(double a, double b, double c, double x)
{
	return a*x*x + b*x + c;
}

double getMaxs(double x)
{
	int i;
	double maxs = -INF;
	for (i = 0; i<n; i++)
	{
		double temp = func(node[i].a, node[i].b, node[i].c, x);
		if (maxs<temp)
		{
			maxs = temp;
		}
	}
	return maxs;
}

void sanfen()
{
	double l = 0, r = 1000, mid;
	while (r - l > eps)
	{
		mid = (l + r) / 2;
		double temp2 = getMaxs(mid);
		double temp1 = getMaxs(mid - eps);//观测增减趋势
		if (temp2<temp1)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	printf("%.4lf\n", getMaxs(mid));
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int i;
		for (i = 0; i<n; i++)
		{
			scanf("%lf%lf%lf", &node[i].a, &node[i].b, &node[i].c);
		}
		sanfen();
	}
	return 0;
}