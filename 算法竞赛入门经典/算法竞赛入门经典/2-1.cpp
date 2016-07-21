#include<iostream>
using namespace std;

int main()
{
	int s=0,t,x;
	for (int i = 100; i < 1000; i++)
	{
		t = i; s = 0;
		while (t != 0)
		{
			x = t % 10;
			s += x*x*x;
			t /= 10;
		}
		if (s == i) cout << s << " ";
	}
	return 0;
}