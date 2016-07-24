#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 100000 + 7;
const int INF = 0x3f3f3f3f;
int main()
{
	int start, last, s;
	int a[MAXN] = { 0 }, m, n, sum = 0, max = -INF;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> m;
		sum = 0; max = -INF;
		for (int j = 1; j <= m; j++)
			cin >> a[j];
		s = 1;
		for (int j = 1; j <= m;j++)
		{
			sum += a[j];
			if (sum >= max) {//7个 1 0 0 0 3 0 0 4个 -1 -2 -3 -4
				start = s;
				max = sum;
				last = j;
			}
			if (sum<0) {
				s = j + 1;
				sum = 0;//这里sum要初始
			}
		}
		cout << "Case " << i + 1 << ":" << endl;
		cout << max << " " << start << " " << last << endl;
		if (i != n - 1) cout << endl;
	}
	return 0;
}

/*
dp的话 d[i]代表以i为结尾的最大 根据d[i-1]正负 更新起始点就好了
*/