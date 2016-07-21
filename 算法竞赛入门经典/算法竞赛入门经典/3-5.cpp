#include<cstdio>
#include<cstring>
using namespace std;
char map[7][7];
typedef struct {
	int mx;
	int my;
}pos;
void swap(pos &x, pos y)
{
	char t;
	t = map[x.mx][x.my];
	map[x.mx][x.my]=map[x.mx + y.mx][x.my + y.my];
	map[x.mx + y.mx][x.my + y.my] = t;
	x.mx += y.mx; x.my += y.my;
}
int main()
{
	char op[20]; bool flag = 1;
	pos move[90],now;
	memset(move, -1, sizeof(move));
	move[65] = { -1,0 }; move[66] = { 1,0 }; move[76] = { 0,-1 }; move[82] = { 0,1 };
	memset(map, 0, sizeof(map));
	scanf("%s\n", op); 
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			scanf("%c", &map[i][j]);
			if (map[i][j] == ' ') now = { i,j };
		}
		getchar();
	}
	int n = 0;
	while (op[n] != 48) {
		if (move[op[n]].mx == -1&& move[op[n]].my == -1 ||map[now.mx+ move[op[n]].mx][now.my + move[op[n]].my]==0) {
			printf("This puzzle has no final configuration.\n");
			flag = 0;
			break;
		}
		else swap(now, move[op[n]]);
		n++;
	}
	if(flag)
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
				printf("%c", map[i][j]);
			printf("\n");
		}
	return 0;
}