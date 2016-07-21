#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int m, n;
int dis[8][2] = { { -1,-2 },{ 1,-2 },{ -2,-1 },{ 2,-1 },{ -2,1 },{ 2,1 },{ -1,2 },{ 1,2 } };
int sx[30], sy[30];
bool vis[26][26],flag=0;
void dfs(int x, int y,int num) {
	if (flag) return;
	if (num >= m*n) { 
		flag = 1; 
		for (int i = 0; i<num; i++)
			printf("%c%d", 'A' + sy[i] - 1, sx[i]);
		printf("\n\n");
		return; }//有结果 就return
	//cout << x<<" "<<y<< endl;
	for (int k = 0; k < 8; k++) {//不成立根本不该跳过去
		int tx = x + dis[k][0], ty = y + dis[k][1];//简化计算
		if (tx < 1 || tx>m || ty  < 1 || ty>n||vis[tx][ty]) continue;
		vis[tx][ty] = 1; sx[num] = tx; sy[num] = ty;//原本使用string+ 浪费时间TLE了
		dfs(tx, ty, num + 1);
		vis[tx][ty] = 0;
	}
}
int main()
{
	int k,i=1;
	cin >> k;
	while (i<=k) {
		cin >> m >> n;
		flag = 0;
		memset(vis, 0, sizeof(vis));
		cout << "Scenario #" << i << ":" << endl;
		vis[1][1] = 1;
		sx[0] = 1; sy[0] = 1;
		dfs(1, 1, 1);
		if (!flag) cout << "impossible" << endl<<endl;
		i++;
	}
	return 0;
}