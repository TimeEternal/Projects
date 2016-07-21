#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 100;
int main()
{
	char s[MAXN], t[MAXN];
	int i = 0, j = 0;
	cin >> t>> s;
	int slen = strlen(s), tlen = strlen(t);
	while (i < slen&&j < tlen) {
		if (s[i] == t[j]) { i++; j++; }
		else j++;
	}
	if (i == slen)cout << "yes";
	else cout << "no";
	return 0;
}