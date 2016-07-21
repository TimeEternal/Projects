#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
struct point {
	int x, y;
}s,e;
int m, n, time;
int dis[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool vis[10][10], flag = 0;
char map[10][10];
void dfs(point t,int sum) {
	if (t.x == e.x&&t.y == e.y&&sum == time) { flag = 1; return; }
	//cout << t.x << " " << t.y << " " << sum << endl;
	if (flag) return;
	int mindis = abs(t.x - e.x) + abs(t.y - e.y);  /*当前点到终点的最短距离*/
	if (mindis>time - sum || (mindis + time - sum) % 2 != 0)
		return;
	point tt;
	for (int i = 0; i < 4; i++) {
		tt.x = t.x + dis[i][0];
		tt.y = t.y + dis[i][1];
			if (map[tt.x][tt.y] != 'X' && !vis[tt.x][tt.y])
			{
				vis[tt.x][tt.y] = 1;
				dfs(tt, sum + 1);
				vis[tt.x][tt.y] = 0;
			}
	}
}
int main()
{
	while (cin >> m >> n >> time&&m != 0 && n != 0 && time != 0) {
		flag = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i <= n + 1; i++) { map[0][i] = 'X'; map[m + 1][i] = 'X'; }
		for (int i = 0; i <= m + 1; i++) { map[i][0] = 'X'; map[i][n + 1] = 'X'; }
		for(int i=1;i<=m;i++)
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S') { s.x = i; s.y = j; }
				if (map[i][j] == 'D') { e.x = i; e.y = j; }
			}
		vis[s.x][s.y] = 1;
		dfs(s, 0);
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
/*
根据题目，doggie必须在第t秒到达门口。也就是需要走t-1步。
设doggie开始的位置为（sx,sy）,目标位置为（ex,ey）.
如果abs(ex-x)+abs(ey-y)为偶数，则abs(ex-x)和abs(ey-y)奇偶性相同，
所以需要走偶数步；
当abs(ex-x)+abs(ey-y)为奇数时，则abs(ex-x)和abs(ey-y)奇偶性不同，
到达目标位置就需要走奇数步。先判断奇偶性再搜索可以节省很多时间，
不然的话容易超时。t-sum为到达目标位置还需要多少步。
因为题目要求doggie必须在第t秒到达门的位置，所以（t-step）和
abs(ex-x)+abs(ey-y)的奇偶性必然相同。
因此temp=（t-sum）+-都可以(abs(ex-x)+abs(ey-y))必然为偶数。
http://www.cnblogs.com/zhourongqing/archive/2012/04/28/2475684.html
*/