#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	int n=1;
	float s, a, b, c;
	while (cin >> a >> b >> c&&!(a == 0 && b == 0 && c == 0)) {
		s = a / b ;
		cout << "Case "<<n++<<":" << fixed << setprecision(c)<<s<<endl;
		//�Դ��ĺ��������ôǿ��
	}
	return 0;
}