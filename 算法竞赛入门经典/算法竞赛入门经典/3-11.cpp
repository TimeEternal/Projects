#include<stdio.h>
#include<string.h>
char h1[110], h2[110];
int main()
{
	while (scanf("%s%s", h1, h2) != EOF)
	{
		int i, j, t, m, n;
		int temp, conut1, conut2;
		i = j = t = 0;
		m = strlen(h1);
		n = strlen(h2);
		while (j<m&&i<n)
		{
			if (h1[j] + h2[i] - 96 <= 3)
			{
				i++, j++;
			}
			else
				t++, i = 0, j = t;
		}
		conut1 = m + n - i;
		i = j = t = 0;
		while (j<n&&i<m)
		{
			if (h2[j] + h1[i] - 96 <= 3)
			{
				i++, j++;
			}
			else
				t++, i = 0, j = t;
		}
		conut2 = m + n - i;
		printf("%d\n", conut1 < conut2 ? conut1 : conut2);
	}
	return 0;
}
/*
		++++++			+++++
		  +++++       +++++				两种匹配方式 
*/