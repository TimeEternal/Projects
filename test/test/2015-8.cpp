/*
X 国王有一个地宫宝库。是 n x m 个格子的矩阵。每个格子放一件宝贝。每个宝贝贴着价值标签。

地宫的入口在左上角，出口在右下角。

小明被带到地宫的入口，国王要求他只能向右或向下行走。

走过某个格子时，如果那个格子中的宝贝价值比小明手中任意宝贝价值都大，小明就可以拿起它（当然，也可以不拿）。

当小明走到出口时，如果他手中的宝贝恰好是k件，则这些宝贝就可以送给小明。

请你帮小明算一算，在给定的局面下，他有多少种不同的行动方案能获得这k件宝贝。
*/
/*#include<iostream>
#incl、*ude<vector>
using namespace std;
//不用故意保留最大值 一个一个拿 后拿的必须比前者大 递增序列 weight map[x][y]
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
int vis[50][50][15][15];//vis数组中记录的是状态   xy坐标 拥有宝物数量 拥有宝物的最大值(这4个可以详尽唯一的描述没一种可能) 
 //  如   vis[3][4][5][6]=7 即当在map[3][4]且身上有5件宝物 宝物的最大值是6 是到达终点有7中路径

int dfs(int x, int y, int num, int max)//当前位置   拥有宝物的数量 拥有的宝物的最大值
 {
     if (vis[x][y][num][max + 1] != -1)//因为宝物有可能为0所以定义max时用最小值-1 这就导致无法作为下标使用  实际上如果测试数据中宝物价值没有0 将所有的+1 去掉也是可以的
     {
         return vis[x][y][num][max + 1];
     }//记忆化的记忆就指的是上面
     if (x == n&&y == m)
     {
         if (num == k)return vis[x][y][num][max + 1] = 1;//满足条件 当前点到目标有1种方案
         else if (num == k - 1 && max<map[x][y])return vis[x][y][num][max + 1] = 1;//同样满足条件 当前点到目标有1种方案
         else return vis[x][y][num][max + 1] = 0;//不满足条件 当前点到目标有0种方案
     }
     long long s = 0;
     if (x + 1 <= n)//可以向下走
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
     }//初始地宫
     memset(vis, -1, sizeof(vis));
     dfs(1, 1, 0, -1);
     printf("%d", vis[1][1][0][0]);
	 system("pause");
     return 0;
 }