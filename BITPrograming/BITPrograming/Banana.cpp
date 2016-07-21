#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 100000 + 7;
int father[MAX];  
int rak[MAX] = { 0 };
bool vis[MAX] = { 0 };
void Make_Set(int x)

{
	father[x] = x;    
	rak[x] = 0;      
}
int Find_Set(int x)
{
	if (father[x] != x)
	{
		father[x] = Find_Set(father[x]);
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
	}
	else if (rak[x] < rak[y])
	{

		father[x] = y;

	}
	else if (rak[x] == rak[y])  //�����������һ��
	{
		father[x] = y;           //��x���ӵ�y��
		rak[y]++;              //��ʱy�������+1
	}
}
bool same(int x, int y){
	return Find_Set(x) == Find_Set(y);
}
int main()
{
	int a, b;
	while (~scanf("%d%d", &a, &b))
	{
		memset(vis, 0, sizeof(vis));
		memset(rak, 0, sizeof(rak));
		if (a == -1 && b == -1)
			break;
		int FLAG = 0;
		while (1)
		{
			if (a == 0 && b == 0)
				break;

			if (!vis[a]) { vis[a] = 1; Make_Set(a); }
			if (!vis[b]) { vis[b] = 1; Make_Set(b); }
			if (same(a,b)) FLAG = 1;
			if(!FLAG) Union(a, b);
			scanf("%d%d", &a, &b);
		}
		if (FLAG == 1)
			printf("No\n");
		else
		{
			int sum = 0;
			for (int i = 0; i <= 100000; i++)
			{
				if (vis[i] && father[i] == i) sum++;
			}
			if (sum > 1)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
	return 0;
}