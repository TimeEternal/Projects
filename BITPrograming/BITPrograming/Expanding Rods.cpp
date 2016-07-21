#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
double c, s,eps = 1e-6,l,n;//l nÒ²ÊÇdoubleµÄ QAQ
bool fun(double h) {
	double r = (4 * h*h + l*l) / 8 / h;
	double ts = 2 * r*asin(l / 2 / r);
	if (ts < s) return true;
	else return false;
}
void bsearch() {
	double left = 0, right = l / 2.0;
	while (right - left > eps) {
		double mid = left + (right - left) / 2;
		if (fun(mid)) left = mid; 
		else right = mid;
	}
	cout << setprecision(3)<<setiosflags(ios::fixed)<<left << endl;
}
int main()
{
	while (cin >> l >> n >> c&&l != -1 && n != -1 && c != -1) {
		s = (1 + n*c)*l;
		bsearch();
	}
	return 0;
}