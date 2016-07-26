#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int s[100000 + 7];
int main()
{
	int n;
	while (cin >> n&&n != 0) {
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= n; i++) {
			int x, y;
			cin >> x >> y;
			s[x] += 1;
			s[y + 1] -= 1;
		}
		for (int i = 1; i <= 100000; i++) {
			s[i] += s[i - 1];
		}
		for (int i = 1; i <= n; i++) {
			cout << s[i];
			if (i != n) cout << " ";
		}
		cout << endl;
	}
	return 0;
}