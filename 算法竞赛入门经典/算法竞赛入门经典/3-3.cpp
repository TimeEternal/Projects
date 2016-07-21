#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int sum[10];
	char s[10001];
	memset(sum, 0, sizeof(sum));
	cin >> s;
	for (int i = 0; i < strlen(s); i++) {
		sum[s[i] - 48] += 1;
	}
	for (int i = 0; i < 10; i++)
		cout << sum[i] << " ";
	cout << endl;
	return 0;
}