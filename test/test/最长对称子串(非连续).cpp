/*
对给定的字符串，本题要求你输出最长对称子串的长度。
例如，给定"Is PAT&TAP symmetric?"，最长对称子串为"s PAT&TAP s"，
于是你应该输出11。
输入格式：
输入在一行中给出长度不超过1000的非空字符串。
输出格式：
在一行中输出最长对称子串的长度。
输入样例：
Is PAT&TAP symmetric?
输出样例：
11
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<sstream>
using namespace std;
const int MAXN = 1001;
int d[MAXN][MAXN],l,maxlen=0;
char s[MAXN];
int pfmdp() {
	maxlen = 0;
	memset(d, 0, sizeof(0));
	for (int i = 0; i < l; i++) d[i][i] = 1;

	for(int i=l-2;i>=0;i--)
		for (int j = i + 1; j < l; j++)
		{
			if (s[i] == s[j]&&(d[i + 1][j - 1]!=1||j-i==2||j-i==1)) d[i][j] = 2 + d[i + 1][j - 1];
			else d[i][j] = 1;
			//for (int k = i; k < j; k++)
					//d[i][j] = max(d[i][j], max(d[i][k], d[k + 1][j]));
			maxlen=maxlen < d[i][j] ? d[i][j] : maxlen;
		}
	return maxlen;
}

int main()
{
		cin.getline(s, 1000);
		l = strlen(s);
		cout << pfmdp() <<endl;	 //人人为我动态规划
	return 0;
}