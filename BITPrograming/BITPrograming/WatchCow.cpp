/*
要判断一个混合图G(V,E)(既有有向边又有无向边)是欧拉图，方法如下:
假设有一张图有向图G'，在不论方向的情况下它与G同构。并且G'包含了G的所有有向边。
那么如果存在一个图G'使得G'存在欧拉回路，那么G就存在欧拉回路。
其思路就将混合图转换成有向图判断。实现的时候，我们使用网络流的模型。
现任意构造一个G'。用Ii表示第i个点的入度，Oi表示第i个点的出度。如果存在一个点k，
|Ok-Ik|mod 2=1，那么G不存在欧拉回路。接下来则对于所有Ii>Oi的点从源点连到i一条
容量为(Ii-Oi)/2的边，对于所有Ii<Oi的点从i连到汇点一条容量为(Oi-Ii)/2的边。
如果对于节点U和V，无向边(U，V)∈E，那么U和V之间互相建立容量为无限大的边。
如果此网络的最大流等于∑|Ii-Oi|/2，那么就存在欧拉回路。
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
const int MAX = 50005;
using namespace std;

struct NODE
{
	int v;
	int flag;
}node;
vector<NODE> vec[MAX];

int n, m;
//所有边经过两遍（两条边） 每个点的度都是2  必然存在欧拉回路（经过所有边一次）
void dfs(int u) {
	for (int i = 0; i < vec[u].size(); i++) { //深搜将所有边输出
		if (vec[u][i].flag == 0) {
			vec[u][i].flag = 1;
			//cout << u <<" "<< vec[u][i].v << endl;
			dfs(vec[u][i].v);
		}
	}
	printf("%d\n", u);
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++)
			vec[i].clear();
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);  //构图
			node.v = b;
			node.flag = 0;
			vec[a].push_back(node);//每条边两遍 所以双向边
			node.v = a;
			node.flag = 0;
			vec[b].push_back(node);
		}
		dfs(1);
	}
	return 0;
}
/*
1 2												1
2 1												4
1 4												3
4 1	此时1遍历完成	这个1返回					4
4 2												2
2 3												3
3 2												2
2 4												4
4 3												1
3 4												2
了解一下递归顺序								1
*/