#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct room {
	double jean, catfood;
};
bool cmp(room x, room y) {
	return (x.jean / x.catfood )> (y.jean / y.catfood);
}
int main()
{
	int m, n; double ans = 0;
	room a[10005];
	while (cin >> m >> n&&m != -1 && n != -1) {
		ans = 0;
		for (int i = 0; i < n; i++) 
			cin >> a[i].jean >> a[i].catfood;
		sort(a,a + n, cmp);
		for (int i = 0; i < n; i++) {
			if (m >= a[i].catfood) {
				ans += a[i].jean;
				m -= a[i].catfood;
			}
			else {
				ans += m *a[i].jean / a[i].catfood;
				break;
			}
		}
		cout << setprecision(3) << setiosflags(ios::fixed) << ans << endl;
	}
	return 0;
}
