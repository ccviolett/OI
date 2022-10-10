#include <iostream>
#include <queue>
using namespace std;
typedef long long var;

var read() {
	var s = 0, c = getchar(), a = 0;
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}

int main() {
	int n = read();
	var res = 0;
	for (int i = 1; i <= n; ++i) res += read();
	printf("%lld\n", res);
	return 0;
}
