#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 300007;
//ÿһ�����϶���һ���������ϵ�Ԫ����Ϊ���Ľڵ㣬ÿ��������һ����һ�޶��ı�־���ǡ���//�������ĸ��ڵ�
//һ��ı�־���Լ�������±� ���� Ϊ-1
int father[MAX];  //father[x]��ʾx�ĸ��ڵ�
int num[MAX];    //sign[x] ������¼���Ҹ��ڵ�ʱ��;����·���Ľڵ㣬ѹ��·����ʱ���õ�
int rak[MAX];     //rak[x]  ��ʾx�ڵ������������
				   //��ʼ������
void Make_Set(int x)

{
	father[x] = x;    //��ʼ��һ��ʼÿ���ڵ�ĸ��ڵ㶼Ϊ����
	rak[x] = 0;      //��ʼ��һ��ʼÿ���������Ϊ
	num[x] = 1;
}
// Ѱ��xԪ�����ڵļ���Ҳ�������ӽڵ�ĸ��ڵ㣨��,�����õݹ���ң�����ʱѹ��·��
int Find_Set(int x)
{
	if (father[x] != x)
	{
		father[x] = Find_Set(father[x]); //����һ���ݹ�Ĺ��̣�����ʱѹ��·��
	}
	return father[x];
}
void Union(int x, int y)    //�ϲ��������ཻ�ļ��ϣ�x,y�ֱ�Ϊ������ͬ�ļ���
{
	x = Find_Set(x);
	y = Find_Set(y);
	if (x == y)  return;    //��Ϊͬһ���ϣ���ֱ�ӷ���
	if (rak[x] > rak[y])   //���x������ȱ�y���y���ӵ�x��
	{
		father[y] = x;
		num[x] += num[y];
	}
	else if (rak[x] < rak[y])
	{

		father[x] = y;
		num[y] += num[x];
	}
	else if (rak[x] == rak[y])  //�����������һ��
	{
		father[x] = y;           //��x���ӵ�y��
		rak[y]++;              //��ʱy�������+1
		num[y] += num[x];
	}
}
bool same(int x, int y)//�ж�x��y�Ƿ�����ͬһ������
{
	return Find_Set(x) == Find_Set(y);
}
int main()
{
	int m, n;
	while (cin >> n >> m&&!(n == 0 && m == 0)) {
		for (int i = 0; i < n; i++)Make_Set(i);
		while (m--) {
			int x,y,t;
			cin >> x>>y;
			while (x-- > 1) {
				cin >> t;
				Union(y, t);
			}
		}
		cout << num[Find_Set(0)] << endl;
	}
	return 0;
}