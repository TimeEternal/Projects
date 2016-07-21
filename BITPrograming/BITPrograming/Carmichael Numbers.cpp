/*http://blog.csdn.net/lyhvoyage/article/details/9732549 */

#include<cstdio>
#include<cstring>
#include<math.h>
#define LL long long
int a[66000];
void judge_prime() /*筛法求素数*/
{
	int i, j, m = sqrt(65010 + 0.5);
	memset(a, 0, sizeof(a));
	for (i = 2; i <= m; i++)
	{
		if (!a[i])  /*素数为0*/
		{
			for (j = i*i; j<65010; j += i)
				a[j] = 1; /*非素数为1*/
		}
	}
}
LL pow_mod(LL a, LL n, LL m) /*递归求快速幂*/
{
	if (n == 0) return 1;
	LL x = pow_mod(a, n / 2, m);
	LL ans = x*x%m;
	if (n % 2 == 1) ans = ans*a%m;
	return ans;
}
int main()
{
	judge_prime();
	LL i, n;
	bool flag;
	while (~scanf("%lld", &n) && n)
	{
		if (!a[n])
		{
			printf("%lld is normal.\n", n);
			continue;
		}
		flag = true;
		for (i = 2; i<n; i++)
		{
			if (pow_mod(i, n, n) != i)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			printf("The number %lld is a Carmichael number.\n", n);
		else
			printf("%lld is normal.\n", n);
	}
	return 0;
}