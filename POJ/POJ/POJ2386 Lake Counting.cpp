#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, M;
char map[107][107];
int ans = 0;

void dfs(int x,int y) {
	map[x][y] = '.';
	for(int dx=-1;dx<=1;dx++)
		for (int dy = -1; dy <= 1; dy++) {
			int xx = x + dx, yy = y + dy;
			if (0 <= xx&&xx < N && 0 <= yy&&yy <= M&&map[xx][yy] == 'W') {
				dfs(xx, yy);
			}
		}
}

void slove() {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'W') {
				dfs(i, j);
				ans++;
			}
		}
}

int main()
{
	scanf("%d %d\n", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &map[i][j]);
		}
		getchar();
	}
	slove();
	printf("%d\n", ans);
	return 0;
}