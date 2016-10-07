#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 2000, MAXM = 1000;
int n, m, M;
int a[MAXN];

int dp[MAXN][MAXM];//n种物品 取出m个

void slove() {
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; i < m; j++) {
			if (j > a[i]) {
				dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
			}//负数需要调整
			else {
				dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
			}
		}
	}
}