/*1):当盘子数为1的时候，只有一种放法就是把所有苹果放到一个盘子里。
(2) : 当苹果数为1或0的时候，也只有一种放法，注意题目中说明，盘子之间并无顺序, 所以不管这个苹果放在哪个盘子里，结果都算一个。
(3) : 当m<n时，因为此时最多只能放到m个盘子中去（一个里放一个），实际上就相当于把m个苹果放到m个盘子里一样，也就是f(m, m);
(4) : 当m >= n时，也分两种情况讨论，一种是至少有一个盘子里不放苹果，这样子就相当于f(m, n - 1), 第二种是，先取出n个苹果一个盘子里放一个，再将剩下的m - n个苹果放到n个盘子里去，即f(m - n, n);
综上所述:
得到递归表达式：
f(m, n) = 1 当 m = 1,m = 0或n = 1;
f(m, n) = f(m, m) 当m<n;
f(m, n) = f(m - n, n) + f(m, n - 1);这个推断有点吊
***********************************************************************************************
#include <iostream>
using namespace std;
其实隔板法就好了啊 不对不对 3 1 3倒是可以避免 但1 2 3和3 2 1可是不一样的
n个球m个班 每班至少一个c（n-1,m-1）同样如果每个班可以没有 c(n+m-1,m-1)
						  n-1								n+m-1
*/
#include<iostream>
using namespace std;
int f(int m, int n)
{
	if (m == 1 || n == 1 || m == 0)
		return 1;
	else if (m < n)
		return f(m, m);
	else
		return f(m - n, n) + f(m, n - 1);
	/*
	这样也是可以的
	if (m == 1 || n == 1 || m == 0)
	return 1;
	else if (m < 0)
	return 0;
	else
	return f(m - n, n) + f(m, n - 1);
							只不过这里有可能就搜的很深了
	*/
}
int main()
{
	int t, m, n;
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		cout << f(m, n) << endl;
	}
	return 0;
}