#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int dp[105][2];

int main()
{
	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		dp[0][1] = 1;
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (islower(s[i])) {
				dp[i + 1][0] = min(dp[i][0] + 1, dp[i][1] + 2);
				dp[i + 1][1] = min(dp[i][0] + 2, dp[i][1] + 2);
			}
			else {
				dp[i + 1][0] = min(dp[i][0] + 2, dp[i][1] + 2);
				dp[i + 1][1] = min(dp[i][0] + 2, dp[i][1] + 1);
			}
		}
		cout << min(dp[s.length()][0], dp[s.length()][1] + 1) << endl;
	}
	return 0;
}