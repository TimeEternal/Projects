#include <stdio.h> 
int main()
{
	int p, e, i, d;
	int cas = 0;
	int date;
	while (scanf("%d%d%d%d", &p, &e, &i, &d))
	{
		if (p + e + d + i == -4)
			break;
		date = d;
		d++;
		while ((d - p) % 23)//找到比date大的p+倍数周期 如果d=p+23或许是小于起始日期的 这之中有可能有解
		{					//因为他们三个起初不是同时的 否则周期肯定是21252 我傻了
			d++;
		}

		while ((d - e) % 28 != 0 || (d - i) % 33 != 0)
		{
			d += 23;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n", ++cas, d - date);
	}
	return 0;
}
//Memory Time 
//256K   94MS 

/* http://blog.csdn.net/lyy289065406/article/details/6648551
#include<iostream>
using namespace std;

int main(void)
{
	int p, e, i, d;
	int time = 1;
	while (cin >> p >> e >> i >> d)
	{
		if (p == -1 && e == -1 && i == -1 && d == -1)
			break;

		int lcm = 21252;  // lcm(23,28,33)
		int n = (5544 * p + 14421 * e + 1288 * i - d + 21252) % 21252;
		if (n == 0)
			n = 21252;
		cout << "Case " << time++ << ": the next triple peak occurs in " << n << " days." << endl;
	}
	return 0;
}*/
