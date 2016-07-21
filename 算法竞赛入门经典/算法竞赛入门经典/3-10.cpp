#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	float h,l;
	bool operator ==(const node &t)const 
	{
		if (h==t.h&&l==t.l) return 1;
		else return 0;
	}
}a[6];
void swap(float &x, float &y)
{
	float t;
	t = x; x = y; y = t;
}
bool cmp (const node &x,const node &y) 
{
	if (y.h == x.h&&y.l > x.l||y.h>x.h) return 1;
	else return 0;
}
int main()
{
	for (int i = 0; i < 6; i++)
	{
		cin >> a[i].h >> a[i].l;
		if (a[i].h > a[i].l) swap(a[i].h, a[i].l);
	}
	sort(a, a + 6,cmp);
	if (a[0]== a[1] && a[2] == a[3] && a[4] == a[5] && a[0].l == a[4].h&&a[2].l == a[4].l)
		cout << "yes";
	else cout << "no";
	return 0;
}