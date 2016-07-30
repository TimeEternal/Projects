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
			e > maxe ? maxe = e : maxe;
		}
		int ans = 1;
		for (int i = 1; i <= maxe; i++)
		{
			a[i] += a[i - 1];
			if (a[i] > ans) ans = a[i];
		}
		cout << ans << endl;
	}
	return 0;
}