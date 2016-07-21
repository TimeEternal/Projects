#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int **s;
	s = (int**)malloc(2 * sizeof(int *));
	for (int i = 0; i < 2; i++)
		s[i] = (int *)malloc(3 * sizeof(int));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cin >> s[i][j];
	cout << *(*(s + 1) + 2);
	return 0;
}