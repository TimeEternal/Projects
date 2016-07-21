#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n; int s = 0;
int p[100];

void permutations(int *a, int cur)
{
	if (cur == n) {
		for (int i = 0; i < n; i++) cout << a[i];
		cout << endl;
		s++;
		return;
	}
	for(int i=0;i<n;i++)
		if (!i || p[i] != p[i - 1]) {
			bool flag = 1; int c1 = 0, c2 = 0;
			for (int j = 0; j < cur; j++)
				if (a[j] == p[i])c1++;
			for (int j = 0; j < n; j++)
				if (p[j] == p[i])c2++;
			if (c1 < c2) {
				a[cur] = p[i];
				permutations(a, cur + 1);
			}
		}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p, p + n);
	int *a = new int[n];
	permutations(a, 0);
	cout << s << endl;
	return 0;
}