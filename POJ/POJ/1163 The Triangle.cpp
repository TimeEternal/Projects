#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 107;
int dp[MAXN][MAXN], map[MAXN][MAXN],n;

int maxnum(int x, int y)
{
	if (dp[x][y] != 0) return dp[x][y];
	if (x == n - 1) return dp[x][y] = map[x][y];
	return dp[x][y] = map[x][y] + max(maxnum(x + 1, y), maxnum(x + 1, y + 1));
}

int main()
{
	memset(dp, 0, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> map[i][j];
	cout << maxnum(0, 0) << endl;
	return 0;
}