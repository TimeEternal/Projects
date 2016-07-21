#include <cstdio>

using namespace std;

#define MAX 65536



int used[MAX] = { 0 }, len = 0; //used�������� 



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

				state++; //Ϊ'b'���λ��1 

			}

			state <<= 1; //˳������ 

			c = getchar();

		} while (i++<4);

	}

	state >>= 1; //�ƻض��Ƶ�һ�� 



	Flip(state);



	return 0;

}



/****************************

|func:�ı�����״̬

|argv�����ӵ�ǰ״̬������λ��

|return����

****************************/

void ChangeState(int*p, int pos)

{

	int a[5], i;

	//��

	a[0] = (pos<12) ? 4 : -2;

	//�� 

	a[1] = (pos> 3) ? (-4) : -2;

	//��

	a[2] = ((pos + 1) % 4) ? 1 : -2;

	//��

	a[3] = ((pos % 4)) ? (-1) : -2;

	//��

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

|func:������

|argv�����ӳ�ʼ״̬

|return����

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

		//����

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

				//��� 

				tail = (tail + 1) % MAX;

				queue[tail].state = state;

				queue[tail].step = queue[head].step + 1;

			}

		}

	}

	//��������δ�ҵ���

	printf("Impossiblen");

}
