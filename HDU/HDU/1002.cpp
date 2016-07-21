#include<iostream>
#include<cstring>
using namespace std;
void changeform(char* x, int *a)
{
	int i = strlen(x);
	while (i>0)
	{
		a[strlen(x) - i - 1] =x[--i]-48;
	}
}
int main()
{
	int n;
	char x[1000], y[1000];
	int a[1000], b[1000], c[1001];
	int len,i,m=1;
	cin >> n;
	while (m<=n) {
		i = 0;
		cin >> x >> y;
		strlen(x) > strlen(y) ? len = strlen(x) : len = strlen(y);
		memset(a, 0, sizeof(a));  
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		changeform(x, a);
		changeform(y, b);
		while (i < len) {
			c[i] += a[i] + b[i];
			if (c[i] >= 10) {
				c[i] -= 10;
				c[i + 1] += 1;
			}
			i++;
		}
		cout << "Case " << m << ":" << endl;
		cout << x << " + " << y << " = ";
		while (c[i] == 0) i--;
		if(i!=-1)
			for (int j = i; j >= 0; j--)
				cout << c[j];
		else cout << 0;
		cout << endl;
		if(m!=n) cout << endl; //坑爹 除了最后一行一个换行 其余两个
		m++;
	}
	return 0;
}