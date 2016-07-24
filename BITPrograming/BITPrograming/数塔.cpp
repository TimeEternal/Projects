#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
const int MAXN = 100 + 7;
int dp[MAXN][MAXN], map[MAXN][MAXN];

int maxsum(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	if (x == n) return dp[x][y] = map[x][y];
	return dp[x][y] = max(maxsum(x + 1, y), maxsum(x + 1, y + 1)) + map[x][y];
}
int main()
{
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				cin >> map[i][j];
		cout << maxsum(1, 1) << endl;
	}
	return 0;
}