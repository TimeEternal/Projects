#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
struct point {
	int x, y, z,t;
	point operator +(const point& temp) {
		return{ x + temp.x,y + temp.y,z + temp.z ,t+temp.t};
	}
};
point dir[6] = { {0,0,1,1},{ 0,0,-1 ,1 },{ 0,-1,0 ,1 },{ 0,1,0 ,1 },{ 1,0,0 ,1 },{ -1,0,0 ,1 }};
const int N = 50 + 2;
int map[N][N][N], vis[N][N][N];
int time, x, y, z;
int bfs() {
	queue<point> q;
	point temp, p; 
	p = { 1,1,1,0 };
	q.push(p);
	while (!q.empty()) {
		for (int i = 0; i < 6; i++) {
			temp = q.front() + dir[i];
			if (map[temp.x][temp.y][temp.z]==0 && !vis[temp.x][temp.y][temp.z]) {
				vis[temp.x][temp.y][temp.z] = 1;
				if (temp.x == x  && temp.y == y && temp.z == z &&temp.t <= time)
					return temp.t;
				q.push(temp);
			}
		}
		q.pop();
	}
	return -1;
}
int main()
{
	int k;
	cin >> k;
	while (k--)
	{
		memset(map, -1, sizeof(map));
		memset(vis, 0, sizeof(vis));
		cin >> x >> z >> y >> time;
		for (int i = 1; i <= x; i++)
			for (int j = 1; j <= z; j++)
				for (int k = 1; k <= y; k++)
					cin >> map[i][k][j];
		cout<<bfs()<<endl;
	}
	return 0;
}