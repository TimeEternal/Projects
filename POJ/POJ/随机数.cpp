#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i<10; i++)
		printf("%d\n", int(rand() / (float)(RAND_MAX) * 3054 + 1000)); //这是关键的一步
}