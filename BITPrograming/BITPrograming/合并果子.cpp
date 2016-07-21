#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 10001

int p[MAXN],q[MAXN];		//a<=b<=c<=d  a,c合并出e e位于q首 下一个合并出的f 
//会由ce 或cd构成 一定会有f>=e  可以共用一维数组 因为每次出两个 入一个

int main(void)
{
	int n;
	while (cin >> n)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			cin >> p[i];
		}

		sort(p, p + n);	//将果子按重量排序，得到优先队列1

		int sum = 0;
		int f1 = 0, r1 = n, f2 = 0, r2 = 0;		//初始化两队列
		while (true)
		{
			//合并的新果子堆放在队列2中，所以当队列1为空且队列2只有一堆果子时结束合并
			if (f1 == r1 && f2 + 1 == r2)
			{
				break;
			}

			int s = 0;
			int j;
			for (j = 0; j < 2; j++)		//取两堆重量最小的果子
			{
				if (f1 != r1)			//队列1是否为空
				{
					if (f2 != r2)		//队列2是否为空
					{
						//选出两队列队首更小的一堆果子
						s += p[f1] < q[f2] ? p[f1++] : q[f2++];
					}
					else
					{
						s += p[f1++];
					}
				}
				else
				{
					s += q[f2++];
				}
			}

			sum += s;		//统计总数
			q[r2++] = s;	//因为新合并出的果子堆的重量一定比之前的都大，所以，直接入队尾即可
		}
		cout << sum << endl;
	}
	return 0;
}