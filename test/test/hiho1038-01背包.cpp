#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n, m;
int need[100], value[100];
int d[100][2000];
int dp() {
	memset(d, 0, sizeof(d));
	for (int i = n - 1; i >= 0; i--)
		for (int j = 1; j <= m; j++)
			if(j>=need[i])//²»ÄÜÍü¼Ç
				d[i][j] = max(d[i + 1][j], d[i + 1][j - need[i]]+value[i]);
	return d[0][m];
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> need[i] >> value[i];
	cout << dp() << endl;
	return 0;
}