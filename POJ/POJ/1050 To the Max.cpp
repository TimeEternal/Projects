#include <stdio.h>
#define MAX 101
int main()
{
	int n;
	int a[MAX][MAX] = { 0 };
	int rowsum[MAX][MAX] = { 0 };
	int max = 0, sum;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j - 1]);
			rowsum[i][j] = rowsum[i][j - 1] + a[i][j - 1];
		}
	for (int i = 0; i<n; i++)
		for (int j = i + 1; j <= n; j++)//从第i列到第j-1列
		{
			sum = 0;
			for (int k = 0; k<n; k++)//每行的和
			{
				sum += rowsum[k][j] - rowsum[k][i];//这个预处理优化 我给满分
				if (sum<0) sum = 0;
				else if (sum>max) max = sum;
			}
		}
	printf("%d\n", max);
	return 0;
}