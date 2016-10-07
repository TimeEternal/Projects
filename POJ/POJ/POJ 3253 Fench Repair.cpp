#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
int N, L[20000 + 7];

void slove() {
	ll ans = 0;
	while (N > 1) {
		int m1 = 0, m2 = 1;
		if (L[m2] < L[m1]) swap(m1, m2);
		for (int i = 2; i < N; i++) {
			if (L[i] < L[m1]) {
				m2 = m1;
				m1 = i;
			}
			else if (L[i] < L[m2]) m2 = i;
		}
		ans += L[m1] + L[m2];
		if (N - 1 == m1) swap(m1, m2);
		L[m1] = L[m1] + L[m2];
		L[m2] = L[N - 1];
		N--;
	}
	printf("%lld\n", ans);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", L + i);
	slove();
	return 0;
}