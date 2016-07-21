#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

struct node {
	int x, y, step,px,py;
	friend bool operator <(node x,node y) {
		return x.step > y.step;
	}
}cur,nextpos;
int map[9][9],sx,sy,ex,ey,psx,psy;
int dis[4][2] = { { -1,0 },{ 1.0 },{ 0,-1 },{ 0,1 } };
bool flag = 0,visp[9][9],vis[9][9][9][9],eflag=0;

bool dfs(int pcx, int pcy, int boxx, int boxy, int pfx, int pfy) {
	if (pcx == pfx&&pcy == pfy) { flag = 1; return true; }
	visp[pcx][pcy] = 1;
	for (int i = 0; i<4&&!flag; i++)
	{
		int xx = pcx + dis[i][0];
		int yy = pcy + dis[i][1];
		if (map[xx][yy] == 1 || visp[xx][yy] || (xx == boxx&&yy == boxy)) continue;
			dfs(xx, yy, boxx, boxy, pfx, pfy);
			if (flag) return true;
		}
	return false;
}
void bfs() {
	priority_queue<node> q;
	q.push({ sx,sy,0,psx,psy });
	while (!q.empty()) {
		cur = q.top();
		if (cur.x == ex&&cur.y == ey) { cout << cur.step << endl; eflag = 1; return; }
		for (int i = 0; i < 4; i++)
		{
			memset(visp, 0, sizeof(visp));
			flag = 0;
			int  x = cur.x + dis[i][0];
			int  y = cur.y + dis[i][1];
			if (map[x][y] == 1) continue;
			nextpos.x = x; nextpos.y = y;
			nextpos.px = cur.x;
			nextpos.py = cur.y;
			nextpos.step = cur.step + 1;
			if (i == 0)
				if (map[cur.x + 1][cur.y] != 1 && dfs(cur.px, cur.py, cur.x, cur.y, cur.x + 1, cur.y) && !vis[x][y][cur.x + 1][cur.y])
				{
					vis[x][y][cur.x + 1][cur.y] = 1;
					q.push(nextpos);
				}
			if (i == 1)
				if (map[cur.x - 1][cur.y] != 1 && dfs(cur.px, cur.py, cur.x, cur.y, cur.x - 1, cur.y) && !vis[x][y][cur.x - 1][cur.y])
				{
					vis[x][y][cur.x - 1][cur.y] = 1;
					q.push(nextpos);
				}
			if (i == 2)
				if (map[cur.x][cur.y + 1] != 1 && dfs(cur.px, cur.py, cur.x, cur.y, cur.x, cur.y + 1) && !vis[x][y][cur.x][cur.y + 1])
				{
					vis[x][y][cur.x][cur.y - 1] = 1;
					q.push(nextpos);
				}
			if (i == 3)
				if (map[cur.x][cur.y - 1] != 1 && dfs(cur.px, cur.py, cur.x, cur.y, cur.x, cur.y - 1) && !vis[x][y][cur.x][cur.y - 1])
				{
					vis[x][y][cur.x][cur.y - 1] = 1;
					q.push(nextpos);
				}
		}
		q.pop();
	}
}
int main()
{
	int k, m, n;
	cin >> k;
	while (k--) {
		cin >> m >> n;
		eflag = 0; flag = 0;
		memset(vis, 0, sizeof(vis));
		memset(visp, 0, sizeof(visp));
		for (int i = 0; i <= n + 1; i++) { map[0][i] = 1; map[m + 1][i] = 1; }
		for (int i = 0; i <= m + 1; i++) { map[i][0] = 1; map[i][n + 1] = 1; }
		for(int i=1;i<=m;i++)
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) { sx = i, sy = j; }
				if (map[i][j] == 3) { ex = i, ey = j; }
				if (map[i][j] == 4) { psx = i; psy = j; }
			}
		bfs();
		if (!eflag) cout << "-1" << endl;
	}
	return 0;
}
/*
先判断箱子周围的空地（即可能能被人推到的格子),然后判断人是否能够达到即将推箱子
的位置，在这里我用BFS嵌套DFS，其中BFS用优先权队列进行维护，每次取步数最少的当前
箱子的位置，然后对于当前箱子可以到达的位置来说，DFS人，判断人能否到达推箱子的
位置。
在这里，重要的一点是，对于一个当前的箱子，可以从不同的方向推，所以我用
vis[x][y][z][k]判断对于当前的x,y格子里的箱子来说，是否已经被在z,k格子里
的人推过，推过为1。
*/