#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
const int MAXN=5000;
struct rec
{
	int l,h,r;
}t;
bool cmp(const rec &x,const rec &y)
{
	/*if(x.h <= y.h) return 0;
	else return 1;*/
	return y.h < x.h;
}
bool cmp1(const rec &x, const rec &y)
{
	return x.l<y.l;
}
int vis[MAXN];
vector<rec> s;
vector<rec> ans;
int main()
{
	memset(vis,0,sizeof(vis));
	while (cin>>t.l>>t.h>>t.r)
	{
		s.push_back(t);
	}
	sort(s.begin(),s.end(),cmp);
	vector<rec>::iterator iter;
	for (iter=s.begin();iter<s.end();iter++)
	{
		bool flag = 1;
		int st, e;
		rec temp;
		temp.h=iter->h;
		for (int j = iter->l; j <= iter->r; j++) {
			if (flag && !vis[j + 1]) { st = j; flag = 0; }
			if (!flag&&(vis[j]&&j!=st||j==iter->r)) {
				if (vis[j]) e = j-1;
				else e = j ;
				flag = 1;
				temp.l = st; 
				temp.r = e;
				ans.push_back(temp);
				for (int k = st + 1; k <= e; k++) vis[k] = 1;
			}
		}
	}
	sort(ans.begin(),ans.end(),cmp1);
	cout << endl<<ans.begin()->l;
	for (iter = ans.begin(); iter < ans.end() - 1; iter++)
	{
		cout <<" " << iter->h << " " << iter->r;
		if (iter->r != (iter + 1)->l)
			cout << " " << 0 << " "<< (iter + 1)->l;
	}
	cout << " " << iter->h <<" "<<iter->r<< " 0" << endl;
	return 0;
}