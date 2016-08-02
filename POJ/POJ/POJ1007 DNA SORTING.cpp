#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
char s[101][51];
int v[101] = { 0 };
int n, l;
void msort()
{
	cin >> l >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < l - 1; j++)
			for (int k = j + 1; k < l; k++)
				if (s[i][j] > s[i][k]) v[i]++;
	}
	int index, min;//每次找到最小的输出即可
	for (int j = 0; j < n; j++) {
		min = 5000;
		for (int i = 0; i < n; i++)
			if (v[i] < min) { min = v[i]; index = i; }
		cout << s[index] << endl;
		v[index] = 5000;
	}
}
int main()
{
	msort();
	return 0;
}