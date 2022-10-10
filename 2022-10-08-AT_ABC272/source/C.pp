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

const int N = 2e5 + 100;

int a[N], v[10];

int main() {
	int n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	sort(a + 1, a + n + 1);
	if (n == 2) {
		if ((a[1] + a[2]) % 2) puts("-1");
		else printf("%d\n", a[1] + a[2]);
		return 0;
	}

	int vp = a[n - 1] + a[n - 2];
	for (int i = n - 1; i >= 1; --i) {
		if ((a[n] + a[i]) % 2) continue;
		if (!(vp % 2) && a[n] + a[i] < vp) 
			printf("%d\n", vp);
		else 
			printf("%d\n", a[n] + a[i]);
		break;
	}
	return 0;
}
