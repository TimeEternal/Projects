/*
n张卡分组一共只有n种情况，分别是分一组，两组，三组。。。n组。将i张卡分成j组可以有
之前两种情况得来：i-1张卡分成j-1组，只要将第i张卡独立分成一组就行了，或者是i-1张卡
分成j组，第i张卡随便插入哪一组都符合条件。
状态转移方程：mark[i][j]=mark[i-1][j-1]+mark[i-1][j]*j。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int mark[2007][2007], bell[2007];//斯特灵数 贝尔数
int main()
{
	memset(mark, 0, sizeof(mark));
	for (int i = 1; i <= 2000; i++) {
		mark[i][i] = 1;
		for (int j = 1; j < i; j++) {
			mark[i][j] = (mark[i - 1][j - 1] + mark[i - 1][j] * j) % 1000;
		}
	}
	for (int i = 1; i <= 2000; i++) {
		bell[i] = 0;
		for (int j = 1; j <= i; j++)
			bell[i] = (bell[i] + mark[i][j]) % 1000;
	}
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		cout << bell[x] << endl;
	}
	return 0;
}