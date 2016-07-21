/*http://blog.csdn.net/crescent__moon/article/details/9952907 */
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int n;
bool g[107][107], reach[107][107];
int energy[107], power[107], cnt[107];
void floyd()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				reach[j][k] = (reach[j][k] || reach[j][i] && reach[i][k]);
}
bool spfa(int now)
{
	queue<int>q;
	memset(power, 0, sizeof(power));
	memset(cnt, 0, sizeof(cnt));
	q.push(now);
	power[1] = 100;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		cnt[now]++;
		if (cnt[now] >= n) return reach[now][n];//如果某个点的次数大于n，则存在正环
		for (int i = 1; i <= n; i++)
			if (g[now][i] && power[now] + energy[i]>power[i] && power[now] + energy[i]>0)
			{
				q.push(i);
				power[i] = power[now] + energy[i];
			}
	}
	return power[n]>0;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == -1)break;
		memset(g, false, sizeof(g));
		memset(reach, false, sizeof(reach));
		int num, door;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &energy[i], &num);
			while (num--)
			{
				scanf("%d", &door);
				g[i][door] = true;
				reach[i][door] = true;
			}
		}
		floyd();
		if (!reach[1][n])
			printf("hopeless\n");
		else
		{
			if (spfa(1))
				printf("winnable\n");
			else
				printf("hopeless\n");
		}
	}
	return 0;
}
