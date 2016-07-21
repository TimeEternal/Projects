/*
Ҫ�ж�һ�����ͼG(V,E)(������������������)��ŷ��ͼ����������:
������һ��ͼ����ͼG'���ڲ��۷�������������Gͬ��������G'������G����������ߡ�
��ô�������һ��ͼG'ʹ��G'����ŷ����·����ôG�ʹ���ŷ����·��
��˼·�ͽ����ͼת��������ͼ�жϡ�ʵ�ֵ�ʱ������ʹ����������ģ�͡�
�����⹹��һ��G'����Ii��ʾ��i�������ȣ�Oi��ʾ��i����ĳ��ȡ��������һ����k��
|Ok-Ik|mod 2=1����ôG������ŷ����·�����������������Ii>Oi�ĵ��Դ������iһ��
����Ϊ(Ii-Oi)/2�ıߣ���������Ii<Oi�ĵ��i�������һ������Ϊ(Oi-Ii)/2�ıߡ�
������ڽڵ�U��V�������(U��V)��E����ôU��V֮�以�ཨ������Ϊ���޴�ıߡ�
������������������ڡ�|Ii-Oi|/2����ô�ʹ���ŷ����·��
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
//���б߾������飨�����ߣ� ÿ����Ķȶ���2  ��Ȼ����ŷ����·���������б�һ�Σ�
void dfs(int u) {
	for (int i = 0; i < vec[u].size(); i++) { //���ѽ����б����
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
			scanf("%d%d", &a, &b);  //��ͼ
			node.v = b;
			node.flag = 0;
			vec[a].push_back(node);//ÿ�������� ����˫���
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
4 1	��ʱ1�������	���1����					4
4 2												2
2 3												3
3 2												2
2 4												4
4 3												1
3 4												2
�˽�һ�µݹ�˳��								1
*/