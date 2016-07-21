#include <cstring>
#include <cstdio>

using namespace std;

int H[10][10];
int V[10][10];

int main()
{
	int  n, m, x, y, T = 0;
	char c;
	while (~scanf("%d%d", &n, &m)) {
		getchar();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				V[i][j] = H[i][j] = 0;
		for (int i = 1; i <= m; ++i) {
			scanf("%c%d%d", &c, &x, &y);
			getchar();
			if (c == 'H')
				H[x][y] = 1;
			else
				V[y][x] = 1;
		}
		if (T++) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n", T);

		int sum = 0;
		for (int len = 1; len < n; ++len) {
			int count = 0, flag = 0;
			for (int i = 1; i + len <= n; ++i)
				for (int j = 1; j + len <= n; ++j) {
					flag = 1;
					for (int h = j; h < j + len; ++h)
						if (!H[i][h] || !H[i + len][h]) flag = 0;
					for (int v = i; v < i + len; ++v)
						if (!V[v][j] || !V[v][j + len]) flag = 0;
					count += flag;
				}
			sum += count;
			if (count) printf("%d square (s) of size %d\n", count, len);
		}

		if (!sum) printf("No completed squares can be found.\n");
	}
	return 0;
}