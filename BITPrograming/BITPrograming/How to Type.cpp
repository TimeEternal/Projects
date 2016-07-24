#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

int dp[105][2];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof(0));
		string s;
		cin >> s;
		int len = s.length();
		dp[0][0] = 0;
		dp[0][1] = 1;

		for (int i = 0; i<len; i++)
		{
			if (isupper(s[i]))
			{
				dp[i + 1][0] = min(dp[i][0] + 2, dp[i][1] + 2);
				dp[i + 1][1] = min(dp[i][0] + 2, dp[i][1] + 1);
			}
			else
			{
				dp[i + 1][0] = min(dp[i][0] + 1, dp[i][1] + 2);
				dp[i + 1][1] = min(dp[i][0] + 2, dp[i][1] + 2);
			}
		}
		cout << min(dp[len][0], dp[len][1] + 1) << endl;
	}
	return 0;
}