#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

const int  MAXN = 45000 + 7;
const int INF = 0x3f3f3f3f;

int father[300+7];  // 并查集 
int visit[MAXN]; // 记录最小生成树用到的边的下标 
int windex; // 记录最小生成树用到边的数量 

typedef struct node {
	int st, ed, w;
} node;

/**
* 预处理并查集数组
*/
void init()
{
	int i, len = sizeof(father) / sizeof(father[0]);

	for (i = 0; i < len; i++) {
		father[i] = i;
	}

}

/**
* kruskal使用贪心算法，将边按权值从小到大排序
*/
int cmp(const void *p, const void *q)
{
	node *a = (node *)p;
	node *b = (node *)q;
	return a->w - b->w;
}

/**
* 并查集寻找起始结点，路径压缩优化
*/
int findParent(int x)
{
	if (x != father[x]) {
		father[x] = findParent(father[x]);
	}
	return father[x];
}

/**
* 求最小生成树
*/
int minTree(node *points, int m, int n)
{
	init();

	int i, count, ans = 0, pa, pb;

	for (i = count = windex = 0; i < m; i++) {
		pa = findParent(points[i].st);
		pb = findParent(points[i].ed);

		if (pa != pb) {
			visit[windex++] = i;
			father[pa] = pb;
			ans += points[i].w;
			count++;
			//printf("%d %d\n", points[i].st, points[i].ed);
		}

		if (count == n - 1) {
			break;
		}
	}

	return ans;
}

/**
* 求次小生成树
*/
int secMinTree(node *points, int m, int n)
{
	int i, j, min, tmp, pa, pb, count;

	for (i = 0, min = INF; i < windex; i++) {
		init();
		// 求次小生成树 
		for (j = count = tmp = 0; j < m; j++) {
			if (j != visit[i]) {
				pa = findParent(points[j].st);
				pb = findParent(points[j].ed);

				if (pa != pb) {
					count++;
					tmp += points[j].w;
					father[pa] = pb;
				}

				if (count == n - 1) {
					break;
				}
			}
		}

		if (count == n - 1 && tmp < min)  min = tmp;
	}
	return min;
}


int main(void)
{
	int i, t, n, m;
	node *points = NULL;

	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &m);

		points = (node *)malloc(sizeof(node) * m);

		for (i = 0; i < m; i++) {
			scanf("%d %d %d", &points[i].st, &points[i].ed, &points[i].w);
		}
		qsort(points, m, sizeof(points[0]), cmp);
		int ans1 = minTree(points, m, n);
		int ans2 = secMinTree(points, m, n);
		printf("%d %d\n", ans1, ans2);
	}
	free(points);
	return 0;
}
