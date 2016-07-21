#include<iostream>
#include<algorithm>
using namespace std;
int a[100000 + 7],n,m,ans;

bool fun(int x) {
	int s = 1, e = a[0] + x,i=1;
	while (i < n&&s!=m) {
		if (a[i] >= e) {
			e = a[i] + x;
			s += 1;
		}
		i++;
	}
	if (s == m)return true;
	else return false;
}
void binarysearch() {
	int left = 1, right = (a[n - 1] - a[0]) / (m-1);
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (fun(mid)) left = mid + 1; 
		else right = mid - 1;
	}
	cout << left-1 << endl;//很明显搜到最后 left right mid是相同的
}
int main()
{
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		binarysearch();
	}
	return 0;
}
