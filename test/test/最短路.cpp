#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;
typedef struct
{
	int x, y;
}point;
int map[100][100];
point prior[100][100];
int m, n;
void shortdis(int d,int x,int y)
{
	if (!map[x][y]||d < map[x][y]) map[x][y] = d;
	if (map[x][y + 1] == 0 || map[x][y] + 1 < map[x][y + 1]) 
	{
		shortdis(d + 1, x, y + 1); prior[x][y + 1] = { x,y };
	}
	if (map[x + 1][y] == 0 || map[x][y] + 1 < map[x + 1][y]) 
	{ 
		shortdis(d + 1, x + 1, y); prior[x+1][y] = { x,y };
	}
	if (map[x - 1][y] == 0 || map[x][y] + 1 < map[x - 1][y]) 
	{
		shortdis(d + 1, x - 1, y); prior[x-1][y] = { x,y };
	}
	if (map[x][y - 1] == 0 || map[x][y] + 1 < map[x][y - 1]) 
	{ 
		shortdis(d + 1, x, y - 1); prior[x][y - 1] = { x,y };
	}
}
void showdis(int x,int y)
{
	stack<point> s; point t; 
	int i = 1,xt,yt;
	do
	{
		s.push({ x,y });
		xt = x; yt = y;
		x = prior[xt][yt].x;
		y = prior[xt][yt].y;
	} while (x != 0);
	while (!s.empty())
	{
		t = s.top();
		s.pop();
		cout << i++ << ": " <<"("<< t.x << "," << t.y <<")"<< endl;
	}
}
int main()
{
	char c;
	cin >> m >> n;
	memset(prior, 0, sizeof(prior));
	for (int i = 0; i <= n + 1; i++) { map[0][i] = 1; map[m + 1][i] = 1; }
	for (int i = 0; i <= m + 1; i++) { map[i][0] = 1; map[i][n+1] = 1; }
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> c;
			map[i][j]=c-48;
		}
	shortdis(1, 1, 1);
	showdis(m,n);
	system("pause");
	return 0;
}