#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n, m, z, l;
		long long  ans = 0, a = 0;
		cin >> n >> m >> z >> l;
		for (int i = 2; i <= n; i++) {
			a = (a*m + z) % l;
			ans = (2*a)^ans;
		}
		cout << ans << endl;
	}
	return 0;
}