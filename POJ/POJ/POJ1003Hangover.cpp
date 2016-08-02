#include<cstdio>
using namespace std;

int main()
{
	float x;
	while (scanf("%f", &x) && x != 0) {
		float sum = 0; int i = 1;
		while (sum < x) {
			i++;
			sum += 1.0 / i;
		}
		printf("%d card(s)\n", i - 1);
	}
	return 0;
}