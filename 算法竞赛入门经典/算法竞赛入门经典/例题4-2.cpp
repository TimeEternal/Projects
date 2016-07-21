#include<iostream>
#include<string>
#include<iterator>
using namespace std;

int main()
{
	int k;
	string qes,ans;
	while (cin >> k >> qes >> ans&&k != -1) {
		int chance = 7,left=qes.length();
		bool win = 0, lose = 0;
		for (string::iterator i = ans.begin(); i < ans.end(); i++) {
			bool bad = 1;
			for (string::iterator j = qes.begin(); j < qes.end(); j++) {
				if (*i == *j) { bad = 0; left--; *j = ' '; }
			}
			if (bad) chance--;
			if (!chance) lose = 1;
			if (!left) win = 1;
			if (win || lose) break;//提前跳出循环 aaaaaaaaaaaaaa 前半就输 abcdefghij abcdef就猜对了
		}
		cout << "Round " << k << endl;
		if (win) cout << "You win"<<endl;
		else if (lose) cout << "You lose"<<endl;
		else cout << "You checked out"<<endl;
	}
	return 0;
}
