#include<stdio.h>
#include<string.h>

char *Haab[] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac",
"ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
char *Tzolkin[] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
"chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };


//在一个字符串数组中搜索指定字符串的下标 
int searchStr(char *list[], int n, char *str)
{
	int i;
	for (i = 0; i<n; i++)
	{
		if (strcmp(list[i], str) == 0)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int day, month, year, date, n, i;
	char s[24];

	scanf("%d", &n);
	printf("%d\n", n);
	for (i = 0; i<n; i++)
	{
		scanf("%d. %s %d", &day, s, &year);

		month = searchStr(Haab, 19, s);
		date = year * 365 + month * 20 + day;

		//进行日历转换
		year = date / 260;
		date = date % 260;
		day = date % 13 + 1;
		month = date % 20;
		
		printf("%d %s %d\n", day, Tzolkin[month], year);
	}
	return 0;
}
