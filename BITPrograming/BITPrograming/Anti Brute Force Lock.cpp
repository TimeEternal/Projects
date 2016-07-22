#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 507;
const int INF = 0x3f3f3f3f;
int s[MAXN][4] = { {0,0,0,0} };
int cost[MAXN][MAXN];
int lowc[MAXN];
bool vis[MAXN];

int cal(int a[], int b[]) {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int x, y;
		if (a[i] > b[i]) { x = a[i]; y = b[i]; }
		else { x = b[i]; y = a[i]; }
		ans += min(x - y, y + 10 - x);
	}
	return ans;
}

int Prim(int cost[][MAXN], int n) {//0000 是无法jump回去的
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	vis[0] = true;
	int minc = INF; int k = -1;
	for (int j = 0; j <= n; j++) {
		if (!vis[j] && cost[0][j] < minc) {
			minc = cost[0][j];
			k = j;
		}
	}
	memset(lowc, INF, sizeof(lowc));
	lowc[k] = minc;

	for (int i = 1; i <= n; i++) {
		minc = INF;
		k = -1;
		for (int j = 0; j <= n; j++) {
			if (!vis[j] && lowc[j] < minc) {
				minc = lowc[j];
				k = j;
			}
		}
		if (k == -1) return -1;
		ans += minc;
		vis[k] = 1;
		for (int j = 0; j <= n; j++) {
			if (!vis[j] && lowc[j] > cost[k][j])
				lowc[j] = cost[k][j];
		}
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(cost, 0, sizeof(cost));
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= n; i++) {
			int x, pos = 3;
			cin >> x;
			while (x > 0) {
				s[i][pos--] = x % 10;
				x /= 10;
			}
		}
		for (int i = 0; i <= n; i++) 
			for (int j = 0; j <= n; j++)
			{
				if (!cost[i][j]&&i!=j)	cost[i][j] =cost[j][i] = cal(s[i], s[j]);
			}
		cout<<Prim(cost, n)<<endl;
	}
	return 0;
}