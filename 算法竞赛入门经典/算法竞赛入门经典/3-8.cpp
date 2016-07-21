#include<iostream>
using namespace std;

int main()
{
	int a, b, t,n=0;
	int s[3000] = { 0 };
	cin >> a >> b;
	cout << a / b << ".";
	t = a%b;
	while (s[t] != 1) {
		s[t] = 1;
		n++;
		cout << 10 * t / b;
		t = 10 * t%b;
	}
	cout << endl<<n<<endl;
	return 0;
}