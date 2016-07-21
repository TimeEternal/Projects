#include<algorithm>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
struct point {
	int x, y;
};
int maze[7][7];
point dis[] = { {0,1},{0,-1},{1,0},{-1,0} };//срвСобио
point nextp[7][7];
bool vis[7][7] = { 0 };
void bfs(int x,int y) {
	queue<point> q;
	stack<point> s;
	vis[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		point t = q.front();
		if (t.x == 1 && t.y == 1) break;
		for (int i = 0; i < 4; i++) {
			point tp;
			tp.x = t.x + dis[i].x; 
			tp.y = t.y + dis[i].y;
			if (!vis[tp.x][tp.y] && maze[tp.x][tp.y] == 0) {
				vis[tp.x][tp.y] = 1;
				q.push(tp);
				nextp[tp.x][tp.y] = t;
			}
		}
		q.pop();
	}
}
int main()
{
	for (int i = 0; i < 7; i++) {
		maze[0][i] = 1; maze[6][i] = 1;
		maze[i][0] = 1; maze[i][6] = 1;
	}
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 6; j++)
			cin >> maze[i][j];
	bfs(5, 5);
	point t = { 1,1 };
	while (t.x != 0 && t.y != 0) {
		cout << "(" << t.x - 1 << ", " << t.y - 1 << ")" << endl;
		t = nextp[t.x][t.y];
	}
	return 0;
}