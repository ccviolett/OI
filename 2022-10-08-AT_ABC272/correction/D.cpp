#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
typedef long long var;

var read() {
	var s = 0, c = getchar(), a = 0;
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}

const int N = 405;

struct Node {
	int x, y;
};

int n, m, res[N][N];
Node q[N * N];

Node operator + (Node a, Node b) { return (Node) {a.x + b.x, a.y + b.y}; }
bool check(Node t) {
	return res[t.x][t.y] == -1 && 
		t.x >= 1 && t.x <= n && t.y >= 1 && t.y <= n;
}

int main() {
	n = read(), m = read();
	memset(res, -1, sizeof(res));

	int head = 0, tail = 0;
	q[++tail] = (Node) {1, 1};
	res[1][1] = 0;
	while (head < tail) {
		Node t = q[++head];
		for (int i = 0; i * i <= m; ++i) {
			int v1 = i, v2 = sqrt(m - i * i);
			if (v1 * v1 + v2 * v2 != m) continue;
			for (int d1 = -1; d1 <= 1; d1 += 2) {
				for (int d2 = -1; d2 <= 1; d2 += 2) {
					Node p = t + (Node) {d1 * v1, d2 * v2};
					if (check(p)) {
						res[p.x][p.y] = res[t.x][t.y] + 1;
						q[++tail] = p;
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) printf("%d ", res[i][j]);
		puts("");
	}

	return 0;
}
