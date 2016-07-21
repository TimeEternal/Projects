#include<cstdio>
using namespace std;

int main()
{
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)&&!(a==0&&b==0&&c==0)){
		printf("%d.",a/b);
		int t=a%b;
		while(c--!=1){
			printf("%d",10*t/b);
			t=10*t%b;
		}
		if(10*t%b*10/b>=5)
		printf("%d\n",10*t/b+1);
		else printf("%d\n",10*t/b);
	}
	return 0;
} 
