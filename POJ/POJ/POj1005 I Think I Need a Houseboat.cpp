#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const float pi = acos(-1);
int main()
{
	int t, i=1;
	scanf("%d", &t);
	while (i<=t) {
		float x, y, rr, area;
		scanf("%f %f", &x, &y);
		rr = x*x + y*y;
		area = pi*rr / 2;
		printf("Property %d: This property will begin eroding in year %d.\n", i, int (area / 50) + 1);
		i++;
	}
	printf("END OF OUTPUT.\n");
	return 0;
}