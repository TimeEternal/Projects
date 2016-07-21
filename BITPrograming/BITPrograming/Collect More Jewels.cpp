/*题意：

一个n*m迷宫，t时间后会倒塌，里边有l个珍宝。现在知道每个珍宝的价值，迷宫地图。
问在能否逃出迷宫；若能逃出，能带走的珍宝最大价值是多少。
珍宝由大写字母【A】~【J】表示，‘*’表示墙，‘.’表示路，‘@’表示起点，‘
<’表示出口。
题解：
两种方法：bfs + 状态压缩或者bfs + dfs，前者只用写bfs，但耗时较高，734MS；
后者则只需要31MS即可。
1）bfs + 状态压缩
将珍宝状态压缩，对于l个珍宝，我们可以用l位二进制表示珍宝的获取情况（1表示已
经获得，0表示未获得）。然后我们用vis[i][j][k]表示状态，i表示珍宝获取情况，
（j，k）表示位置。这样我们相当于走2^l张地图，每次得到珍宝时转换地图，这样就
需要相当多的时间消耗了。
2）bfs + dfs
珍宝至多10件，我们可以找出起点到所有珍宝和终点的最短路径，珍宝到其他珍宝和
终点的最短路径。需要bfs地图至多21次，比上面的2^l次要少很多。我们得到所有的
最短路径之后就可以用dfs搜索最大能获得价值了。
提示：可以用sum保存所有珍宝的价值和，要是dfs时，答案ans = sum，那么就可以
剪枝掉了，why？因为没有比这个价值更大的了。
注意：我们需要把所有的最短路径path[i][j]初始化为无穷大，因为可能出现走不到
的情况。

	代码：
	1.bfs + 状态压缩
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

//状态压缩+bfs
const int maxn = 55;
struct node {
	int x, y;
	int key;    //用10位二进制标识拿到了的珠宝
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
			vis[g.key][g.x][g.y] = true;//已经是广搜 只要拿到过 一定比当前优
			g.num = f.num + 1;
			//printf("%d %d %d\n",g.x,g.y,g.key);
			if (g.x == x2&&g.y == y2)
				ans = max(ans, cal(g.key));
			if (g.num == t)continue;//t时间刚好走到出口也可以 判定在前
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



//2.bfs + dfs   此解法更加优秀


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