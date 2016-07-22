#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

int len;
char s[50];
int cnt[50];

int cnt_num(int r) {
	int n;
	n = len;
	if (s[n - r] == '0') return 0;
	cnt[0] = 1;
	for (int i = 1; i <= n - r; i++) {
		cnt[i] = 0;
		int minn;
		if (i - r<0) minn = 0;
		else minn = i - r;
		for (int j = minn; j<i; j++) {
			if ((j + 1<i || j == 0 && n - r>1) && s[j] == '0') continue;
			if (j + r == i) if (strncmp(s + j, s + n - r, r) >= 0) continue;
			cnt[i] += cnt[j];
		}
	}

	return cnt[n - r];
}

int main() {
	int r, c;
	while (1) {
		scanf("%s", s);
		if (s[0] == '#') break;
		len = strlen(s);
		int ans = 0;
		for (int i = 1; i<len; i++)
			ans += cnt_num(i);
		if (ans>0)
			printf("The code %s can represent %d numbers.\n", s, ans);
		else   printf("The code %s is invalid.\n", s);
	}
	return 0;
}
/*这题我不会 交一发测试正确性*/