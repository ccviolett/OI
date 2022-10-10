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

struct Item {
	int step, round, val;
};

bool operator < (const Item a, const Item b) {
	return a.val > b.val;
}

priority_queue<Item> q;
int res[N];

int main() {
	int n = read(), m = read();
	for (int i = 1; i <= n; ++i) {
		int v = read(), r = (-v + i - 1) / i;
		if (v < 0) q.push((Item) {i, r, v + i * r});
		else q.push((Item) {i, 0, v});
	}
	int mxv = 0;
	while (!q.empty() && true) {
		Item item = q.top();
		q.pop();
		if (item.round > m) continue;
		// cout << item.step << " " << item.round << " " << item.val << endl;
		if (mxv < item.val - 1) break;
		if (res[item.round] == item.val)
			mxv = max(mxv, ++res[item.round]);
		if (item.round < m)
			q.push((Item) {item.step, item.round + 1, item.val + item.step});
	}
	for (int i = 1; i <= m; ++i)
		printf("%d\n", res[i]);
	return 0;
}
