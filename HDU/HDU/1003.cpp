#include<iostream>
using namespace std;
int main()
{
	int start, last,s;
	int a[100001] = { 0 }, m, n, sum = 0, max = -100000000;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> m;
		sum = 0; max = -100000000;
		for (int k = 1; k <= m; k++)
			cin >> a[k];
		s = 1;
		for (int k = 1; k <= m;)
		{
			sum += a[k];
			k++;
			if (sum >= max) {//7个 1 0 0 0 3 0 0 4个 -1 -2 -3 -4
				start = s;
				max = sum;
				last = k - 1;//不管sum大于小于0都要和max比较 因为max本来就可以是负的
			}
			if (sum<0) {
				s = k;
				sum = 0;//这里sum要初始为0  上面有sum += a[k];原来我就写sum=a[k]加了两遍
			}
		}
		cout << "Case " << i + 1 << ":" << endl;
		cout << max << " " << start << " " << last << endl;
		if (i != n - 1) cout << endl;
	}
	return 0;
}