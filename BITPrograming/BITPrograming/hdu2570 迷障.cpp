#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int c; cin >> c;
	int s[100];
	while (c--) {
		int n, v, w;
		cin >> n >> v >> w;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		sort(s, s + n);
		float curm = 0;
		int curv = 0;
		for (int i = 0; i < n; i++)
		{
			if ((curm + s[i] / 100.0*v) / (curv + v) <= 0.01*w)
			{
				curm += s[i] / 100.0*v;
				curv += v;
			}
			else
				break;

		}
		double ans;
		if (curm == 0) { ans = 0; }
		else { ans = curm / curv; }
		cout << curv << " " << setprecision(2) << setiosflags(ios::fixed) << ans << endl;
	}
	return 0;
}