/*http://blog.csdn.net/say_c_box/article/details/52003545 */
/*http://blog.csdn.net/nare123/article/details/51966794 */  //������뿴������
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
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int mymin(int a, int b, int c) {
	return min(a, min(b, c));
}
int main()
{
	int s[107], n;
	int dp[107][3];
	memset(dp, INF, sizeof(dp));
	dp[0][1] = dp[0][0] = dp[0][2] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) {
		dp[i][0] = mymin(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + 1;
		if (s[i] == 1 || s[i] == 3) {
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		}
		if (s[i] == 2 || s[i] == 3) {
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		}
		// ԭ������s[i]==0  dp[i][1]=dp[i][2]=INF �����޷�������� ���״̬�޷�ת�Ƶ��¸�״̬ ���ȫ��ʼ��ΪINF�� ʡ���������
	}
	int ans = mymin(dp[n][0], dp[n][1], dp[n][2]);
	cout << ans << endl;
	return 0;
}