#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
const double pi = acos(-1.0);
double r, R, H, v;

bool fun(double h) {
	double rr,vv;
	rr = h*(R - r) / H + r;
	vv = pi / 3 * h*(r*r + rr*r + rr*rr);//圆台面积公式设上底的半径为r ,下底的半径为R ,高为h 则V＝(1 / 3)*π*h*(R ^ 2 + Rr + r ^ 2)
	if (vv < v) return 1;
	else return 0;
}

int main()
{
	int n; cin >> n;
	while (n--) {
		cin >> r >> R >> H >> v;
		double left = 0, right = H;
		while (right - left > 1e-7) {
			double mid = left + (right - left) / 2;
			if (fun(mid)) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		cout << setprecision(6) << setiosflags(ios::fixed) << left << endl;
	}
	return 0;
}