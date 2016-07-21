#include <iostream>
using namespace std;
struct binode
{
	char data;
	binode* lchild, * rchild;
};
class bitree
{
public:
	void creat();//建立二叉树
	void inorder();//中序遍历
private:
	binode* root;
	binode* creat(binode* &);
	void inorder(binode* );
};
void bitree::creat()
{
	creat(root);
}
binode* bitree::creat(binode* &bt)               //
{
	char ch;
	cin >> ch;
	if (ch == '*')
		bt = NULL;
	else {
		bt = new binode;
		bt->data = ch;
		bt->lchild = creat(bt->lchild);
		bt->rchild = creat(bt->rchild);
	}
	return bt;
}
void bitree::inorder()
{
	inorder(root);
	cout << endl;
}
void bitree::inorder(binode* bt)          //
{
	if (bt == NULL)
		return;
	else {
		inorder(bt->lchild);
		cout << bt->data;
		inorder(bt->rchild);
	}
}
int main()
{
	bitree i;
	i.creat();
	i.inorder();
	return 0;
}