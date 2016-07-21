#include<iostream>
using namespace std;
const int maxn = 25;
int n, k, m, a[maxn] = { 0 };
void go(int &s, int d, int l)
{
	while (l--) {
		do { s = (s + d + n - 1) % n + 1; } while (a[s] == 0);
	}
}
int main()
{
	int p1 = n, p2 = 1;//p1是A逆时针走 p2是B顺时针走 
	while (cin >> n >> k >> m&&n != 0) {
		int left = n;
		for (int i = 1; i < n + 1; i++) a[i] = i;
		while (left) {
			go(p1, 1, k);
			go(p2, -1, m);
			a[p1] = a[p2] = 0;
			cout << p1;
			if (p1 != p2) {
				cout << ',' << p2 << endl;
				left -= 2;
			}
			else {
				cout << endl;
				left -= 1;
			}
		}
	}
	return 0;
}