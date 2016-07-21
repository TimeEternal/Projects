#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef unsigned char SString[100 + 1];
int slide[101];
bool initSString(SString &S,const char* temp)
{
	memset(S, 0, sizeof(S));
	S[0] = strlen(temp);
	for (int i = 1; i <= S[0]; i++) S[i] = temp[i-1];
	return 1;
}
int  Index_kmp(SString S, SString T, int pos)
{
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0])
	{
		if (j == 0 || S[i] == T[j]) { ++i; ++j; }
		else j = slide[j];
	}
	if (j > T[0]) return i - T[0];
	else return 0;
}
void get_slide(SString T)
{
	int i = 1, j = 0; slide[1] = 0;
	while(i<T[0])
	 if (j == 0 || T[i] == T[j]) { ++i; ++j; slide[i] = j; }
	 else j = slide[j];
}

int main()
{
	int p;
	SString S, T;
	initSString(S, "abaabcac");
	initSString(T, "abc");
	get_slide(T);
	p = Index_kmp(S, T, 1);
	cout << p<<endl;
	system("pause");
	return 1;
}