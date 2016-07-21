
/*
�򵥵�01������ֱ�����е��鷳������ת��Ϊ�ڴ��������ʵ�����¿��Ի�õ����Ǯ��
Ҳ������õ�ĳ��Ǯ��ʱ����������ʣ�״̬ת�Ʒ����� 
dp[j]=max(dp[j],dp[j-s[i].m]*s[i].p)
��ֵdp[0]=1 ,��Ϊ��͵Ǯ��Ȼ�ǲ���ץ�ģ������dp[j]���ǻ��jǮ�����Դﵽ��
��������ʣ��������ٱ���ͬʱ���Ѳſ��ԣ���˸���Ҫ�ˣ������и����������Ż���
������sum[i] ��¼ǰi�����У�����i����Ǯ���ͣ������ڶ���ѭ���Ϳ�����
for(j = sum[i] ; j>=s[i].m;j--) , ��Ϊ��j >sum[i] ʱ j-s[i].m>sum[i-1] 
(sum[i]-sum[i-1]=s[i].m)��ʱ��dp[j-s[i].m]��Ȼ��û�����������Ϊ��ʱ���
ֻ�㵽��sum[i-1] !
�ٶȴ��� ��Ħ֮��*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#define M 105
using namespace std;
struct ss {
	double p;
	int m;
} s[M];
int main() {
	int t, i, j, n, sum[M];
	double dp[M * M], P;
	scanf("%d", &t);
	while (t-- && scanf("%lf %d", &P, &n)) {
		P = 1 - P;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		sum[0] = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d %lf", &s[i].m, &s[i].p);
			s[i].p = 1 - s[i].p;
			sum[i] = sum[i - 1] + s[i].m;
		}
		for (i = 1; i <= n; i++)
			for (j = sum[n]; j >= s[i].m; j--)
				dp[j] = max(dp[j], dp[j - s[i].m] * s[i].p); //ѹ����dp����������
		for (j = sum[n]; j >= 1; j--)//��͵i    ͵i ȡ����
			if (dp[j] > P)break;
		printf("%d\n", j);
	}
	return 0;
}
