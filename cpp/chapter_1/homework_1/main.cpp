//编写程序，接受用户输入的10个整数，输出它们的和。
#include <iostream>

using namespace std;

int main(){
	int a, b, c, d, e, f, g, h, i, j, sum;
	cout << "请输入10个整数(用Enter键换数):" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;
	cin >> f;
	cin >> g;
	cin >> h;
	cin >> i;
	cin >> j;
	sum = a + b + c + d + e + f + g + h + i + j;
	cout << "10个整数之和为：" << sum << endl;
	
	return 0;
}
