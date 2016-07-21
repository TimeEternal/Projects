#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

bool prime[10000 + 5],in[10000+5];
int m, n;
int a[] = { 0,1,2,3,4,5,6,7,8,9 };
struct node {
	int num, step;
};
void bfs() {
	queue<node> q;
	node t,f;
	q.push({m,0});
	while (!q.empty()) {
		f = q.front(); in[f.num] = 1;
		if (f.num == n) { cout << f.step << endl; return; }
		t.step = f.step + 1;
		for (int i = 0; i < 10; i++) {
			t.num = f.num / 10 * 10 + a[i];
			if (!prime[t.num] && !in[t.num]) { q.push(t); in[t.num] = 1; }//cout << t.num << " ";}
			t.num = f.num / 100 * 100 + f.num % 10 + a[i] * 10;
			if (!prime[t.num] && !in[t.num]) { q.push(t); in[t.num] = 1; }//cout << t.num << " ";}
			t.num = f.num / 1000 * 1000 + f.num % 100 + a[i] * 100;
			if (!prime[t.num] && !in[t.num]) { q.push(t); in[t.num] = 1; }// cout << t.num << " ";}
			t.num = f.num % 1000 + a[i] * 1000;
			if (!prime[t.num] && !in[t.num] && t.num > 1000) { q.push(t); in[t.num] = 1; }// cout << t.num << " ";}
		}
		q.pop();
		//cout << endl<<q.front().num<<":"<<endl;
	}
}
int main()
{
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= 100; i++)
		if (!prime[i])
			for (int j = i*i; j <= 10000; j += i)
				prime[j] = 1; 
	int k;
	cin >> k;
	while (k--) {
		cin >> m >> n;
		memset(in, 0, sizeof(in));
		bfs();
	}
	return 0;
}