#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int t = 0, sum = 0;
	char s[81];
	cin >> s;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == 'O') {
			t++;
			sum += t;
		}
		else { t = 0; }
	}
	cout << sum<<endl;
	return 0;
}