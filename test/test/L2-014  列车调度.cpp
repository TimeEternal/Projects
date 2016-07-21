/* http://blog.csdn.net/aozil_yang/article/details/51927477 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 100000 + 10;
int a[maxn];
int sum[maxn << 2];
int cnt;
void pushup(int rt) {
	sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
}
void build(int l, int r, int rt) {
	if (l == r) {
		sum[rt] = a[++cnt];
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, rt << 1);
	build(m + 1, r, rt << 1 | 1);
	pushup(rt);
}
int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		return sum[rt];

	}
	int m = (l + r) >> 1;
	int ret = -maxn - 10;
	if (L <= m) ret = max(ret, query(L, R, l, m, rt << 1));
	if (m < R) ret = max(ret, query(L, R, m + 1, r, rt << 1 | 1));
	return ret;
}
void update(int p, int add, int l, int r, int rt) {
	if (l == r) {
		sum[rt] = add;
		return;

	}
	int m = (l + r) >> 1;
	if (p <= m)update(p, add, l, m, rt << 1);
	else update(p, add, m + 1, r, rt << 1 | 1);
	pushup(rt);
}
int pos[maxn];
int main() {


	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)scanf("%d", &a[i]), pos[a[i]] = i;
	build(1, n, 1);
	int sum = 0, ans = 0;
	while (sum < n) {
		int l = 1;
		while (l <= n) {
			int cur = query(l, n, 1, n, 1);
			if (cur < 0)break;
			++sum;
			l = pos[cur];
			update(l, -maxn, 1, n, 1);
			++l;
		}
		++ans;
	}
	printf("%d\n", ans);
	return 0;
}
