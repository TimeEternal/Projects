#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 100;
int d[MAXN][MAXN];
int len;
char s[MAXN];

bool match(char a, char b) {
	if (a == '['&&b == ']' || a == '('&&b == ')')
		return 1;
	else return 0;
}
void dp()
{
	for (int i = 0; i < len; i++) {
		d[i + 1][i] = 0;
		d[i][i] = 1;
	}
	for (int i = len - 2; i >= 0; i--)
		for (int j = i + 1; j < len; j++) {
			d[i][j] = len;
			if (match(s[i], s[j])) d[i][j] = min(d[i][j], d[i + 1][j - 1]);
			for (int k = i; k < j; k++)
				d[i][j] = min(d[i][j], d[i][k] + d[k + 1][j]);
		}
}

void print(int i, int j)
{
	if (i > j) return;
	if (i == j) {
		if (s[i] == '(' || s[i] == ')') cout << "()";
		else cout << "[]";
		return;
	}
	int ans = d[i][j];
	if (match(s[i], s[j]) && ans == d[i + 1][j - 1]) {
		cout << s[i];
		print(i + 1, j - 1);
		cout << s[j];
		return;
	}
	for (int k = i; k<j; k++)
		if (ans == (d[i][k] + d[k + 1][j])) {
			print(i, k);
			print(k + 1, j);
			return;
		}
}

int main()
{
	cin.getline(s, MAXN);
	len = strlen(s);
	if (len == 0) cout << "0" << endl;
	else {
		dp();
		print(0, len - 1);
		cout << endl << len + d[0][len - 1] << endl;
	}
	return 0;
}