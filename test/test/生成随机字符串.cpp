#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s = "aabbccddeee";
	for (int i = 0; i < 100; i++)
	{
		next_permutation(s.begin(),s.end());
		cout << s<<endl;
	}
	return 0;
}