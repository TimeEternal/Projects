/*http://blog.csdn.net/xingyeyongheng/article/details/9310555
http://www.cnblogs.com/biyeymyhjob/archive/2012/10/04/2711527.html
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100000
int p[N];
char str[N];
int main() {
	int i = 1000;
	char temp[1000],c;
	while (i--) {
		cin.getline(str, 1000);
		strcpy(temp, str);
		int len = strlen(str);
		for (int i = len; i >= 0; i--)
		{
			str[i + i + 2] = str[i];
			str[i + i + 1] = '#';
		}
		str[0] = '*';
		int id = 0, maxt = 0;
		for (int i = 2; i < 2 * len + 1; i++)
		{
			if (id + p[id] > i)
			{
				p[id] = min(p[id + id - i], p[id] + id - i);
			}
			else
			{
				p[i] = 1;
			}
			while (str[i - p[i]] == str[i + p[i]])
			{
				p[i]++;
			}
			if (i + p[i] > id + p[id])
			{
				id = i;
			}
			if (p[i] >= maxt)
			{
				maxt = p[i];
			}
		}
		cout << maxt - 1 << temp << endl;
	}
	return 0;
}
