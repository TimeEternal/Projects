#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char s[20];
	float c[256],sum=0;
	c[67] = 12.01; c[72] = 1.008; c[79] = 16.00; c[78] = 14.01;//¿ÉÒÔÓÃmap
	cin >> s;
	for (int i = 0; i < strlen(s); i++) {
		if (isalpha(s[i])) sum += c[s[i]];//65 -90 A-Z
		else sum += c[s[i - 1]] * (s[i] - 49);//48 -57  0-9
	}
	cout << sum << endl;
	return 0;
}