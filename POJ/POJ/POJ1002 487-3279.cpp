#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define UNCODE(a) (a>='A'?((a>'Q'?(a-'A'-1):(a-'A'))/3+2):a-'0')
//#define DEBUG

int uncode(char* s)
{
	int i;
	int result = 0;
	for (i = 0; i<strlen(s); i++)
	{
		if (s[i] == '-') continue;
		result = result * 10 + UNCODE(s[i]);
	}
	return result;
}

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
#ifdef DEBUG
	freopen("data.dat", "r", stdin);
	//freopen("out.dat","w",stdout);
#endif
	int* store;
	char s[50];
	int time;
	int n = 0;
	int i;
	int start, value;
	int dup = 0;
	scanf("%d", &time);
	store = (int*)malloc(sizeof(int)*(time));
	for (n = 0; n<time; n++)
	{
		scanf("%s", s);
		store[n] = uncode(s);
	}
	qsort(store, time, sizeof(store[0]), cmp);
	value = store[0];
	start = 0;
	for (n = 0; n<time; n++)
	{
		if (store[n] != value) {
			if ((n - start)>1) {
				printf("%03d-%04d %d\n", store[start] / 10000, store[start] % 10000, n - start);
				dup = 1;
			}
			start = n;
			value = store[n];
		}
	}
	if ((n - start)>1) {
		printf("%03d-%04d %d\n", store[start] / 10000, store[start] % 10000, n - start);
		dup = 1;
	}
	if (!dup)
	{
		printf("No duplicates.\n");
	}
	free(store);
	return 1;
}
