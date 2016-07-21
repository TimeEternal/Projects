#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int x) {
	if (x == 1) return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0) {
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	while (n--) {
		int xx;
		cin >> xx;
		if (isprime(xx)) { cout << "Yes" << endl; }
		else { cout << "No" << endl; }
	}
	return 0;
}
