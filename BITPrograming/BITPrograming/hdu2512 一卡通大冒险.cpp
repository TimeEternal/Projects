/*
n张卡分组一共只有n种情况，分别是分一组，两组，三组。。。n组。将i张卡分成j组可以有
之前两种情况得来：i-1张卡分成j-1组，只要将第i张卡独立分成一组就行了，或者是i-1张卡
分成j组，第i张卡随便插入哪一组都符合条件。
状态转移方程：mark[i][j]=mark[i-1][j-1]+mark[i-1][j]*j。
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#define LL long long
#define eps 1e-7
#define MOD 1000
using namespace std;
int stir2[2005][2005];
int bell[2005];
int main() {
	memset(stir2, 0x00000001, sizeof(stir2));
	for (int i = 1; i <= 2000; i++) {
		stir2[i][0] = 0;
		stir2[i][i] = 1;
		for (int j = 1; j<i; j++)
			stir2[i][j] = (stir2[i - 1][j - 1] + j*stir2[i - 1][j]) % MOD;
	}
	for (int i = 1; i <= 2000; i++) {
		bell[i] = 0;
		for (int j = 0; j <= i; j++)
			bell[i] = (bell[i] + stir2[i][j]) % MOD;
	}
	int n, t;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << bell[n] << endl;
	}
	return 0;
}