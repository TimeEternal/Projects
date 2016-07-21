//#define LOCAL
//#define TESTING
/*转自 http://blog.csdn.net/archya/article/details/38439317 */
#include<stdio.h>
#include<string.h>

char board[10][10], player;
int lm[10][10];

void turn(int r, int c)
{
	if (board[r][c] == 'W') 
		board[r][c] = 'B';
	else board[r][c] = 'W';
}

char getcommand()
{
	int temp;
	temp = getchar();
	while (temp != 'L'&&temp != 'M'&&temp != 'Q')
		temp = getchar();
	return temp;
}

char sw(char side)
{
	if (side == 'W') 
		return 'B';
	else return 'W';
}

int checkp(int r, int c, int k)
{
	if (k == 1)
	{
		if (board[r][c] != sw(player)) 
			return 0;
		else return 1;
	}
	else if (board[r][c] == '-')
	{
		lm[r][c] = 1;
		return 0;
	}
	else if (board[r][c] == player) return -1;
	else return 2;
}

int list()
{
	memset(lm, 0, sizeof(lm));
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if (board[i][j] == player)
			{
				int tempr, tempc;
				//上
				for (int k = 1; k < i; k++)
				{
					tempr = i - k;
					tempc = j;
					if (checkp(tempr, tempc, k)>0) continue;
					else break;
				}
				//下
				for (int k = 1; k + i <= 8; k++)
				{
					tempr = i + k;
					tempc = j;
					if (checkp(tempr, tempc, k)>0) continue;
					else break;
				}
				//左
				for (int k = 1; k <= j; k++)
				{
					tempr = i;
					tempc = j - k;
					if (checkp(tempr, tempc, k)>0) continue;
					else break;
				}
				//右
				for (int k = 1; k + j <= 8; k++)
				{
					tempr = i;
					tempc = j + k;
					if (checkp(tempr, tempc, k)>0) continue;
					else break;
				}
				//左上
				for (int k = 1; k < i && k < j; k++)
				{
					tempr = i - k;
					tempc = j - k;
					if (checkp(tempr, tempc, k)>0) continue;
					else break;
				}
				//左下
				for (int k = 1; k + i <= 8 && k < j; k++)
				{
					tempr = i + k;
					tempc = j - k;
					if (checkp(tempr, tempc, k)>0) continue;
					else break;
				}
				//右上
				for (int k = 1; k < i && k + j <= 8; k++)
				{
					tempr = i - k;
					tempc = j + k;
					if (checkp(tempr, tempc, k)>0) continue;
					else break;
				}
				//右下
				for (int k = 1; k + i <= 8 && k + j <= 8; k++)
				{
					tempr = i + k;
					tempc = j + k;
					if (checkp(tempr, tempc, k)>0) continue;
					else break;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			sum += lm[i][j];
		}
	}
	return sum;
}

void move(int r, int c)
{
	if (!list()) player = sw(player);
	board[r][c] = player;
	int tempr, tempc, result;
	//上
	for (int i = 1; i < r; i++)
	{
		tempr = r - i;
		tempc = c;
		if (checkp(tempr, tempc, i)>0) continue;
		else if (checkp(tempr, tempc, i) < 0)
		{
			for (int j = 1; j < i; j++)
			{
				board[r - j][c] = player;
			}
			break;
		}
		else break;
	}
	//下
	for (int i = 1; i + r <= 8; i++)
	{
		tempr = r + i;
		tempc = c;
		if (checkp(tempr, tempc, i)>0) continue;
		else if (checkp(tempr, tempc, i) < 0)
		{
			for (int j = 1; j < i; j++)
			{
				board[r + j][c] = player;
			}
			break;
		}
		else break;
	}
	//左
	for (int i = 1; i < c; i++)
	{
		tempr = r;
		tempc = c - i;
		if (checkp(tempr, tempc, i)>0) continue;
		else if (checkp(tempr, tempc, i) < 0)
		{
			for (int j = 1; j < i; j++)
			{
				board[r][c - j] = player;
			}
			break;
		}
		else break;
	}
	//右
	for (int i = 1; i + c <= 8; i++)
	{
		tempr = r;
		tempc = c + i;
		if (checkp(tempr, tempc, i)>0) continue;
		else if (checkp(tempr, tempc, i) < 0)
		{
			for (int j = 1; j < i; j++)
			{
				board[r][c + j] = player;
			}
			break;
		}
		else break;
	}
	//左上
	for (int i = 1; i < c && i < r; i++)
	{
		tempr = r - i;
		tempc = c - i;
		if (checkp(tempr, tempc, i)>0) continue;
		else if (checkp(tempr, tempc, i) < 0)
		{
			for (int j = 1; j < i; j++)
			{
				board[r - j][c - j] = player;
			}
			break;
		}
		else break;
	}
	//左下
	for (int i = 1; i < c && i + r <= 8; i++)
	{
		tempr = r + i;
		tempc = c - i;
		if (checkp(tempr, tempc, i)>0) continue;
		else if (checkp(tempr, tempc, i) < 0)
		{
			for (int j = 1; j < i; j++)
			{
				board[r + j][c - j] = player;
			}
			break;
		}
		else break;
	}
	//右上
	for (int i = 1; i < r && i + c <= 8; i++)
	{
		tempr = r - i;
		tempc = c + i;
		if (checkp(tempr, tempc, i)>0) continue;
		else if (checkp(tempr, tempc, i) < 0)
		{
			for (int j = 1; j < i; j++)
			{
				board[r - j][c + j] = player;
			}
			break;
		}
		else break;
	}
	//右下
	for (int i = 1; i + c <= 8 && i + r <= 8; i++)
	{
		tempr = r + i;
		tempc = c + i;
		if (checkp(tempr, tempc, i)>0) continue;
		else if (checkp(tempr, tempc, i) < 0)
		{
			for (int j = 1; j < i; j++)
			{
				board[r + j][c + j] = player;
			}
			break;
		}
		else break;
	}

	player = sw(player);
	int bnum = 0, wnum = 0;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if (board[i][j] == 'W') wnum++;
			else if (board[i][j] == 'B') bnum++;
		}
	}
	printf("Black -%3d White -%3d\n", bnum, wnum);
#ifdef TESTING
	printf("palyer=%c\n", player);
#endif
}

int main()
{
#ifdef LOCAL
	freopen("xt4-3.sd", "r", stdin);
	freopen("xt4-3.out", "w", stdout);
#endif
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		memset(board, 0, sizeof(board));
		for (int i = 1; i <= 8; i++)
		{
			char temp;
			temp = getchar();
			while (temp != '-'&&temp != 'B'&&temp != 'W')temp = getchar();
			board[i][1] = temp;
			for (int j = 2; j <= 8; j++) board[i][j] = getchar();
		}
#ifdef TESTING
		for (int i = 1; i <= 8; i++)
		{
			for (int j = 1; j <= 8; j++) printf("%c", board[i][j]);
			printf("\n");
		}
#endif
		player = getchar();
		while (player != 'W'&&player != 'B')player = getchar();
#ifdef TESTING
		printf("palyer=%c\n", player);
#endif

		for (;;)
		{
			char command;
			command = getcommand();
#ifdef TESTING
			printf("command=%c\n", command);
#endif
			if (command == 'Q')
			{
				for (int i = 1; i <= 8; i++)
				{
					for (int j = 1; j <= 8; j++) printf("%c", board[i][j]);
					printf("\n");
				}
				if (kase>0)printf("\n");
				break;
			}
			else if (command == 'M')
			{
				int r, c, tempn;
				scanf("%d", &tempn);
				r = tempn / 10;
				c = tempn % 10;
#ifdef TESTING
				printf("r=%d c=%d\n", r, c);
#endif
				move(r, c);
			}
			else
			{
				int re = list();
				int num = re;
				if (!re)
				{
					printf("No legal move.\n");
				}
				else
				{
					for (int i = 1; i <= 8; i++)
					{
						for (int j = 1; j <= 8; j++)
						{
							if (lm[i][j])
							{
								printf("(%d,%d)", i, j);
								num--;
								if (num) printf(" ");
								else
								{
									printf("\n");
									break;
								}
							}
						}
						if (!num) break;
					}
				}
			}
		}
	}
}