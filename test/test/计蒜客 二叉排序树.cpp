#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node *lchild, *rchild, *father;
	Node(int _data, Node *_father = NULL) {
		data = _data;
		lchild = NULL;
		rchild = NULL;
		father = _father;
	}
	~Node() {
		if (lchild != NULL) {
			delete lchild;
		}
		if (rchild != NULL) {
			delete rchild;
		}
	}
	void insert(int value) {
		if (value == data) {
			return;
		}
		else if (value > data) {
			if (rchild == NULL) {
				rchild = new Node(value, this);
			}
			else {
				rchild->insert(value);
			}
		}
		else {
			if (lchild == NULL) {
				lchild = new Node(value, this);
			}
			else {
				lchild->insert(value);
			}
		}
	}
	Node* search(int value) {
		if (data == value) {
			return this;
		}
		else if (value > data) {
			if (rchild == NULL) {
				return NULL;
			}
			else {
				return rchild->search(value);
			}
		}
		else {
			if (lchild == NULL) {
				return NULL;
			}
			else {
				return lchild->search(value);
			}
		}
	}
	Node* predecessor() {
		Node *temp = lchild;
		while (temp != NULL && temp->rchild != NULL) {
			temp = temp->rchild;
		}
		return temp;
	}
	Node* successor() {
		Node *temp = rchild;
		while (temp != NULL && temp->lchild != NULL) {
			temp = temp->lchild;
		}
		return temp;
	}
	void remove_node(Node *delete_node) {
		Node *temp = NULL;
		if (delete_node->lchild != NULL) {
			temp = delete_node->lchild;
			temp->father = delete_node->father;
			delete_node->lchild = NULL;
		}
		if (delete_node->rchild != NULL) {
			temp = delete_node->rchild;
			temp->father = delete_node->father;
			delete_node->rchild = NULL;
		}
		if (delete_node->father->lchild == delete_node) {
			delete_node->father->lchild = temp;
		}
		else {
			delete_node->father->rchild = temp;
		}
		delete delete_node;
	}
	bool delete_tree(int value) {
		Node* delete_node, *current_node;
		current_node = search(value);
		if (current_node == NULL) { return false; }
		if (current_node->lchild != NULL) {
			delete_node = current_node->predecessor();
		}
		else if (current_node->rchild != NULL) {
			delete_node = current_node->successor();
		}
		else { delete_node = current_node; }
		current_node->data = delete_node->data;
		remove_node(delete_node);
		return true;
	}
	void dfs(Node* t) {
		if (t) {
			dfs(t->lchild);
			cout << t->data<<"(";
			if (t->lchild == NULL)cout << "#, ";
			else cout << t->lchild->data << ", ";
			if (t->rchild == NULL)cout << "#)"<<endl;
			else cout << t->rchild->data << ")"<<endl;
			dfs(t->rchild);
		}
	}
};
class BinaryTree {
private:
	Node *root;
public:
	BinaryTree() {
		root = NULL;
	}
	~BinaryTree() {
		if (root != NULL) {
			delete root;
		}
	}
	void insert(int value) {
		if (root == NULL) {
			root = new Node(value);
		}
		else {
			root->insert(value);
		}
	}
	bool find(int value) {
		if (root->search(value) == NULL) {
			return false;
		}
		else {
			return true;
		}
	}
	bool delete_tree(int value) {
		return root->delete_tree(value);
	}
	void inorder() {
		root->dfs(root);
	}
};
int main() {
	BinaryTree btree;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		btree.insert(x);
	}
	btree.inorder();
	return 0;
}
