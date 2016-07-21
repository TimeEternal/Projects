/*http://www.cnblogs.com/LLGemini/p/4371031.html*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 30;
int t, n;
double rv[maxn], kv[maxn];
double Judge(double r)
{
	double min_ = r / rv[n - 1] + (t - r) / kv[n - 1];
	double error = 1e100; //
	for (int i = 0; i < n - 1; i++)
	{
		double tmp = r / rv[i] + (t - r) / kv[i];
		error = min(error, tmp - min_);
	}
	return error;
}

int main()
{
	while (~scanf("%d", &t))
	{
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &rv[i], &kv[i]);
		}
		double L = 0.0, R = t;

		bool ok = false;
		while (R - L>1e-7)
		{
			double m1 = L + (R - L) / 3;
			double m2 = R - (R - L) / 3;
			//cout << Judge(m1) << " " << Judge(m2) << endl;
			if (Judge(m1) > Judge(m2)) R = m2;
			else L = m1;
		}
		double err = Judge(L);
		if (err < 0.00)
			printf("The cheater cannot win.\n");
		else
			printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", err * 3600, L, t - L);
	}
	return 0;
}