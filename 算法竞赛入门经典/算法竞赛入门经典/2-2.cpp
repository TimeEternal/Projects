#include<iostream>
using namespace std;

int main()
{
	int a, b, c,n=1,i;
	while (1) {
		cin >> a >> b >> c;
		for (i = 10; i < 101; i++)
		{
			if (i % 3 == a&&i % 5 == b&&i % 7 == c) {
				cout << "Case " << n++ << ":" << i << endl;
				break;
			}
		}
		if(i==101) cout << "no answer" << endl;
	}
	return 0;
}