#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
struct point {
	int x, y;
}s,e;
int m, n, time;
int dis[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool vis[10][10], flag = 0;
char map[10][10];
void dfs(point t,int sum) {
	if (t.x == e.x&&t.y == e.y&&sum == time) { flag = 1; return; }
	//cout << t.x << " " << t.y << " " << sum << endl;
	if (flag) return;
	int mindis = abs(t.x - e.x) + abs(t.y - e.y);  /*��ǰ�㵽�յ����̾���*/
	if (mindis>time - sum || (mindis + time - sum) % 2 != 0)
		return;
	point tt;
	for (int i = 0; i < 4; i++) {
		tt.x = t.x + dis[i][0];
		tt.y = t.y + dis[i][1];
			if (map[tt.x][tt.y] != 'X' && !vis[tt.x][tt.y])
			{
				vis[tt.x][tt.y] = 1;
				dfs(tt, sum + 1);
				vis[tt.x][tt.y] = 0;
			}
	}
}
int main()
{
	while (cin >> m >> n >> time&&m != 0 && n != 0 && time != 0) {
		flag = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i <= n + 1; i++) { map[0][i] = 'X'; map[m + 1][i] = 'X'; }
		for (int i = 0; i <= m + 1; i++) { map[i][0] = 'X'; map[i][n + 1] = 'X'; }
		for(int i=1;i<=m;i++)
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S') { s.x = i; s.y = j; }
				if (map[i][j] == 'D') { e.x = i; e.y = j; }
			}
		vis[s.x][s.y] = 1;
		dfs(s, 0);
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
/*
������Ŀ��doggie�����ڵ�t�뵽���ſڡ�Ҳ������Ҫ��t-1����
��doggie��ʼ��λ��Ϊ��sx,sy��,Ŀ��λ��Ϊ��ex,ey��.
���abs(ex-x)+abs(ey-y)Ϊż������abs(ex-x)��abs(ey-y)��ż����ͬ��
������Ҫ��ż������
��abs(ex-x)+abs(ey-y)Ϊ����ʱ����abs(ex-x)��abs(ey-y)��ż�Բ�ͬ��
����Ŀ��λ�þ���Ҫ�������������ж���ż�����������Խ�ʡ�ܶ�ʱ�䣬
��Ȼ�Ļ����׳�ʱ��t-sumΪ����Ŀ��λ�û���Ҫ���ٲ���
��Ϊ��ĿҪ��doggie�����ڵ�t�뵽���ŵ�λ�ã����ԣ�t-step����
abs(ex-x)+abs(ey-y)����ż�Ա�Ȼ��ͬ��
���temp=��t-sum��+-������(abs(ex-x)+abs(ey-y))��ȻΪż����
http://www.cnblogs.com/zhourongqing/archive/2012/04/28/2475684.html
*/