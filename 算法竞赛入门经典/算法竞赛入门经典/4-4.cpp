/*骰子涂色 六面 输入两个骰子 判断是否等价*/
#include<iostream>
#include<cstring>
using namespace std;
int toleft[7] = {0,1,4,2,5,3,6};
int toup[7] = { 0,2,6,3,4,1,5 };

void left(char (&t)[10], char (&s)[10])
{
	for (int i = 1; i < 7; i++)
		t[i] = s[toleft[i]];
	memcpy(s, t, sizeof(t));
}
void up(char(&t)[10],  char (&s)[10])
{
	for (int i = 1; i < 7; i++)
		t[i] = s[toup[i]];
	memcpy(s, t, sizeof(t));
}
int main()
{
	char s[10] = { 'a' }, e[10]={ 'a' }, t[10]= { 'a' };
	bool flag = 0;
	for (int i = 1; i < 7; i++) cin >> s[i];
	for (int i = 1; i < 7; i++) cin >> e[i];
	for (int i = 0; i < 6&&!flag; i++) {
		switch (i)
		{
		default:break;
		case 1:up(t, s); break;
		case 2:up(t, s); break;
		case 3:up(t, s); break;
		case 4:left(t, s); up(t, s); break;
		case 5:up(t, s); up(t, s); break;
		}
		for (int j = 0; j < 4; j++) 
		{
			left(t, s);
			if (0 == strcmp(t, e))  //memcmp(t,e,sizeof(t));也是一样的效果 按字节比较
				flag = 1;
		}
	}
	if (flag)cout << "yes";
	else cout << "no";
	return 0;
}