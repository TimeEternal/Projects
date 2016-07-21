#include<iostream>  
using namespace std;  
string str(string s) {         //具体的转换函数  
  string a = "";  
  int l = s.length(), i, j, m;  
  for (i = 0; i < l; i = i + m) {  
      m = 1;  
      for (j = i + 1; j < l; j++) {  
        if (s[i] == s[j])  
          m++;  
        else  
          break;  
      }  
      char c = m + '0';  
      a.push_back(c);  
      a.push_back(s[i]);  
  }  
  return a;  
}  
string rec(int n) {   //动态规划函数  
  string res;  
  if (n == 1)  
    res = "1";  
  else  
    res = str(rec(n - 1));  
  return res;  
}   
int main() {  
  int n;  
  while(cin >> n)  
    cout << rec(n) << endl;  
}  