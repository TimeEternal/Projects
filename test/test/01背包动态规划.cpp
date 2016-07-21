#include<iostream>
using namespace std;
int w[100];        //物品重量序列
int v[100];        //物品价值序列
int bag;           //背包容量
int number;        //物品数量
int table[50][50]; //
int i;
void input()
{
	cout << "输入物品数量：";
	cin >> number;
	cout << "输入物品重量序列：";
	for (i = 1; i <= number; i++)
		cin >> w[i];
		cout << "输入物品价值序列：";
	for (i = 1; i <= number; i++)
		cin >> v[i];
		cout << "输入背包容量：";
	cin >> bag;
}
int f(int i, int j)//判序号越界
{
	if (i>number || j <= 0)
		return 0;

	return table[i][j];
}
int max(int a, int b)
{
	if (a>b)
		return a;
	return b;
}
void set_table()
{
	for (int j = 1; j <= bag; j++)       //j 为背包将放物品重量
	{
		for (int i = number; i >= 1; i--)//i 为物品数量
		{
			if (j<w[i])
				table[i][j] = f(i + 1, j);
			else
			{
				table[i][j] = max(f(i + 1, j),f(i + 1, j - w[i]) + v[i]);
			}
		}
	}
}
int serch(int i, int j)
{
	if (table[i + 1][j]>table[i + 1][j - w[i]] + v[i])
		return 0;
	return 1;
}
int main()
{
	input();
	set_table();

	cout <<endl<< "最大价值：" << table[1][bag] << endl;
	cout << "最大价值的物品序列：";
	int i = 1;

	while (i <= bag)//输出最大价值的物品的序列号！
	{
		if (serch(i, bag) == 1)
		{
			cout << i << " ";
			bag = bag - w[i];
		}
		i++;
	}

	cout << endl;
	system("pause");
	return 0;
}
