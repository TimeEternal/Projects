/*
https://comzyh.com/blog/archives/568/
Dinic�㷨�Ļ���˼·:

���ݲ������������ͼ��
�ڲ��ͼ��ʹ��DFS��������ֱ������������·
�ظ����ϲ���ֱ���޷�����
*/
#include <cstdio>
#include<queue>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define min(x,y) ((x<y)?(x):(y))
using namespace std;
const int MAX = 0x5fffffff;//
int tab[250][250];//�ڽӾ��� 
int dis[250];//��Դ�����,�ֲ�ͼ 
int q[2000], h, r;//BFS���� ,��,β 
int N, M, ANS;//N:����;M,���� 
int BFS(){	queue<int> q;	memset(dis, -1, sizeof(dis));	dis[1] = 0;	q.push(1);	while (!q.empty())	{		int h = q.front();		for (int i = 1; i <= N; i++)			if (dis[i] < 0 && tab[h][i]) {				dis[i] = dis[h] + 1;				q.push(i);			}		q.pop();	}	if (dis[N] > 0) return 1;	else return 0;}
//Find����һ������,�������ر������������,����0��ʾ�޷����� 
int find(int x, int low)//Low��Դ�㵽������խ��(ʣ��������С)�ıߵ�ʣ������
{
	int i, a = 0;
	if (x == N)return low;//�ǻ�� 
	for (i = 1; i <= N; i++)
		if (tab[x][i] >0 //��ͨ 
			&& dis[i] == dis[x] + 1 //�Ƿֲ�ͼ����һ�� 
			&& (a = find(i, min(low, tab[x][i]))))//�ܵ����(a <> 0) 
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
		while (BFS())//Ҫ��ͣ�ؽ����ֲ�ͼ,���BFS�������Ž��� 
		{
			while (tans = find(1, 0x7fffffff))ANS += tans;//һ��BFSҪ��ͣ��������·,ֱ���Ҳ���Ϊֹ 
		}
		printf("%d\n", ANS);
	}
	system("pause");
	return 0;
}