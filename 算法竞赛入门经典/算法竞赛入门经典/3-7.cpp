#include<iostream>
#include<cstring>
using namespace std;
int to[101];
int num2asc[4] = { 65,67,71,84 };
int main()
{
	char c,map[51][1001];
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	for (int i = 0; i < n; i++)
	{
		memset(to, 0, sizeof(to));
		for (int j = 0; j < m; j++)
		{
			to[map[j][i]] += 1;
		}
		int max = 0;
		for (int k = 0; k < 4; k++)
		{
			if (to[num2asc[k]]>max)
			{
				c = num2asc[k];
				max = to[c];
			}
		}
		cout << c<<endl;
	}
	return 0;
}