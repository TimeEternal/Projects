/*
首先计算m的值，用二进制表示的话，m的值为0.11…，也就是m = 2^(-1) + 2^(-2) + … + 
2^(-1 - i)（i比实际1的个数少1个），也就是m = 1 - 2^(-1 - i)。接下来就是计算e的值，
不难得出，e = 2^j - 1。那么也就有m * 2^e = A * 10^B，似乎可以直接计算了。然而，直接
这样算的话是不行的，因为当e太大的话（e最大可以是1073741823，注意这还只是2的指数），
等号左边的数就会超出上限，所以要想继续算下去，就得自己去想办法再写出满足要求的类来，
这显然太麻烦了。所以，这个时候我们对等式两边同时取对数，这个时候就有 
log10(m) + e × log10(2) = log10(A) + B。因为此时m和e的值都是确定的，所以不妨令等式
左边为t，也就有t = log10(A) + B。这个时候就有问题了，A和B怎么算。写题解的时候突然意识
到了这个问题，读题的时候很多人，包括我，都把AeB默认为了科学记数法，在ACTA协会群里面讨论
的时候很多人也都说这是科学计数法。先来看如果是科学记数法的时候应该怎么办。
如果是科学记数法的话，那么对于A，就有1 ≤ A < 10。那么0 < log10(A) < 1。所以t的小数部
分就是log10(A)，整数部分就是B，即B = ⌊t⌋，A = 10^(t - B)。那么接下来，我们只需要开出
两个二维数组来，分别记录对应i和j下A和B的大小，之后从输入里提取出A和B的大小，去二维数组
里面查找对应的i和j即可。*/
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	double TA[20][40];
	long long TB[20][40];

	// 打表
	for (int i = 0; i <= 9; ++i) 
		for (int j = 1; j <= 30; ++j) {
		double m = 1 - pow(2, -1 - i), e = pow(2, j) - 1;
		double t = log10(m) + e * log10(2);
		TB[i][j] = floor(t), TA[i][j] = pow(10, t - TB[i][j]);
	}

	// 输入并输出结果
	string in;
	while (cin >> in && in != "0e0") {
		// 处理输入
		for (string::iterator i = in.begin(); i != in.end(); ++i) if (*i == 'e') *i = ' ';
		istringstream ss(in);
		double A; int B;
		ss >> A >> B;
		while (A < 1) A *= 10, B -= 1;
		// 在打好的表中寻找答案
		for (int i = 0; i <= 9; ++i) 
			for (int j = 1; j <= 30; ++j) {
			if (B == TB[i][j] && (fabs(A - TA[i][j]) < 1e-4 || fabs(A / 10 - TA[i][j]) < 1e-4)) {
				cout << i << ' ' << j << endl;
				break;
			}
		}
	}
}
