#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 50005;
int a[maxn], n, m, ans;
bool check(int x)
{
	int sum, last;
	sum = 0; last = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] - last<x) { sum += 1; continue; }
		last = a[i];
	}
	if (sum>m) return 0;
	return 1;
}
int main()
{
	int L, R, mid;
	while (scanf("%d %d %d\n", &L, &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		a[++n] = L;
		R = L;
		L = 0;
		while (L <= R)
		{
			mid = L + (R - L) / 2;
			if (check(mid)) { ans = mid; L = mid + 1; }
			else R = mid - 1;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}