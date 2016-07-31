#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[1000000 + 7];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, maxe = 0;
		cin >> n;
		memset(a, 0, sizeof(a));
		while (n--) {
			int s, e;
			cin >> s >> e;
			a[s] += 1, a[e + 1] -= 1;
			maxe = e > maxe ? e : maxe;//别告诉我是这个TLE了 我可是为了省时间
		}
		int ans = 0;
		for (int i = 1; i <= maxe; i++)
		{
			a[i] += a[i - 1];
			if (a[i] > ans) ans = a[i];
		}
		cout << ans << endl;
	}
	return 0;
}