#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 10001

int p[MAXN],q[MAXN];		//a<=b<=c<=d  a,c�ϲ���e eλ��q�� ��һ���ϲ�����f 
//����ce ��cd���� һ������f>=e  ���Թ���һά���� ��Ϊÿ�γ����� ��һ��

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

		sort(p, p + n);	//�����Ӱ��������򣬵õ����ȶ���1

		int sum = 0;
		int f1 = 0, r1 = n, f2 = 0, r2 = 0;		//��ʼ��������
		while (true)
		{
			//�ϲ����¹��Ӷѷ��ڶ���2�У����Ե�����1Ϊ���Ҷ���2ֻ��һ�ѹ���ʱ�����ϲ�
			if (f1 == r1 && f2 + 1 == r2)
			{
				break;
			}

			int s = 0;
			int j;
			for (j = 0; j < 2; j++)		//ȡ����������С�Ĺ���
			{
				if (f1 != r1)			//����1�Ƿ�Ϊ��
				{
					if (f2 != r2)		//����2�Ƿ�Ϊ��
					{
						//ѡ�������ж��׸�С��һ�ѹ���
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

			sum += s;		//ͳ������
			q[r2++] = s;	//��Ϊ�ºϲ����Ĺ��Ӷѵ�����һ����֮ǰ�Ķ������ԣ�ֱ�����β����
		}
		cout << sum << endl;
	}
	return 0;
}