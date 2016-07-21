
/*
简单的01背包，直接做有点麻烦，可以转化为在大于逃脱率的情况下可以获得的最大钱数
也就是求得到某个钱数时的最大逃脱率，状态转移方程是 
dp[j]=max(dp[j],dp[j-s[i].m]*s[i].p)
初值dp[0]=1 ,因为不偷钱当然是不被抓的，这里的dp[j]就是获得j钱数可以达到的
最大逃脱率！几次抢劫必须同时逃脱才可以，因此概率要乘！这里有个常数级的优化，
可以用sum[i] 记录前i的银行（包括i）的钱数和，这样第二个循环就可以是
for(j = sum[i] ; j>=s[i].m;j--) , 因为当j >sum[i] 时 j-s[i].m>sum[i-1] 
(sum[i]-sum[i-1]=s[i].m)这时的dp[j-s[i].m]显然还没有算出来，因为此时最多
只算到了sum[i-1] !
百度代码 观摩之用*/
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
				dp[j] = max(dp[j], dp[j - s[i].m] * s[i].p); //压缩的dp并看不懂啊
		for (j = sum[n]; j >= 1; j--)//不偷i    偷i 取最优
			if (dp[j] > P)break;
		printf("%d\n", j);
	}
	return 0;
}
