/*
X ������һ���ع����⡣�� n x m �����ӵľ���ÿ�����ӷ�һ��������ÿ���������ż�ֵ��ǩ��

�ع�����������Ͻǣ����������½ǡ�

С���������ع�����ڣ�����Ҫ����ֻ�����һ��������ߡ�

�߹�ĳ������ʱ������Ǹ������еı�����ֵ��С���������ⱦ����ֵ����С���Ϳ�������������Ȼ��Ҳ���Բ��ã���

��С���ߵ�����ʱ����������еı���ǡ����k��������Щ�����Ϳ����͸�С����

�����С����һ�㣬�ڸ����ľ����£����ж����ֲ�ͬ���ж������ܻ����k��������
*/
/*#include<iostream>
#incl��*ude<vector>
using namespace std;
//���ù��Ᵽ�����ֵ һ��һ���� ���õı����ǰ�ߴ� �������� weight map[x][y]
int map[52][52];
int m, n, k,sum=0;
void dp(int x, int y,int weight,int s) {
	if (x == m&&y == n&&(s == k|| map[x][y] > weight&&s-1==k)) sum += 1;
	if (map[x][y] > weight&&map[x][y]!=-1&&s<=k) {
		dp(x + 1, y, map[x][y], s+1);
		dp(x , y + 1, map[x][y], s+1);
		dp(x + 1, y, weight, s);
		dp(x, y + 1, weight, s);
	}
	if (map[x][y] < weight&&map[x][y] != -1 && s <= k) {
		dp(x + 1, y, weight, s);
		dp(x, y + 1, weight, s);
	}
}
int main()
{
	memset(map, -1, sizeof(map));
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	dp(1, 1, 0, 0);
	cout << sum;
	return 0;
}*/
#include <cstdio>
#include <cstring>
#include<Windows.h>
#define N 1000000007
int n, m, k;
int map[50][50];
int vis[50][50][15][15];//vis�����м�¼����״̬   xy���� ӵ�б������� ӵ�б�������ֵ(��4�������꾡Ψһ������ûһ�ֿ���) 
 //  ��   vis[3][4][5][6]=7 ������map[3][4]��������5������ ��������ֵ��6 �ǵ����յ���7��·��

int dfs(int x, int y, int num, int max)//��ǰλ��   ӵ�б�������� ӵ�еı�������ֵ
 {
     if (vis[x][y][num][max + 1] != -1)//��Ϊ�����п���Ϊ0���Զ���maxʱ����Сֵ-1 ��͵����޷���Ϊ�±�ʹ��  ʵ����������������б����ֵû��0 �����е�+1 ȥ��Ҳ�ǿ��Ե�
     {
         return vis[x][y][num][max + 1];
     }//���仯�ļ����ָ��������
     if (x == n&&y == m)
     {
         if (num == k)return vis[x][y][num][max + 1] = 1;//�������� ��ǰ�㵽Ŀ����1�ַ���
         else if (num == k - 1 && max<map[x][y])return vis[x][y][num][max + 1] = 1;//ͬ���������� ��ǰ�㵽Ŀ����1�ַ���
         else return vis[x][y][num][max + 1] = 0;//���������� ��ǰ�㵽Ŀ����0�ַ���
     }
     long long s = 0;
     if (x + 1 <= n)//����������
     {
         if (max<map[x][y])
         {
             s += dfs(x + 1, y, num + 1, map[x][y]);
             s%N;
         }
             s += dfs(x + 1, y, num, max);
             s%N;
     }
     if (y + 1 <= m)
     {
         if (max<map[x][y])
         {
             s += dfs(x, y + 1, num + 1, map[x][y]);
             s%N;
         }
             s += dfs(x, y + 1, num, max);
             s%N;
	}
     return vis[x][y][num][max + 1] = s%N;;
 }
 int main(int argc, char const *argv[])
 {
 //    freopen("C:\\Users\\cong\\Desktop\\input.txt","r",stdin); 
 //    freopen("C:\\Users\\cong\\Desktop\\output.txt","w",stdout); 

     scanf("%d%d%d", &n, &m, &k);

     for (int i = 1; i <= n; i++)
     {
         for (int j = 1; j <= m; j++)
         {
             scanf("%d", &map[i][j]);
         }
     }//��ʼ�ع�
     memset(vis, -1, sizeof(vis));
     dfs(1, 1, 0, -1);
     printf("%d", vis[1][1][0][0]);
	 system("pause");
     return 0;
 }