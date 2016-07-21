#include<iostream>
#include<cstdlib>
using namespace std;
int n, r;
int s[10];
void dfs(int i) {
	if (i >= r ) {
		for (int k = 0; k < r; k++)
			cout << s[k];
		cout << endl;
		return;
	}
	int t;
	if (i == 0) t = n;
	else t = s[i - 1] - 1;
	for (int k = t; k >= r-i; k--) {
		s[i] = k;
		dfs(i + 1);
	}
}
int main()
{
	cin >> n >> r;
	dfs(0);
	return 0;
}