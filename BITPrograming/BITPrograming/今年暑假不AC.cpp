#include<iostream>
#include<algorithm>
using namespace std;

struct show {
	int s, e;
};

bool cmp(show x, show y) {
	return x.e < y.e;
}
int main()
{
	show a[100];
	int n,ans=1,ce;
	while (cin >> n&&n != 0) {
		for (int i = 0; i < n; i++)  cin >> a[i].s >> a[i].e;
		sort(a, a + n, cmp);
		ans = 1; ce = a[0].e;
		for (int i = 1; i < n; i++) {
			if (a[i].s >= ce) {
				ans++;
				ce = a[i].e;
			}
		}
		cout << ans << endl;
	}
	return 0;
}