#include <cstdio>
using namespace std;

void result(int num, int &result_add, int &result_mul)
{
	int i, j, k;

	i = num / 100;        //��λ
	j = num / 10 % 10;    //ʮλ
	k = num % 10;         //��λ

	result_add += i + j + k;    //�ֽ������λ�����
	result_mul *= i * j * k;    //���
}


int main()
{
	int i, j, k;
	int result_add, result_mul;

	for (i = 123; i <= 329; i++)
	{
		j = i * 2;
		k = i * 3;

		result_add = 0;
		result_mul = 1;



		result(i, result_add, result_mul);
		result(j, result_add, result_mul);
		result(k, result_add, result_mul);

		if (result_add == 45 && result_mul == 362880)
			printf("%d %d %d\n", i, j, k);
	}
	return 0;
}
