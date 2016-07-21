#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAX = 1000 + 7;
int father[MAX];
int rak[MAX];
void init(int n) {
	for (int i = 1; i <= n; i++) {
		father[i] = i;
		rak[i] = 0;
	}
}

int find(int x) {
	if (father[x] != x)
		father[x] = find(father[x]);
	return father[x];
}

void merge(int x, int y) {
	int xx = find(x), yy = find(y);
	if (rak[yy] > rak[xx]) {
		father[xx] = yy;
	}
	else if (rak[yy] < rak[xx]) {
		father[yy] = xx;
	}
	else {
		father[xx] = yy;
		rak[yy]++;
	}
}

int main()
{
	int N, M;
	while (cin >> N >> M&&N != 0) {
		init(N);
		while (M--) {
			int s, e;
			cin >> s >> e;
			merge(s, e);
		}
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			if (father[i] ==i) { sum++; }
		}
		cout << sum - 1 << endl;
	}
	return 0;
}