#include <iostream>
#include <map>

#ifdef LOCAL_LOGGER
#define _logger(...) fprintf(stderr, __VA_ARGS__)
#else
#define _logger(...);
#endif

using namespace std;
typedef long long var;

var read() {
	var s = 0, c = getchar(), a = 0;
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}

const int N = 5e3 + 100;

int n, a[N], b[N];
map<int, bool> ibMap;

bool check(int t) {
	if (t <= 2) return false;
	if (ibMap[t]) return false;
	ibMap[t] = true;
	for (int i = 1; i <= n; ++i) b[i] = a[i] % t;

	_logger("Check: %d\n", t);
	for (int i = 1; i <= n; ++i) _logger("%d ", b[i]);
	_logger("\n");

	sort(b + 1, b + n + 1);
	int num = 0;
	for (int i = 1; i <= n; ++i) {
		if (b[i] != b[i - 1]) num = 0;
		if (++num > n / 2) return true;
	}
	return false;
}

int main() {
	srand(time(0));
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int T = 1; T <= 100; ++T) {
		int x = a[rand() % n + 1], y = a[rand() % n + 1];
		_logger("X Y: %d %d\n", x, y);
		int d = abs(x - y);
		for (int i = 1; i * i <= d; ++i) {
			if (d % i) continue;
			if (check(i)) {
				printf("%d\n", i);
				return 0;
			} if (check(d / i)) {
				printf("%d\n", d / i);
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}
