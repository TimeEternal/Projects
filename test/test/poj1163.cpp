#include<iostream>
#include<algorithm>
using namespace std;
int d[100][100],m[100][100];
int n;
int dp() {
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < i + 1; j++) {
			if (i == n - 1)d[i][j] = m[i][j];//²»ÄÜÍü°¡
			else d[i][j] += m[i][j] + max(d[i + 1][j], d[i + 1][j + 1]);
		}
	return d[0][0];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> m[i][j];
	cout << dp() << endl;
}