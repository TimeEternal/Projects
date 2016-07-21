#include<iostream>
#include<algorithm>
using namespace std;

char a[2005];
int num = 0;
bool cmp(int x, int y)
{
	int tx = x, ty = y;
	while (tx < ty) {
		if (a[tx] == a[ty]) { tx++; ty--; }
		if (a[tx] > a[ty]) { return 1; }
		if (a[tx] < a[ty]) { return 0; }
	}
	return 1;
}
void greedy(int s,int e) {
	if (s > e)return;
	if (num!=0&&num % 80 == 0) cout << endl;
	if (cmp(s, e)) {
		cout << a[e];
		num++;
		greedy(s, e - 1);
	}
	else {
		cout << a[s];
		num++;
		greedy(s+1, e);
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	greedy(0, n - 1);
	if (num % 80 != 0)cout << endl;
	return 0;
}
//DCBACD
//DCABCD
