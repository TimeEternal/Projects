#include<iostream>
using namespace std;
#define MAXSIZE 20

int mov=0, camp=0;
typedef int KeyType;
typedef struct {
	KeyType key;
}RedType;
typedef struct {
	RedType r[MAXSIZE + 1];
	int length;
}SqList;
bool LE(int a, int b) {
	camp++;
	if (a >= b) return 1;
	else return 0;	
}
void InitList(SqList &L){
	L.length = 5;
	for (int i = 1; i <= 5; i++)
		cin >> L.r[i].key;
}
void InsertSort(SqList L) {						//直接插入排序
	int i, j;
	mov = 0; camp = 0;
	for (i = 2; i <= L.length; ++i)
	{
		camp++;
		if (L.r[i].key < L.r[i - 1].key) {
			L.r[0] = L.r[i];
			L.r[i] = L.r[i - 1];
			mov += 2;
			for (j = i - 2; L.r[0].key < L.r[j].key; j--)
			{
				camp++;
				L.r[j + 1] = L.r[j];
				mov++;
			}
			camp++;
			L.r[j + 1] = L.r[0];
			mov++;
		}
	}
		cout << camp << " " << mov << " ";
}
void BubbleSort(SqList L) {				//冒泡排序
	int i, j,t, flag;
	mov = 0; camp = 0;
	for (i = 1; i <= L.length; i++) {
		flag = 1;
		for (j = 1; j <= L.length - i; j++,camp++) 
			if (L.r[j + 1].key < L.r[j].key) {
				t = L.r[j + 1].key;
				L.r[j + 1].key = L.r[j].key;
				L.r[j].key = t;
				mov += 3;
				flag = 0;
			}
		if (flag) break;
	}
	cout << camp << " " << mov << " ";
	camp = 0; mov = 0;
}
void QSort(SqList L, int low, int high) {			//快速排序
	int s = low, e = high;
	L.r[0] = L.r[low];mov++;
	while (low<high)
	{
		while (low < high&&LE(L.r[high].key,L.r[0].key)) --high; 
		L.r[low] = L.r[high];mov++;
		while (low < high&&LE(L.r[0].key, L.r[low].key)) ++low;
		L.r[high] = L.r[low]; mov++;
	}
	L.r[low] = L.r[0]; mov++;
	if (s < low - 1)   QSort(L, s, low-1);
	if (e > low + 1)   QSort(L, low + 1, e);
}
void SelectSort(SqList L) {			//选择排序
	int t,m,locm;
	mov = 0; camp = 0;
	for (int i = 1; i < L.length; i++) {
		m = L.r[i].key; locm = i;
		for (int j = i + 1; j <= L.length; j++, camp++)
			if (L.r[j].key < m) {
				m = L.r[j].key;
				locm = j;
			}
		if (i != locm) {
			t = L.r[locm].key;
			L.r[locm].key = L.r[i].key;
			L.r[i].key = t;
			mov += 3;
		}
	}
	cout << camp << " " << mov << " ";
	mov = 0; camp = 0;
}

void mergearray(RedType a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		mov++; camp++;
		if (a[i].key <= a[j].key)
			temp[k++] = a[i++].key;
		else
			temp[k++] = a[j++].key;
	}

	while (i <= m)
	{
		temp[k++] = a[i++].key;
		mov++;
	}

	while (j <= n)
	{
		mov++;
		temp[k++] = a[j++].key;
	}

	for (i = 0; i < k; i++)
		a[first + i].key = temp[i];
}
void mergesort(RedType a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序
		mergesort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}

bool MergeSort(RedType a[], int n)
{
	int *p = new int[n];
	if (p == NULL)
		return false;
	mergesort(a, 1, n, p);
	delete[] p;
	cout << camp << " " << mov << endl;
	return true;
}
int main()
{
	SqList l; int n;
	cin>>n;
	for (int i = 0; i < n; i++) {
		InitList(l);
		InsertSort(l);
		BubbleSort(l);
		QSort(l, 1, 5);	cout << camp << " " << mov << " ";
		SelectSort(l);
		MergeSort(l.r, 5);
	}
	system("pause");
	return 0;
}