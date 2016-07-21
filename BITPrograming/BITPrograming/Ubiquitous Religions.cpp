#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX = 50000+7;
//每一个集合都是一棵树，集合的元素则为树的节点，每棵树都有一个独一无二的标志，那、、//就是树的根节点
//一般的标志是自己本身的下标 或者 为-1
int father[MAX];  //father[x]表示x的父节点
int sign[MAX];    //sign[x] 用来记录查找根节点时，途中所路过的节点，压缩路径的时候用到
int rak[MAX];    //rak[x]  表示x节点所在树的深度
				  //初始化集合
void Make_Set(int x)

{
	father[x] = x;    //初始化一开始每个节点的父节点都为本身
	rak[x] = 0;      //初始化一开始每棵树的深度为
}
// 寻找x元素所在的集合也就是找子节点的根节点（树,若采用递归查找，回溯时压缩路径
int Find_Set(int x)
{
	if (father[x] != x)
	{
		father[x] = Find_Set(father[x]); //这是一个递归的过程，回溯时压缩路径
	}
	return father[x];
}
void Union(int x, int y)    //合并两个不相交的集合，x,y分别为两个不同的集合
{
	x = Find_Set(x);
	y = Find_Set(y);
	if (x == y)  return;    //若为同一集合，则直接返回
	if (rak[x] > rak[y])   //如果x树的深度比y树深，y树接到x树
	{
		father[y] = x;
	}
	else if (rak[x] < rak[y])
	{

		father[x] = y;

	}
	else if (rak[x] == rak[y])  //若两树的深度一样
	{
		father[x] = y;           //则x树接到y树
		rak[y]++;              //此时y树的深度+1
	}
}
bool same(int x, int y)//判断x和y是否属于同一个集合
{
	return Find_Set(x) == Find_Set(y);
}

int main()
{
	int m, n,i=1;
	while (cin >> n >> m&&m !=0 && n != 0) {
		for (int i = 1; i <= n; i++)
			Make_Set(i);
		while (m--) {
			int x, y;
			cin >> x >> y;
			Union(x, y);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (Find_Set(i) == i) ans++;
		cout << "Case "<<i<<": "<<ans << endl;
		i++;
	}
	return 0;
}