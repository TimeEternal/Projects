/*
（1）递推
（2）考验分析问题能力
i % 2 == 0 ans[i] = 3*ans[i-2] + 2*ans[i-4] + 2*ans[i-6] + ... + 2*ans[0]
i % 2 != 0 ans[i] = 0
ans[0] = 1
*/
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	int ans[37], n, sum = 0;
	memset(ans, 0, sizeof(ans));
	ans[0] = 1;
	for (int i = 2; i <= 30; i++) {
		if (i % 2 == 0) {
			sum += ans[i - 2] * 2;
			ans[i] = sum + ans[i - 2];
		}
	}
	while (cin >> n&&n != -1) {
		cout << ans[n] << endl;
	}
	return 0;
}