#include<iostream>
#include<algorithm>
using namespace std;

int a, b;

void slove() {
	bool f = true;
	while (1) {
		if (a > b) swap(a, b);
		if (b%a == 0) break;
		if (b - a > a) break;
		b -= a;
		f = !f;
	}
	if (f) cout << "Stan wins" << endl;
	else cout << "Ollie wins" << endl;
}

int main()
{
	while (cin >> a >> b) {
		if (a == 0 && b == 0) break;
		slove();
	}
	return 0;
}