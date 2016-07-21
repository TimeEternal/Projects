#include <cstdio>

using namespace std;

#define MAX 65536



int used[MAX] = { 0 }, len = 0; //used用于判重 



struct

{

	int state;

	int step;

}queue[MAX];



int main()

{

	void Flip(int state);

	void ChangeState(int*p, int pos);



	char c;

	int state = 0, i;



	while ((c = getchar()) != EOF)

	{

		i = 1;

		do

		{

			if (c == 'b')

			{

				state++; //为'b'则该位置1 

			}

			state <<= 1; //顺次左移 

			c = getchar();

		} while (i++<4);

	}

	state >>= 1; //移回多移的一次 



	Flip(state);



	return 0;

}



/****************************

|func:改变棋子状态

|argv：棋子当前状态和所在位置

|return：无

****************************/

void ChangeState(int*p, int pos)

{

	int a[5], i;

	//上

	a[0] = (pos<12) ? 4 : -2;

	//下 

	a[1] = (pos> 3) ? (-4) : -2;

	//左

	a[2] = ((pos + 1) % 4) ? 1 : -2;

	//右

	a[3] = ((pos % 4)) ? (-1) : -2;

	//中

	a[4] = 0;



	for (i = 0; i<5; i++)

	{

		if (-2 != a[i])

		{

			(*p) ^= (1 << (pos + a[i]));

		}

	}

}



/****************************

|func:翻棋子

|argv：棋子初始状态

|return：无

****************************/

void Flip(int state)

{

	int tail = -1, head = -1, i;



	len++;

	used[state] = 1;

	tail = (tail + 1) % MAX;

	queue[tail].step = 0;

	queue[tail].state = state;



	while (len>0)

	{

		len--;

		//出队

		head = (head + 1) % MAX;



		if (0xFFFF == queue[head].state || 0 == queue[head].state)

		{

			printf("%dn", queue[head].step);

			return ;

		}



		for (i = 0; i<16; i++)

		{

			state = queue[head].state;

			ChangeState(&state, i);

			if (!used[state])

			{

				len++;

				used[state] = 1;

				//入队 

				tail = (tail + 1) % MAX;

				queue[tail].state = state;

				queue[tail].step = queue[head].step + 1;

			}

		}

	}

	//遍历完尚未找到解

	printf("Impossiblen");

}
