/*
在遥远的国家佛罗布尼亚，嫌犯是否有罪，须由陪审团决定。陪审团是
由法官从公众中挑选的。先随机挑选n 个人作为陪审团的候选人，然后
再从这n 个人中选m 人组成陪审团。选m 人的办法是：控方和辩方会
根据对候选人的喜欢程度，给所有候选人打分，分值从0 到20。为了
公平起见，法官选出陪审团的原则是：选出的m 个人，必须满足辩方
总分和控方总分的差的绝对值最小。如果有多种选择方案的辩方总分
和控方总分的之差的绝对值相同，那么选辩控双方总分之和最大的
方案即可。最终选出的方案称为陪审团方案。
为叙述问题方便，现将任一选择方案中，辩方总分和控方总分
之差简称为“辩控差”，辩方总分和控方总分之和称为“辩控和”。
第i 个候选人的辩方总分和控方总分之差记为V(i)，辩方总分和控
方总分之和记为S(i)。现用f(j, k)表示，取j 个候选人，使其辩
控差为k 的所有方案中，辩控和最大的那个方案（该方案称为“方
案f(j, k)”）的辩控和。并且，我们还规定，如果没法选j 个人，
使其辩控差为k，那么f(j, k)的值就为-1，也称方案f(j, k)不可行。
本题是要求选出m 个人，那么，如果对k 的所有可能的取值，求
出了所有的f(m, k) (-20×m≤ k ≤ 20×m)，那么陪审团方案
自然就很容易找到了。
问题的关键是建立递推关系。需要从哪些已知条件出发，
才能求出f(j, k)呢？显然，方案f(j, k)是由某个可行的方案f(j-1, x)
( -20×m ≤ x ≤ 20×m)演化而来的。可行方案f(j-1, x)能演化成
方案f(j, k)的必要条件是：存在某个候选人i，i 在方案f(j-1, x)中
没有被选上，且x+V(i) = k。在所有满足该必要条件的f(j-1, x)中，
选出 f(j-1, x) + S(i) 的值最大的那个，那么方案f(j-1, x)再加上候选人i，
就演变成了方案 f(j, k)。这中间需要将一个方案都选了哪些人都记录下来。
不妨将方案f(j, k)中最后选的那个候选人的编号，记在二维数组的
元素path[j][k]中。那么方案f(j, k)的倒数第二个人选的编号，
就是path[j-1][k-V[path[j][k]]。假定最后算出了解方案的辩控差是k，
那么从path[m][k]出发，就能顺藤摸瓜一步步求出所有被选中的候选人。
初始条件，只能确定f(0, 0) = 0。由此出发，一步步自底向上递推，
就能求出所有的可行方案f(m, k)( -20×m ≤ k ≤ 20×m)。实际解题
的时候，会用一个二维数组f 来存放f(j, k)的值。而且，由于题目中辩
控差的值k 可以为负数，而程序中数租下标不能为负数，所以，在程序中
不妨将辩控差的值都加上400，以免下标为负数导致出错，即题目描述中，
如果辩控差为0，则在程序中辩控差为400。


*/
#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

int dp[21][801], path[21][801], v[201], s[201], list[21];

bool select(int j, int k, int i)
{
	while (j>0 && path[j][k] != i)
	{
		k -= v[path[j][k]];
		j--;
	}
	return j ? 1 : 0;
}

int main()
{
	int T = 1, n, m, i, j, k, d, p, fix;
	while (scanf("%d%d", &n, &m), n + m)
	{
		memset(dp, -1, sizeof(dp)); memset(path, 0, sizeof(path));
		fix = m * 20; dp[0][fix] = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", &d, &p);
			v[i] = d - p; s[i] = d + p;
		}

		for (j = 1; j <= m; j++)
			for (k = 0; k <= 2 * fix; k++)
				if (dp[j - 1][k] >= 0)
					for (i = 1; i <= n; i++)
						if (dp[j][k + v[i]]<dp[j - 1][k] + s[i])
							if (!select(j - 1, k, i))
							{
								dp[j][k + v[i]] = dp[j - 1][k] + s[i];
								path[j][k + v[i]] = i;
							}
		for (k = 0; k <= fix; k++)
			if (dp[m][fix - k] >= 0 || dp[m][fix + k] >= 0)	break;
		d = dp[m][fix - k]>dp[m][fix + k] ? fix - k : fix + k;

		for (p = d, i = 1; i <= m; i++)
		{
			list[i] = path[m - i + 1][p];
			p -= v[list[i]];
		}
		sort(list + 1, list + m + 1);
		printf("Jury #%d\n", T++);
		printf("Best jury has value %d for prosecution and value %d for defence:\n", (dp[m][d] + d - fix) / 2, (dp[m][d] - d + fix) / 2);
		for (i = 1; i <= m; i++)	printf(" %d", list[i]); printf("\n\n");
	}
	return 0;
}

/*
4 2
1 2
2 3
4 1
6 2

Jury #1
Best jury has value 6 for prosecution and value 4 for defence:
2 3
*/

