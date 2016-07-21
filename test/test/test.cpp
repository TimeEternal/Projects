
/*在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。*/
#include "iostream"

using namespace std;
int m,k;
int num;

char map[100][100];
int l[100];
void dfs(int i, int n)
{
	cout << i << " " << n << endl;
	if (n == 0) {      //棋子放完了
		num++;
		return;
	}
	if (i >= m) {    // 已经访问完了
		return;
	}
	if (n > m - i) {     //剩余棋子数目大于行数
		return;
	}
	for (int j = 0; j<m; j++) {
		if (l[j] != 1 && map[i][j] == '#') {  //不是以前有过的列同时是#
			l[j] = 1;
			dfs(i + 1, n - 1);
			l[j] = 0;
		}
	}
	dfs(i + 1, n);
}
int main()
{
	while (scanf("%d%d", &m, &k) == 2 && m != -1) {
		memset(l, 0, sizeof(l));
		num = 0;
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<m; j++) {
				cin >> map[i][j];
			}
		}
		dfs(0, k);
		cout << num << endl;
	}
	return 0;
}
