#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 100 + 1;
char s[MAXN];
int d[MAXN][MAXN];//d(i,j)表示i到j最长回文串

int main()
{
	int n;
	cin >> n;
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) d[i][i] = 1;//初始化单个字符

	for (int i = n - 1; i >= 1; i--)
		for (int j = i + 1; j <= n; j++) {
			if (s[i] == s[j])	d[i][j] = d[i + 1][j - 1] + 2;//两侧相等 数量等于中部+2
			for (int k = i; k < j; k++)//最大等于其中某个子串的最大值
				d[i][j] = max(d[i][j],max(d[i][k], d[k + 1][j]));
		}
	cout << d[1][n];
	return 0;
}