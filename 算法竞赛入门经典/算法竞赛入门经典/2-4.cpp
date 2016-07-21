#include<cstdio>
using namespace std;

int main()
{
	int m, n,c=1;
	double s;
	while (scanf("%d%d", &n, &m) && !(m == 0 && n == 0)) {
		s = 0;
		for (int i = n; i <= m; i++)
			s += 1.0 / i/i;
		printf("Case %d:%.5f\n", c++, s);
	}
	return 0;
}
