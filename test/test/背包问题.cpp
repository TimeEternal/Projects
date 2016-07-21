#include <iostream>
#include <fstream>
#include<algorithm>
#include<utility>
#include<cstring>
const int MAXN=100;
const int MAXC = 1000;
using namespace std;
int best=0,bestio[MAXN],d[MAXN][MAXC];
int c,n,w[MAXN],v[MAXN],io[MAXN];
pair<int,int> goods[MAXN];
void dfs(int i,int cw,int cp)    // 回溯
{
	if(i>=n){
		if(cp>best){
			best=cp;
			for(int i=0;i<n;i++) bestio[i]=io[i];
		}
	}
	else for(int j=0;j<2;j++){//io 在回到上一层向下搜索时 被重新值 无需还原
		io[i]=j;
		if((cw+io[i]*w[i])<=c){
			cp+=v[i]*io[i];
			dfs(i+1,cw+io[i]*w[i],cp);
		}
	}
}
bool cmp(pair<int,int> x,pair<int,int> y)
{
	if(float(x.second)/x.first>float(y.second)/y.first) return 1;
	else return 0;
}
int greedy()
{
	int max=0,w=0;
	sort(goods,goods+n,cmp);
	for(int i=0;i<n;i++)
		if(w+goods[i].first<c){
			w+=goods[i].first;
			max+=goods[i].second;
		}
		return max; 
}
int dp(){
	memset(d, 0, sizeof(d));
	for(int i=n-1;i>=0;i--)
		for (int j = 0; j <= c; j++) {
			if (j >= w[i])
				d[i][j] = max(d[i+1][j], d[i + 1][j - w[i]] + v[i]);
		}
		return d[0][c];
}
int main()
{
	ifstream in;ofstream out;int k=1;
	in.open("in.txt");
	out.open("out.txt");
	while(in>>c>>n&&c!=0){
		best=0;
		memset(d,0,sizeof(d));
		for(int i=0;i<n;i++) {
			in>>w[i]>>v[i];
			(goods+i)->first = w[i];
			(goods+i)->second = v[i];
		}
		out<<"Case "<<k++<<endl;
		out<<greedy()<<"   ";
		dfs(0,0,0);
		out<<best<<"   ";
		out << dp()<<endl<<endl;
	}
	in.close();out.close();
	return 0;
}