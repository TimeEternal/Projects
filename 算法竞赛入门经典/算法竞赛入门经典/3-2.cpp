#include<iostream>
#include<iomanip>
using namespace std;

int cal(string s, int x, int j) {
	int ans = 0;
	for (int i = x; i < j; i++) {
		ans = 10 * ans + s[i] - '0';
	}
	return ans;
}
int main()
{
	char s[20];
	float c[256], sum = 0, temp = 0;
	c[67] = 12.01; c[72] = 1.008; c[79] = 16.00; c[78] = 14.01;//¿ÉÒÔÓÃmap
	int n,st,en;
	cin>>n;
	while (n--)
	{
		cin >> s;
		sum = en = 0; st = 0x3f3f3f3f;
		for (int i = 0; i <= strlen(s); i++) {
			if (isalpha(s[i]) || s[i] == '\0') {
				en = i;
				sum += temp;
				sum += temp*cal(s, st, en) - 1;
				temp = c[s[i]];
				st = 0;
			}
			else { if (!st) st = i; }
		}
		cout << setprecision(3) << setiosflags(ios::fixed) << sum << endl;
	}
	return 0;
}