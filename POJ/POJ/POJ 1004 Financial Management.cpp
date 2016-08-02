#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	float sum = 0, x;
	for (int i = 0; i < 12; i++) {
		scanf("%f", &x);
		sum += x;
	}
	printf("$%.2f\n", sum / 12.0);
	return 0;
}