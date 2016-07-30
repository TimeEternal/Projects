#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int mymin(int a, int b, int c,int d) {
	return min(d, min(a, min(b, c)));
}
int main()
{
	int s[107], n;
	int dp[107][4];
	while (cin >> n) {
		memset(dp, INF, sizeof(dp));
		dp[0][1] = dp[0][0] = dp[0][2] = dp[0][3] = 0;
		for (int i = 1; i <= n; i++) cin >> s[i];
		for (int i = 1; i <= n; i++) {
			dp[i][3] = mymin(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i-1][3]) + 1;
			if (s[i] == 2 || s[i] == 3 || s[i] == 6 || s[i] == 7) {
				dp[i][0] = min(dp[i-1][1],min(dp[i - 1][2], dp[i - 1][3]));
			}
			if (s[i] == 1 || s[i] == 3 || s[i] == 5 || s[i] == 7) {
				dp[i][1] = min(dp[i - 1][0], min(dp[i - 1][2], dp[i - 1][3]));
			}
			if (s[i] == 4 || s[i] == 5 || s[i] == 6 || s[i] == 7) {
				dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][3]));
			}
			// 原本还有s[i]==0  dp[i][1]=dp[i][2]=INF 代表无法做这件事 这个状态无法转移到下个状态 起初全初始化为INF了 省略这个步骤
		}
		int ans = mymin(dp[n][0], dp[n][1], dp[n][2],dp[n][3]);
		cout << ans << endl;
	}
	
	return 0;
}