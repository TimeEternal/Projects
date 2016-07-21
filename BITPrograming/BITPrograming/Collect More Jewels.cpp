/*���⣺

һ��n*m�Թ���tʱ���ᵹ���������l���䱦������֪��ÿ���䱦�ļ�ֵ���Թ���ͼ��
�����ܷ��ӳ��Թ��������ӳ����ܴ��ߵ��䱦����ֵ�Ƕ��١�
�䱦�ɴ�д��ĸ��A��~��J����ʾ����*����ʾǽ����.����ʾ·����@����ʾ��㣬��
<����ʾ���ڡ�
��⣺
���ַ�����bfs + ״̬ѹ������bfs + dfs��ǰ��ֻ��дbfs������ʱ�ϸߣ�734MS��
������ֻ��Ҫ31MS���ɡ�
1��bfs + ״̬ѹ��
���䱦״̬ѹ��������l���䱦�����ǿ�����lλ�����Ʊ�ʾ�䱦�Ļ�ȡ�����1��ʾ��
����ã�0��ʾδ��ã���Ȼ��������vis[i][j][k]��ʾ״̬��i��ʾ�䱦��ȡ�����
��j��k����ʾλ�á����������൱����2^l�ŵ�ͼ��ÿ�εõ��䱦ʱת����ͼ��������
��Ҫ�൱���ʱ�������ˡ�
2��bfs + dfs
�䱦����10�������ǿ����ҳ���㵽�����䱦���յ�����·�����䱦�������䱦��
�յ�����·������Ҫbfs��ͼ����21�Σ��������2^l��Ҫ�ٺܶࡣ���ǵõ����е�
���·��֮��Ϳ�����dfs��������ܻ�ü�ֵ�ˡ�
��ʾ��������sum���������䱦�ļ�ֵ�ͣ�Ҫ��dfsʱ����ans = sum����ô�Ϳ���
��֦���ˣ�why����Ϊû�б������ֵ������ˡ�
ע�⣺������Ҫ�����е����·��path[i][j]��ʼ��Ϊ�������Ϊ���ܳ����߲���
�������

	���룺
	1.bfs + ״̬ѹ��
	*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
	using namespace std;

//״̬ѹ��+bfs
const int maxn = 55;
struct node {
	int x, y;
	int key;    //��10λ�����Ʊ�ʶ�õ��˵��鱦
	int num;
};
char e[maxn][maxn];
int val[11];
bool vis[1100][maxn][maxn];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

int cal(int key)
{
	int i, j, ans = 0;
	for (i = 0, j = 1; i<10; i++, j = j * 2)
		if (j&key)ans += val[i];
	return ans;
}
void bfs(int x1, int y1, int x2, int y2, int n, int m, int t)
{
	//printf("%d %d %d %d\n",x1,y1,x2,y2);
	memset(vis, false, sizeof(vis));
	node f, g;
	int i, j, k, xx, yy, key, ans = -1;
	f.x = x1, f.y = y1, f.key = f.num = 0;
	vis[0][x1][y1] = true;
	queue<node>q;
	q.push(f);
	while (!q.empty())
	{
		f = q.front();
		q.pop();
		//printf("%d\n",f.num);
		for (i = 0; i<4; i++)
		{
			g.x = f.x + dir[i][0];
			g.y = f.y + dir[i][1];
			if (g.x<0 || g.y<0 || g.x >= n || g.y >= m || e[g.x][g.y] == '*')continue;
			if (e[g.x][g.y] != '.')g.key = (f.key | (1 << (e[g.x][g.y] - 'A')));
			else g.key = f.key;
			if (vis[g.key][g.x][g.y])continue;
			vis[g.key][g.x][g.y] = true;//�Ѿ��ǹ��� ֻҪ�õ��� һ���ȵ�ǰ��
			g.num = f.num + 1;
			//printf("%d %d %d\n",g.x,g.y,g.key);
			if (g.x == x2&&g.y == y2)
				ans = max(ans, cal(g.key));
			if (g.num == t)continue;//tʱ��պ��ߵ�����Ҳ���� �ж���ǰ
			q.push(g);
		}
	}
	if (ans == -1)printf("Impossible\n");
	else printf("The best score is %d.\n", ans);
}
int main()
{
	int T, tt = 0;
	scanf("%d", &T);
	while (T--)
	{
		int i, j, k, n, m, t, x1, y1, x2, y2;
		scanf("%d%d%d%d", &m, &n, &t, &k);
		for (i = 0; i<k; i++)scanf("%d", &val[i]);
		for (i = 0; i<n; i++)
			scanf("%s", e[i]);
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<m; j++)
			{
				if (e[i][j] == '@') { x1 = i; y1 = j; e[i][j] = '.'; }
				else if (e[i][j] == '<') { x2 = i; y2 = j; e[i][j] = '.'; }
			}
		}
		printf("Case %d:\n", ++tt);
		bfs(x1, y1, x2, y2, n, m, t);
		if (T != 0)printf("\n");
	}
	return 0;
}



//2.bfs + dfs   �˽ⷨ��������


/*#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 55;
const int INF = 1e8;
struct node {
	int x, y;
	int num;
};
int vis[maxn][maxn];
int n, m, t, l, ans, sum;
int val[11];
int path[12][12], mark[12];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
char e[maxn][maxn];
void bfs(int x, int y, int from)
{
	memset(vis, 0, sizeof(vis));
	vis[x][y] = 1;
	int i, j, k;
	node f, g;
	queue<node>q;
	f.x = x; f.y = y; f.num = 0;
	q.push(f);
	while (!q.empty())
	{
		f = q.front();
		q.pop();
		for (i = 0; i<4; i++)
		{
			g.x = f.x + dir[i][0];
			g.y = f.y + dir[i][1];
			if (g.x<0 || g.y<0 || g.x >= n || g.y >= m || e[g.x][g.y] == '*' || vis[g.x][g.y])continue;
			vis[g.x][g.y] = 1;
			g.num = f.num + 1;
			if (e[g.x][g.y] != '.')
			{
				if (e[g.x][g.y] == '@')path[from][0] = g.num;
				else if (e[g.x][g.y] == '<')path[from][l + 1] = g.num;
				else path[from][e[g.x][g.y] - 'A' + 1] = g.num;
			}
			q.push(g);
		}
	}
}
void dfs(int pre, int time, int value)
{
	if (time>t || ans == sum)return;
	if (pre == l + 1)
	{
		ans = max(ans, value);
		return;
	}
	for (int i = 1; i <= l + 1; i++)
	{
		if (mark[i])continue;
		mark[i] = 1;
		dfs(i, time + path[pre][i], value + val[i - 1]);
		mark[i] = 0;
	}
}
int main()
{
	int T, tt = 0;
	scanf("%d", &T);
	while (T--)
	{
		int i, j, k;
		sum = 0;
		scanf("%d%d%d%d", &m, &n, &t, &l);
		for (i = 0; i<l; i++) { scanf("%d", &val[i]); sum += val[i]; }
		val[l] = 0;
		for (i = 0; i<n; i++)scanf("%s", e[i]);
		for (i = 0; i <= l + 1; i++)
		{
			for (j = 0; j <= l + 1; j++)
				path[i][j] = INF;
		}
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<m; j++)
			{
				if (e[i][j] == '@')bfs(i, j, 0);
				if (e[i][j] == '<')bfs(i, j, l + 1);
				if (e[i][j] <= 'J'&&e[i][j] >= 'A')bfs(i, j, e[i][j] - 'A' + 1);
			}
		}
		ans = -1;
		memset(mark, 0, sizeof(mark));
		dfs(0, 0, 0);
		printf("Case %d:\n", ++tt);
		if (ans == -1)printf("Impossible\n");
		else printf("The best score is %d.\n", ans);
		if (T != 0)printf("\n");
	}
	return 0;
}
*/