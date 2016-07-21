#include<iostream>
#include<cstring>
using namespace std;

char map[102][102];
bool vis[102][102];
int sum = 0;
void dfs(int x, int y) {
	if (!vis[x][y] && map[x][y] == '@') {
		vis[x][y] = 1;
		dfs(x-1,y-1);
		dfs(x-1,y);
		dfs(x-1,y+1);
		dfs(x,y+1);
		dfs(x+1,y+1);
		dfs(x+1,y);
		dfs(x+1,y-1);
		dfs(x, y - 1);
	}
}

int main()
{
	int m, n;
	while (cin >> m >> n&&m != 0) {
		sum = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i <= n + 1; i++) { map[0][i] = '*'; map[m + 1][i] = '*'; }
		for (int i = 0; i <= m + 1; i++) { map[i][0] = '*'; map[i][n + 1] = '*'; }
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] == '@' && !vis[i][j]) {
					dfs(i, j);
					sum++;
				}
			}
		cout << sum << endl;
	}
	return 0;
}