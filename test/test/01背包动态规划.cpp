#include<iostream>
using namespace std;
int w[100];        //��Ʒ��������
int v[100];        //��Ʒ��ֵ����
int bag;           //��������
int number;        //��Ʒ����
int table[50][50]; //
int i;
void input()
{
	cout << "������Ʒ������";
	cin >> number;
	cout << "������Ʒ�������У�";
	for (i = 1; i <= number; i++)
		cin >> w[i];
		cout << "������Ʒ��ֵ���У�";
	for (i = 1; i <= number; i++)
		cin >> v[i];
		cout << "���뱳��������";
	cin >> bag;
}
int f(int i, int j)//�����Խ��
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
	for (int j = 1; j <= bag; j++)       //j Ϊ����������Ʒ����
	{
		for (int i = number; i >= 1; i--)//i Ϊ��Ʒ����
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

	cout <<endl<< "����ֵ��" << table[1][bag] << endl;
	cout << "����ֵ����Ʒ���У�";
	int i = 1;

	while (i <= bag)//�������ֵ����Ʒ�����кţ�
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
