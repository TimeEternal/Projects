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
		for (int j = i + 1; j <= n; j++)//�ӵ�i�е���j-1��
		{
			sum = 0;
			for (int k = 0; k<n; k++)//ÿ�еĺ�
			{
				sum += rowsum[k][j] - rowsum[k][i];//���Ԥ�����Ż� �Ҹ�����
				if (sum<0) sum = 0;
				else if (sum>max) max = sum;
			}
		}
	printf("%d\n", max);
	return 0;
}