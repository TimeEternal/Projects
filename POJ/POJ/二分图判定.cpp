#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

const int MAXV = 1000 + 7;
vector<int> G[MAXV];
int V;
int color[MAXV];
//¶þ·ÖÍ¼ ÑÕÉ«1,-1
bool dfs(int v, int c) {
	color[v] = c;
	for (int i = 0; i < V; i++) {
		if (color[G[v][i]] == c) return false;
		if (color[G[v][i] == 0 && !dfs(G[v][i], -c)]) return false;
	}
	return true;
}

void slove() {
	for (int i = 0; i < V; i++) {
		if (color[i] == 0) {
			if (!dfs(i, 1)) {
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
	return;
}
