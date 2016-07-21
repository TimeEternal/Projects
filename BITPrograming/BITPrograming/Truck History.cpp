#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2000 + 7;
bool vis[MAXN];
int lowc[MAXN], cost[MAXN][MAXN];
int Prim(int cost[][MAXN], int n) {
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	vis[0] = true;
	for (int i = 0; i < n; i++) lowc[i] = cost[0][i];
	for (int i = 1; i < n; i++) {
		int minc = INF;
		int k = -1;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && lowc[j] < minc) {
				minc = lowc[j];
				k = j;
			}
		}
		if (k == -1) return -1;
		ans += minc;
		vis[k] = 1;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && lowc[j] > cost[k][j])
				lowc[j] = cost[k][j];
		}
	}
	return ans;
}

int cal(int x, int y, string s[]) {
	if (x == y) return INF;
	int sum = 0;
	for (int i = 0; i < 7; i++) {
		if (s[x][i] != s[y][i])
			sum++;
	}
	return sum;
}
int main()
{
	int n;
	string s[MAXN];
	while (scanf("%d",&n)&&n != 0) {
		for (int i = 0; i < n; i++) cin >> s[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cost[i][j] = cal(i, j, s);
		printf("The highest possible quality is 1/%d.\n", Prim(cost, n));
	}
	return 0;
}