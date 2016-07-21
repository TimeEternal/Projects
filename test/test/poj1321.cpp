/*DFS，没想法就很难很难，有想法就很容易的题

棋盘规则与否不是难点，无论规则不规则都可以用标记去解决

难点在于 棋盘的行数（列数）n 与 待摆放的棋子总数k  的关系为k <= n


K<n时就让人有点迷糊不

K == n时还是比较好办的
知怎样处理了


	网上普遍做法都是 逐行深搜，效率不错，我也稍微借鉴了，具体看程序，不多说了，搜索的题抽象性太强，文字很难说清楚

*/
	//Memory Time 
	//184K   32MS 

#include<iostream>
using namespace std;

bool chess[9][9];
bool vist_col[9];  //列标记
int status;  //状态计数器
int n, k;

void DFS(int row, int num)  //逐行搜索，row为当前搜索行，num为已填充的棋子数
{
	if (num == k)
	{
		status++;
		return;
	}

	if (row>n)    //配合下面DFS(row+1,num); 语句使用，避免搜索越界
		return;

	for (int j = 1; j <= n; j++)
		if (chess[row][j] && !vist_col[j])
		{
			vist_col[j] = true;  //放置棋子的列标记
			DFS(row + 1, num + 1);
			vist_col[j] = false; //回溯后，说明摆好棋子的状态已记录，当前的列标记还原
		}

	DFS(row + 1, num);   //这里是难点，当k<n时，row在等于n之前就可能已经把全部棋子放好
						 //又由于当全部棋子都放好后的某个棋盘状态已经在前面循环时记录了
						 //因此为了处理多余行，令当前位置先不放棋子，搜索在下一行放棋子的情况
	return;				//不放 多搜这么多次啊 感觉复杂度好高
}

int main(int i, int j)
{
	while (cin >> n >> k)
	{
		if (n == -1 && k == -1)
			break;

		/*Initial*/

		memset(chess, false, sizeof(chess));
		memset(vist_col, false, sizeof(vist_col));
		status = 0;

		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				char temp;
				cin >> temp;
				if (temp == '#')
					chess[i][j] = true;
			}

		DFS(1, 0);  //注意初始化的值别弄错了
		cout << status << endl;
	}
	return 0;
}
