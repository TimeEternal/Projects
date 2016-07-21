#include<iostream>

using namespace std;

int a[100];

int saxi(int low, int high)
{
	int i = low;
	int j = high;
	a[0] = a[low];
	while (i<j)
	{
		while (a[j] > a[0]&&i<j) j--;
		a[i] = a[j];
		while (a[i] < a[0]&&i<j) i++;
		a[j] = a[i];
	}
	a[i] = a[0];
	return i;
}
void quick_sort(int low, int high)
{
	int axi;
	if (low < high)
	{
		axi = saxi(low, high);
		quick_sort(1, axi - 1);
		quick_sort(axi + 1, high);
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin>>a[i];
	quick_sort(1, n);
	for (int i = 1; i <= n; i++)
		cout<< a[i]<<' ';
}