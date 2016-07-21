#include<iostream>
#include<algorithm>
using namespace std;
int vis[100], d[100],v[100],n,s;
int dp(int s) {
	if (vis[s]) return d[s];
	vis[s] = 1;
	for (int i = 1; i <= n; i++) {
		if (s >= v[i])
			d[s] = min(d[s], dp(s - v[i]) + 1);
	}
	return d[s];
}
int main()
{
	memset(vis, 0, sizeof(vis));
	memset(d, 1, sizeof(d));
	d[0] = 0;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> v[i];
	cout << dp(s);
	return 0;
}