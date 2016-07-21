#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1100;
int a[maxn], n, r;
int main()
{
	while (scanf("%d%d", &r, &n) != EOF)
	{
		if (r == -1 && n == -1)
			break;
		for (int i = 0; i<n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int l, index = 0, ans = 0;
		while (index<n)//»úÖÇµÄ ²»ÐÐ 
		{
			l = a[index] + r;
			while (index<n&&a[index] <= l)//×ó°ë¾¶
				index++;
			int p = a[index - 1] + r;
			while (index<n&&a[index] <= p)//ÓÒ°ë¾¶
				index++;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
