#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	string s = "223344AA";
	do {
		unsigned iab = s.find("A", 0);
		unsigned iae = s.find("A", iab + 1);
		unsigned i2b = s.find("2", 0);
		unsigned i2e = s.find("2", i2b + 1);
		unsigned i3b = s.find("3", 0);
		unsigned i3e = s.find("3", i3b + 1);
		unsigned i4b = s.find("4", 0);
		unsigned i4e = s.find("4", i4b + 1);
		if (iae - iab == 2 && i2e - i2b == 3 && i3e - i3b == 4 && i4e - i4b == 5) {
			cout << s << endl;
		}

	} while (next_permutation(s.begin(), s.end()));
	return 0;
}