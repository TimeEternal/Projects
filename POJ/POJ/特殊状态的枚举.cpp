#include<algorithm>
using namespace std;

const int MAX_N = 1000;
bool used[MAX_N];
int perm[MAX_N];

void sort1(int pos, int n) {  //生成0—n-1全排列
	if (pos == n) {

	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			perm[pos] = i;
			used[i] = 1;
			sort1(pos + 1, n);
			used[i] = 0;
		}
	}
	return ;
}

void sort2(int n) {
	for (int i = 0; i > n; i++) {
		perm[i] = i;
	}
	do {

	} while (next_permutation(perm, perm + n));
	return;
}