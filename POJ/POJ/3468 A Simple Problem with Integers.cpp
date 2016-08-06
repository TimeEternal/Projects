#include<iostream>
#include<cstdio>
using namespace std;

int x;
long sum[100000 + 7];
int main()
{
	int N, Q;
	cin >> N >> Q;
	sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		sum[i] += sum[i - 1] + x;
	}
	for (int i = 0; i < Q; i++) {
		int s, e, c;
		char op;
		cin >> op >> s >> e;
		if(op=='Q')
			cout << sum[e] - sum[s - 1] << endl;
		else {
			cin >> c;
			for (int j = s; j <= e; j++)
				sum[j] += (j - s + 1)*c;
		}
	}
	return 0;
}