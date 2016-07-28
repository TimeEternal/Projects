/*
���⣺����1~n����ĳ��˳�����У�����������ĳһ����������1��a1~ai������ai~an�ݼ�
��2��a1~ai�ݼ���ai~an���������ж����ֲ�ͬ�����С�
˼·��������ȫ���ݼ���ȫ��������һ�֣������������������������������ˣ�
Ҫ������������1���Ǿ�ֻ�ܰ�����n����iλ�ã�����C��1��n-1��+C��2��n-1��+������+C��n-2��n-1��
��2^(n-1)-2��������2���루1����ͬ�����Թ���(2^(n-1)-2)*2+2=2^n-2.
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
		if (n == 1)       //������벻����
		{
			if (p == 1) cout << "0" << endl;
			else cout << "1" << endl;
			continue;
		}
		long long ans = qpow(2, n);
		cout << (ans - 2 + p) % p << endl;//ans��ȡ��p��� ����Ϊ0
	}
	return 0;
}