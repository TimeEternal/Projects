#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 1000 + 7;


int v[MAXN], p[MAXN];
int dp[MAXN][MAXN];

int main() {
	int T, N, V;
	cin >> T;
	while (T--) {
		cin >> N >> V;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; i++) cin >> p[i];
		for (int i = 0; i < N; i++) cin >> v[i];

		for(int i=N-1;i>=0;i--)
			for (int j = 0; j <= V; j++) {
				dp[i][j] = dp[i + 1][j];//״̬ѹ������д��һ�� ��Ϊ��һ�и�����һ��
				if (j >= v[i])
					dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + p[i]);
			}
		cout << dp[0][V] << endl;
	}
	return 0;
}
