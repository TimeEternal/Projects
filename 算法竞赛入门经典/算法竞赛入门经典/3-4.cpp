#include<iostream>
using namespace std;

int main()
{
	int i, j,len,flag=0;
	char s[81];
	cin >> s;
	len = strlen(s);
	for (i = 1; i <= len; i++) {
		if (len % i == 0) {
			flag = 1;					//���%i��=0 flagӦ��Ϊ�� ����ֻ����=0�����flag ����Ϊ1
			for (j = i ; j < len;j++) {
				if (s[j - i] != s[j]) {
					flag = 0; break;
				}
			}
		}
		if (flag) {
			cout << i << endl; break;
		}
	}
	return 0;
}