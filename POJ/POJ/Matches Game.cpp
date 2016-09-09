#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	int m, x, ans = 0;
	while (cin >> m) {
		ans = 0;
		for (int i = 0; i < m; i++) {
			cin >> x;
			ans = ans ^ x;
		}
		if (ans == 0) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}