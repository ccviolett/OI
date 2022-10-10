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

const int N = 101;
bool attend[N][N];

int main() {
	int n = read(), m = read();
	for (int i = 1; i <= m; ++i) {
		int k = read();
		for (int j = 1; j <= k; ++j) attend[read()][i] = true;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			bool have = false;
			for (int k = 1; k <= m; ++k) {
				if (attend[i][k] && attend[j][k]) {
					have = true;
					break;
				}
			}
			if (!have) {
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
}
