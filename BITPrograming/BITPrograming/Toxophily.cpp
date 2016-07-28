/*首先这题是一道物理题，需要我们根据题意抽象一个函数出来。对物体的运动作分解后，可以得到：

f(t) = x*tan(t) - g*x*x / (v*cos(t)) ^ 2 / 2, 其中t表示v与x轴正向的夹角（弧度），f(t)表示物体的运动轨迹与直线x0 = x的交点纵坐标。

分析后可以得到该函数在区间（0, π / 2)上先增后减，所以我们可以在该区间上三分，求出使函数取得极大值的角度t0。若f(t0)<y，则无解；否则对区间（0，t0）二分，找到使得f(t) = y的t值，即为所求。*/

#include<iostream>  
#include<cstdio>  
#include<cmath>  

using namespace std;

const double eps = 1.0e-9;
const double PI = acos(-1.0);
const double g = 9.8;
double x, y, v;

double f(double t)
{
	return x*tan(t) - g*x*x / 2 / (v*v*cos(t)*cos(t));
}

double two_devide(double left, double right)
{
	double m;
	while (right - left >= eps)
	{
		m = (right + left) / 2;
		if (f(m) <= y)
			left = m;
		else
			right = m;
	}
	return m;
}

double three_devide(double left, double right)
{
	double m1, m2;
	while (right - left >= eps)
	{
		m1 = left + (right - left) / 3;
		m2 = right - (right - left) / 3;
		if (f(m1) <= f(m2))
			left = m1;
		else
			right = m2;
	}
	return (m1 + m2) / 2;
}

int main()
{
	int t;
	double maxt;
	cin >> t;
	while (t--)
	{
		cin >> x >> y >> v;
		maxt = three_devide(0, PI / 2);
		if (f(maxt)<y)
			printf("-1\n");
		else
			printf("%.6lf\n", two_devide(0, maxt));
	}
	return 0;
}
/*
三变量 消元  消除t 我都不会 真tm傻 x表示t带入y
由x=v*cos(θ)*t,y=v*sin(θ）*t-g*t*t/2,然后通过数学变形（sin（θ）^2+cos(θ)^2=1)得到方程：
g*x*x*tan(θ）^2-2*v*v*x*tan(θ)+2*v*v*y+g*x*x=0，
*/