#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int k, n;
int A[60000 + 7], B[60000 + 7];
int minans = 0x3f3f3f3f;
int main()
{
	cin >> k;
	while (k--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> A[i];
		for (int i = 0; i < n; i++) cin >> B[i];
		for (int k = 0; k < n; k++) {
			int t = 0;
			for (int i = 0; i < n; i++)
			{
				t += pow(A[i] - B[(i + k) % n], 2);
				if(t>minans) break;
			}
			minans = min(minans, t);
		}
		cout << minans << endl;
	}
	return 0;
}