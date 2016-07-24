/*
n�ſ�����һ��ֻ��n��������ֱ��Ƿ�һ�飬���飬���顣����n�顣��i�ſ��ֳ�j�������
֮ǰ�������������i-1�ſ��ֳ�j-1�飬ֻҪ����i�ſ������ֳ�һ������ˣ�������i-1�ſ�
�ֳ�j�飬��i�ſ���������һ�鶼����������
״̬ת�Ʒ��̣�mark[i][j]=mark[i-1][j-1]+mark[i-1][j]*j��
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