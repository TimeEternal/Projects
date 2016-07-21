#include<cstdio>
using namespace std;
int convert(const char *str)
{
	int sum = 0;
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			sum = sum * 10 + str[i] - '0';
		else
			return -1;

	}
	if (sum >= 1 && sum <= 1000)
		return sum;
	else
		return -1;
}
int main()
{
	char A[10000], B[10000];
	int a, b;
	scanf("%s ", &A);
	gets_s(B);//¶ÁÈëÒ»ĞĞ
	a = convert(A);
	b = convert(B);
	if (a == -1)
		printf("? + ");
	else
		printf("%d + ", a);
	if (b == -1)
		printf("? = ");
	else
		printf("%d = ", b);
	if (a == -1 || b == -1)
		printf("?\n");
	else
		printf("%d\n", a + b);
	return 0;

}

