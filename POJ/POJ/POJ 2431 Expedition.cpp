#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

int L, P, N;
pair<int, int> a[10000 + 7];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}
void slove() {
	a[N].first = 0;
	a[N].second = 0;
	N++;
	sort(a, a + N, cmp);

	priority_queue<int> que;
	int ans = 0, pos = 0, tank = P;
	for (int i = 0; i < N; i++) {
		int d = L - a[i].first - pos;
		while (tank - d < 0) {
			if (que.empty()) {
				printf("-1\n");
				return;
			}
			tank += que.top();
			que.pop();
			ans += 1;
		}
		que.push(a[i].second);
		pos = L - a[i].first;
		tank -= d;
	}
	printf("%d\n", ans);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &a[i].first, &a[i].second);
	scanf("%d%d", &L, &P);
	slove();
	return 0;
}