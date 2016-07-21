
/*��һ��������״�����̣���״�����ǲ�����ģ�����ڷ����ӣ�����û������Ҫ��ڷ�ʱ������������Ӳ��ܷ��������е�ͬһ�л���ͬһ�У����������ڸ�����״�ʹ�С�����̣��ڷ�k�����ӵ����п��еİڷŷ���C��*/
#include "iostream"

using namespace std;
int m,k;
int num;

char map[100][100];
int l[100];
void dfs(int i, int n)
{
	cout << i << " " << n << endl;
	if (n == 0) {      //���ӷ�����
		num++;
		return;
	}
	if (i >= m) {    // �Ѿ���������
		return;
	}
	if (n > m - i) {     //ʣ��������Ŀ��������
		return;
	}
	for (int j = 0; j<m; j++) {
		if (l[j] != 1 && map[i][j] == '#') {  //������ǰ�й�����ͬʱ��#
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
