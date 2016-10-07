#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 1000 + 7;
int dp[MAXN][MAXN];
int n, W, w[MAXN],v[MAXN];

void slove() {
	for(int i=0;i<n;i++)
		for(int j=0;j<=W;j++)
			for (int k = 0; k*w[i] <= j; k++) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][i - k*w[i]] + k*v[i]);
			}
	printf("%d\n", dp[n][W]);
}

void bslove() {
	for (int i = 0; i<n; i++)
		for (int j = 0; j <= W; j++) {
			if (j < w[i]) dp[i + 1][j] = dp[i][j];
			else dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]]);
		}
	printf("%d\n", dp[n][W]);
}

int cdp[MAXN];
void cslove() {
	for(int i=0;i<n;i++)
		for (int j = w[i]; j <= W; j++) {
			cdp[j] = max(cdp[j], cdp[j - w[i]] + v[i);
		}
	printf("%d\n", dp[W]);
}