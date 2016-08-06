/*
https://comzyh.com/blog/archives/568/
Dinic算法的基本思路:

根据残量网络计算层次图。
在层次图中使用DFS进行增广直到不存在增广路
重复以上步骤直到无法增广
*/
#include <cstdio>
#include<queue>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define min(x,y) ((x<y)?(x):(y))
using namespace std;
const int MAX = 0x5fffffff;//
int tab[250][250];//邻接矩阵 
int dis[250];//距源点距离,分层图 
int q[2000], h, r;//BFS队列 ,首,尾 
int N, M, ANS;//N:点数;M,边数 
int BFS(){	queue<int> q;	memset(dis, -1, sizeof(dis));	dis[1] = 0;	q.push(1);	while (!q.empty())	{		int h = q.front();		for (int i = 1; i <= N; i++)			if (dis[i] < 0 && tab[h][i]) {				dis[i] = dis[h] + 1;				q.push(i);			}		q.pop();	}	if (dis[N] > 0) return 1;	else return 0;}
//Find代表一次增广,函数返回本次增广的流量,返回0表示无法增广 
int find(int x, int low)//Low是源点到现在最窄的(剩余流量最小)的边的剩余流量
{
	int i, a = 0;
	if (x == N)return low;//是汇点 
	for (i = 1; i <= N; i++)
		if (tab[x][i] >0 //联通 
			&& dis[i] == dis[x] + 1 //是分层图的下一层 
			&& (a = find(i, min(low, tab[x][i]))))//能到汇点(a <> 0) 
		{
			tab[x][i] -= a;
			tab[i][x] += a;
			return a;
		}
	return 0;

}
int main()
{
	//freopen("ditch.in" ,"r",stdin );
	//freopen("ditch.out","w",stdout);
	int i, f, t, flow, tans;
	while (scanf("%d%d", &M, &N) != EOF) {
		memset(tab, 0, sizeof(tab));
		for (i = 1; i <= M; i++)
		{
			scanf("%d%d%d", &f, &t, &flow);
			tab[f][t] += flow;
		}
		//
		ANS = 0;
		while (BFS())//要不停地建立分层图,如果BFS不到汇点才结束 
		{
			while (tans = find(1, 0x7fffffff))ANS += tans;//一次BFS要不停地找增广路,直到找不到为止 
		}
		printf("%d\n", ANS);
	}
	system("pause");
	return 0;
}