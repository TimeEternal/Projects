/*
题意：数字1~n，按某种顺序排列，且满足下列某一个条件：（1）a1~ai递增，ai~an递减
（2）a1~ai递减，ai~an递增。问有多少种不同的排列。
思路：首先是全部递减或全部递增各一种；另外就是满足上列两个条件的情况了，
要想满足条件（1）那就只能把最大的n放在i位置，共有C（1，n-1）+C（2，n-1）+。。。+C（n-2，n-1）
即2^(n-1)-2；条件（2）与（1）相同，所以共有(2^(n-1)-2)*2+2=2^n-2.
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

long long p;

long long qmul(long long a, long long b)
{
	long long ans = 0;
	while (b)
	{
		if (b & 1) ans = (ans + a) % p;
		a = (a + a) % p;
		b >>= 1;
	}
	return ans;
}

long long qpow(long long a, long long n)
{
	long long ans = 1;
	while (n)
	{
		if (n & 1) ans = qmul(ans, a);
		a = qmul(a, a);
		n >>= 1;
	}
	return ans;
}
int main()
{
	long long n;
	while (cin >> n >> p) {
		if (n == 1)       //这个坑想不到啊
		{
			if (p == 1) cout << "0" << endl;
			else cout << "1" << endl;
			continue;
		}
		long long ans = qpow(2, n);
		cout << (ans - 2 + p) % p << endl;//ans是取余p后的 可能为0
	}
	return 0;
}