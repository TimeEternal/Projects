#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

struct interval {
	double left, right;
};

bool cmp(interval a, interval b) {
	return a.left < b.left;
}

int main()
{
	int n, d, num = 1;
	interval a[1007];
	while (cin >> n >> d && !(n == 0 && d == 0)) {
		int ans = 1;
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			if (y > d || y < 0||d < 0) { ans = -1; }
			else {
				a[i].left = x - sqrt(d*d - y*y);
				a[i].right = x + sqrt(d*d - y*y);
			}
		}
		sort(a, a + n, cmp);
		double conend = a[0].right;
		for (int i = 1; i < n&&ans != -1; i++) {
			if (a[i].left > conend) {
				conend = a[i].right;
				ans++;
			}
			else if (a[i].right < conend) 
				conend = a[i].right;
		}
		printf("Case %d: %d\n", num++, ans);
	}
	return 0;
}