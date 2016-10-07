#include<iostream>
using namespace std;

int main()
{
	int x;
	while (cin >> x) {
		if (x == 0) break;
		if (x <= 2) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}
	return 0;
}