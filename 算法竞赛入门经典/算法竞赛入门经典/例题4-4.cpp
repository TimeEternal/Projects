#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 8;
char code[maxn][2 << maxn];
bool readcodes()
{
	memset(code, 0, sizeof(code));
	for(int len=1;len<=maxn;len++)
		for (int i = 0; i < (1 << len) - 1; i++)
		{
			char c = getchar();
			if (c == EOF) return 0;
			if (c == '\n')return 1;
			code[len][i] = c;
		}
}
int readint(int len) {
	int v = 0;
	while (len--)
		v = v * 2 + getchar() - '0';
	return v;
}
int main()
{
	while (readcodes()) {
		while (1) {
			int len = readint(3);//这两个while break用的真是绝妙啊
			if (len == 0) break;
			while (1) {
				int v = readint(len);
				if (v == (1 << len) - 1) break;
				putchar(code[len][v]);
			}
		}
		cout << endl;
	}
	return 0;
}