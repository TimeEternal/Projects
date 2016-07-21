#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}
int main()
{
	int n,max=0,a[12],gray;
	while (cin >> n&&n != 0) {
		max = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (max < a[i]) max = a[i];
		}
		cin >> gray;
		int ans = (max + 49) / 50;
		for (int i = 0; i < n; i++) a[i] = ans*50 - a[i];//求剩余 组成灰色
		while (gray > 0) {
			sort(a, a + n, cmp);
			if (a[2] == 0) {
				ans++;
				for (int i = 0; i < n; i++) a[i] = 50 + a[i];//添加颜料
			}
			a[0]--; a[1]--; a[2]--;
			gray--;
		}
		cout << ans << endl;
	}
	return 0;
}