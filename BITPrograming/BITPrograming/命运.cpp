#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 1000 + 7;
const int INF = 0x3f3f3f3f;

int map[21][MAXN];
int dp[21][MAXN];

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n, m;
		cin >> n >> m;
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> map[i][j];
		for (int i = 0; i <= n; i++) dp[i][0] = -INF;
		for (int i = 0; i <= m; i++) dp[0][i] = -INF;
		dp[0][1] = dp[1][0] = 0;
		for (int i = 1; i <=n; i++)
			for (int j = 1; j <= m; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);//如果左侧为负数 上侧不能初始化为0
				for (int k = 2; k <= m; k++)
				{
					if (j % k == 0)
						dp[i][j] = max(dp[i][j], dp[i][j / k]);
				}
				dp[i][j] += map[i][j];
			}
		cout << dp[n][m] << endl;
	}
	return 0;
}
