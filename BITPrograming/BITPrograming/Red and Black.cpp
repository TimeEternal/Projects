#include<iostream>
#include<cstring>
using namespace std;
char map[22][22];
bool vis[22][22];
int sum = 0;

void dfs(int x, int y) {
	if (map[x][y] == '.' && !vis[x][y]) {
		vis[x][y] = 1;
		sum++;
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
	}
}
int main()
{
	int m, n,sx,sy;
	while (cin >> n >> m&&n!=0) {
		sum = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i <= n + 1; i++) { map[0][i] = '#'; map[m + 1][i] = '#'; }
		for (int i = 0; i <= m + 1; i++) { map[i][0] = '#'; map[i][n + 1] = '#'; }
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '@') { map[i][j] = '.'; sx = i; sy = j; }
			}
		dfs(sx, sy);
		cout << sum << endl;
	}
	return 0;
}