#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct node {
	string op;
	int t;
}opt[100];
int cal(string op, int x, int y) {
	if (op == "OR") return x | y;
	else if (op == "XOR") return x^y;
	else return x&y;
}
int main()
{
	int n, m,ans=-9999999;
	string s; int x;
	cin >> n >> m;
	for (int i = 0; i < n&& i < 27; i++) cin >> opt[i].op >> opt[i].t;
	for (int i = 27; i < n; i++)cin >> s >> x;
	for (int i = 0; i <= m; i++) {
		int t=i;
		for (int j = 0; j < n&&j < 27; j++) {
			t = cal(opt[j].op, t, opt[j].t);
		}
		if (t > ans)ans = t;
	}
	cout << ans << endl;
	return 0;
}
/*
���²�һ�£������������൱�ж�������һ��д���ˣ�������ܹ�9���㦲=��=��
�ȿȣ���������ɡ���Ϊ��λ���㣬���Ը�λ֮�以��Ӱ�죬ֱ��ȫ��ת�ɶ����������ͺá�
������ö��m�����Ƶ�ÿһλ���Ӹ�λ����λ��ÿһλ���κ�n�β����в����Ķ�Ӧλ����λ
����õ�һ������������¼��������
����ö��ǰ���λ��ʱ����������һλѡ0ʱ������ڵ���ѡ1�Ľ������ô�Ժ��ÿһλ��
ѡ0/1�Կ��ˣ�����0/1�ĸ������ѡ�ĸ���
��û�г��֢��е��������m����һλΪ0����ô��ֻ��ѡ0�ˣ�ֱ��������
��û�г��֢��е��������m����һλΪ1����ʱ��ѡ0/1�Կɣ��Ƚ�һ�µõ������������
ʱ��ѡ0ʱ������ڵ���ѡ1�Ľ�����Ǿͱ��һ�£��Ժ��ÿһλ�͵ö���������������ˡ�
ÿһλ�Ľ����Ӧ�洢���������תΪʮ���ƾ��Ǵ��ˡ�

*/