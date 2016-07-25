/*http://blog.csdn.net/say_c_box/article/details/52003545 */
/*http://blog.csdn.net/nare123/article/details/51966794 */  //大神代码看不懂啊
/*
观察所给数字的二进制为00,01,10,11.其中的1恰好为对应的天数能干的事情。
假设k[i]为第k天应该干的事情
若序列a[]的子序列s[i](L<=i<=R)有连续个3，
1.假设L=1；那么s之前没有数字，s的状态是由R+1位置的数字决定的，但是无论这个数字是什么s序列中都不可能存在休息的天数。所以k[R+1]=k[R]&a[R+1];
2.假设L!=1,那么R+1的状态是由L-1的状态决定的，但s中仍不可能存在休息的天数。所以
k[R+1]=k[L-1]^k[L]^...^k[R](^为异或运算)
再考虑a[]中没有3的情况那么,k[i+1]=a[i+1]^k[i]; 若k[i+1]==3说明其中一定存在10,01那么k[i+1]=k[i]&a[i+1];
若k[i]==0 则说明第i天休息；
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int mymin(int a, int b, int c) {
	return min(a, min(b, c));
}
int main()
{
	int s[107], n;
	int dp[107][3];
	memset(dp, INF, sizeof(dp));
	dp[0][1] = dp[0][0] = dp[0][2] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) {
		dp[i][0] = mymin(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + 1;
		if (s[i] == 1 || s[i] == 3) {
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		}
		if (s[i] == 2 || s[i] == 3) {
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		}
		// 原本还有s[i]==0  dp[i][1]=dp[i][2]=INF 代表无法做这件事 这个状态无法转移到下个状态 起初全初始化为INF了 省略这个步骤
	}
	int ans = mymin(dp[n][0], dp[n][1], dp[n][2]);
	cout << ans << endl;
	return 0;
}