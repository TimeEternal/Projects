#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int map[22][22],sx,sy,ex,ey,m,n,mindis=11;
int dis[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void dfs(int x, int y, int step) {
	if (step > 10) return;
	for (int i = 0; i < 4; i++) {
		int xx = x, yy = y;
		bool flag = 0;
		//if(map[xx-dis[i][0]][yy-dis[i][1]] == 0) 不是因为背后是0才能打 因为是墙不能打
		if (map[xx + dis[i][0]][yy + dis[i][1]] == 1) continue;
		while (1) {
			xx += dis[i][0];
			yy += dis[i][1];
			if (xx<1 || xx>m || yy<1 || yy>n) { flag = 1; break; }
			if (map[xx][yy] == 0)continue;
			else if (map[xx][yy] == 1)break;
			else { mindis = min(mindis, step); return; }
		}
		if (flag) continue;
		map[xx][yy] = 0;
		dfs(xx - dis[i][0], yy - dis[i][1], step + 1);
		map[xx][yy] = 1;
	}
}

int main() {
	while (cin >> n >> m&&n != 0 && m != 0) {
		mindis = 11;
		memset(map, 0, sizeof(map));
		for(int i=1;i<=m;i++)
			for (int j = 1; j <= n; j++){
				cin >> map[i][j];
				if (map[i][j] == 2) { sx = i; sy = j; map[i][j] = 0; }
				//if (map[i][j] == 3) { ex = i; ex = j; }
		}
		dfs(sx, sy, 1);
		if (mindis != 11) cout << mindis << endl;
		else cout << "-1" << endl;
	}
	return 0;
}
