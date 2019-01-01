#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int lim = 50;
map<pair<int, int>, int> e;

/*
2 < n, n2 < 10000
n-1 <= m < 100000
n2-1 <= m2 < 100000
2 < t, t2 <= 30
*/

int main() {
	int n, m, t;
	int cost = 1000;
	srand(time(NULL));
	int T = 2;
	while (T --) {
		e.clear();
		n = max(3, rand() % 10000); 
		m = max(n - 1, rand() % min(100000, n * n / 2));
		t = max(1, rand() % min(n, 30));

		cout << n << ' ' << t << ' ' << m << '\n';
		for (int i = 0; i < t; i ++)
			cout << i + 1 << ((i != t - 1)? ' ':'\n');
		for (int i = 2; i <= n; i ++) {
			int u = max(1, rand() % i);
			e[pii(i, u)] = 1;
			e[pii(u, i)] = 1;
			cout << i << ' ' << u << ' ' << rand() % cost + 1 << '\n';
		}
		for (int i = 0; i < m - n + 1; i ++) {
			int u, v;
			do {
				u = rand() % n + 1;
				v = rand() % n + 1;
			} while (u == v || e.count(pii(u, v)));
			e[pii(u, v)] = 1;
			e[pii(v, u)] = 1;
			cout << u << ' ' << v << ' ' << rand() % cost + 1 << '\n';
		}
	}
}
