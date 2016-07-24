/*http://blog.csdn.net/say_c_box/article/details/52003545*/
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <set>


using namespace std;

#define MAXN 110
#define LEN 1000000
#define INF 1e9+7
#define MODE 1000000
typedef long long ll;


int n;
int a[MAXN];
int f[MAXN][3];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 0; i<4; i++)
		f[0][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
		if (a[i] == 1 || a[i] == 3)
			f[i][1] = min(f[i - 1][0], f[i - 1][2]);
		else
			f[i][1] = INF;
		if (a[i] == 2 || a[i] == 3)
			f[i][2] = min(f[i - 1][0], f[i - 1][1]);
		else
			f[i][2] = INF;
		if (a[i] == 0)
		{
			f[i][1] = INF;
			f[i][2] = INF;
		}
	}
	printf("%d\n", min(f[n][0], min(f[n][1], f[n][2])));
}
/*http://blog.csdn.net/nare123/article/details/51966794*/  //������뿴������
/*
�۲��������ֵĶ�����Ϊ00,01,10,11.���е�1ǡ��Ϊ��Ӧ�������ܸɵ����顣
����k[i]Ϊ��k��Ӧ�øɵ�����
������a[]��������s[i](L<=i<=R)��������3��
1.����L=1����ôs֮ǰû�����֣�s��״̬����R+1λ�õ����־����ģ������������������ʲôs�����ж������ܴ�����Ϣ������������k[R+1]=k[R]&a[R+1];
2.����L!=1,��ôR+1��״̬����L-1��״̬�����ģ���s���Բ����ܴ�����Ϣ������������
k[R+1]=k[L-1]^k[L]^...^k[R](^Ϊ�������)
�ٿ���a[]��û��3�������ô,k[i+1]=a[i+1]^k[i]; ��k[i+1]==3˵������һ������10,01��ôk[i+1]=k[i]&a[i+1];
��k[i]==0 ��˵����i����Ϣ��
*/