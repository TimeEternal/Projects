/*DFS��û�뷨�ͺ��Ѻ��ѣ����뷨�ͺ����׵���

���̹���������ѵ㣬���۹��򲻹��򶼿����ñ��ȥ���

�ѵ����� ���̵�������������n �� ���ڷŵ���������k  �Ĺ�ϵΪk <= n


K<nʱ�������е��Ժ���

K == nʱ���ǱȽϺð��
֪����������


	�����ձ��������� �������ѣ�Ч�ʲ�����Ҳ��΢����ˣ����忴���򣬲���˵�ˣ��������������̫ǿ�����ֺ���˵���

*/
	//Memory Time 
	//184K   32MS 

#include<iostream>
using namespace std;

bool chess[9][9];
bool vist_col[9];  //�б��
int status;  //״̬������
int n, k;

void DFS(int row, int num)  //����������rowΪ��ǰ�����У�numΪ������������
{
	if (num == k)
	{
		status++;
		return;
	}

	if (row>n)    //�������DFS(row+1,num); ���ʹ�ã���������Խ��
		return;

	for (int j = 1; j <= n; j++)
		if (chess[row][j] && !vist_col[j])
		{
			vist_col[j] = true;  //�������ӵ��б��
			DFS(row + 1, num + 1);
			vist_col[j] = false; //���ݺ�˵���ں����ӵ�״̬�Ѽ�¼����ǰ���б�ǻ�ԭ
		}

	DFS(row + 1, num);   //�������ѵ㣬��k<nʱ��row�ڵ���n֮ǰ�Ϳ����Ѿ���ȫ�����ӷź�
						 //�����ڵ�ȫ�����Ӷ��źú��ĳ������״̬�Ѿ���ǰ��ѭ��ʱ��¼��
						 //���Ϊ�˴�������У��ǰλ���Ȳ������ӣ���������һ�з����ӵ����
	return;				//���� ������ô��ΰ� �о����ӶȺø�
}

int main(int i, int j)
{
	while (cin >> n >> k)
	{
		if (n == -1 && k == -1)
			break;

		/*Initial*/

		memset(chess, false, sizeof(chess));
		memset(vist_col, false, sizeof(vist_col));
		status = 0;

		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				char temp;
				cin >> temp;
				if (temp == '#')
					chess[i][j] = true;
			}

		DFS(1, 0);  //ע���ʼ����ֵ��Ū����
		cout << status << endl;
	}
	return 0;
}
