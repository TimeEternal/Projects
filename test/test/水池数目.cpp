#include<iostream>
#include<cstdlib>
using namespace std;
const int N = 100;
bool vis[N][N];
bool map[N][N];
int m, n;
void dfs(int i, int j) {
	if (map[i][j] == 0 || vis[i][j]) return ;
	vis[i][j] = 1;
	dfs(i - 1,j);
	dfs(i + 1, j);
	dfs(i , j - 1);
	dfs(i , j + 1);
}
int main()
{
	int k; int count = 0;
	cin >> k;
	while (k--) {
		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));
		count = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> map[i][j];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) 
				if (map[i][j] && !vis[i][j]) {
					dfs(i, j);
					count++;
				}
		cout << count << endl;
	}
}