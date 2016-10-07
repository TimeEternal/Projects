#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m,M;
const int MAXN = 1000;

int dp[MAXN][MAXN];
//第二类stirling数
void solve() {
	dp[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (j - i >= 0) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % M;
				//			含有0			不含有0
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
}