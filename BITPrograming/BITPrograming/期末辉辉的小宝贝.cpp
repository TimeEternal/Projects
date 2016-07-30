#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	long long  n;
	while (cin >> n&&n != 0) {
		int ans = 0;
		while (n) {
			if (n & 1) ans++;
			n >>= 1;
		}
		cout << ans << endl;
	}
	return 0;
}