#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	int n,max=0;
	map<string, int> ballon;
	string color,ans;
	while (cin >> n&&n != 0)
	{
		ballon.clear();
		max = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> color;
			ballon[color] += 1;
			if (ballon[color] > max)
			{
				ans = color;
				max = ballon[color];
			}
		}
		cout <<ans << endl;
	}
}