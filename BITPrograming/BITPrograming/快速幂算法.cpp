#include<iostream>
#include<algorithm>
using namespace std;

int quickpower(int a, int b, int c) {
	int ans = 1;
	a %= c;
	while (b > 0) {
		if (b % 2 == 1)
			ans = (ans*a) % c;
		b /= 2;
		a = (a*a) % c;
	}
	return ans;
}
int main()
{
	cout << quickpower(2, 10, 3) << endl;
	return 0;
}