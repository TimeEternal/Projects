#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int m, n,ans=0;
int vis[8];
char map[8][8];
void dfs(int row,int num) {
	if (num == 0) { ans++; return; }
	if (m - row <num || row >= m) return;//���ʣ������С��Ҫ�������� �����Ѿ�����������
	for(int i=0;i<m;i++)
		if (map[row][i] == '#' && !vis[i]) {//���벻��
			vis[i] = 1;
			dfs(row + 1,num-1);
			vis[i] = 0;
		}
	dfs(row + 1, num);
}
int main()
{
	while (cin >> m >> n&&m != -1 && n != -1) {
		ans = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				cin >> map[i][j];
		dfs(0,n);
		cout << ans << endl;
	}
	return 0;
}