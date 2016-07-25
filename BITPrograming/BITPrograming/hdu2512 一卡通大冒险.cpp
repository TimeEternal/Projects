/*
n�ſ�����һ��ֻ��n��������ֱ��Ƿ�һ�飬���飬���顣����n�顣��i�ſ��ֳ�j�������
֮ǰ�������������i-1�ſ��ֳ�j-1�飬ֻҪ����i�ſ������ֳ�һ������ˣ�������i-1�ſ�
�ֳ�j�飬��i�ſ���������һ�鶼����������
״̬ת�Ʒ��̣�mark[i][j]=mark[i-1][j-1]+mark[i-1][j]*j��
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int mark[2007][2007], bell[2007];//˹������ ������
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