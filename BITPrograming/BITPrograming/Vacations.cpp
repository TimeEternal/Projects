/*http://blog.csdn.net/say_c_box/article/details/52003545*/
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <set>


using namespace std;

#define MAXN 110
#define LEN 1000000
#define INF 1e9+7
#define MODE 1000000
typedef long long ll;


int n;
int a[MAXN];
int f[MAXN][3];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 0; i<4; i++)
		f[0][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
		if (a[i] == 1 || a[i] == 3)
			f[i][1] = min(f[i - 1][0], f[i - 1][2]);
		else
			f[i][1] = INF;
		if (a[i] == 2 || a[i] == 3)
			f[i][2] = min(f[i - 1][0], f[i - 1][1]);
		else
			f[i][2] = INF;
		if (a[i] == 0)
		{
			f[i][1] = INF;
			f[i][2] = INF;
		}
	}
	printf("%d\n", min(f[n][0], min(f[n][1], f[n][2])));
}
/*http://blog.csdn.net/nare123/article/details/51966794*/  //大神代码看不懂啊
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