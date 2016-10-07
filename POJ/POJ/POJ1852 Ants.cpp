#include<cstdio>
#include<algorithm>
using namespace std;

int a[1000000 + 7];
void slove(int l, int n) {
	int minans = 0,maxans = 0;
	for (int i = 0; i < n; i++) {
		minans = max(minans, min(a[i], l - a[i]));
		maxans = max(maxans, max(a[i], l - a[i]));
	}
	printf("%d %d\n", minans, maxans);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int l, n;
		scanf("%d %d", &l, &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		slove(l, n);
	}
	return 0;
}