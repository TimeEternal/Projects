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
先吐槽一下，这数据真是相当感动啊，第一次写错了，结果还能过9个点Σ=。=Σ
咳咳，进入正题吧。因为是位运算，所以各位之间互不影响，直接全部转成二进制来做就好。
接下来枚举m二进制的每一位，从高位到低位，每一位依次和n次操作中参数的对应位进行位
运算得到一个结果，分以下几种情况：
①在枚举前面的位数时，出现了有一位选0时结果大于等于选1的结果，那么以后的每一位就
选0/1皆可了，所以0/1哪个结果大选哪个；
②没有出现①中的情况，且m的这一位为0，那么就只能选0了，直接算结果；
③没有出现①中的情况，且m的这一位为1，这时候选0/1皆可，比较一下得到结果，如果这个
时候选0时结果大于等于选1的结果，那就标记一下，以后的每一位就得都按情况①来考虑了。
每一位的结果对应存储起来，最后转为十进制就是答案了。

*/