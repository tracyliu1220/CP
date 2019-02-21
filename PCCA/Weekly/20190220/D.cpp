#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	if (n == 1) {
		if (a[0] >= m) cout << 1 << '\n';
		else cout << -1 << '\n';
		return 0;
	}

	int L = 0, R = n + 1, M; // days
	while (R - L > 1) {
		M = (R + L) / 2;
		LL sum = 0;
		for (int i = 0; i <= n / M; i ++) {
			for (int j = 0; j < M; j ++) {
				if (i * M + j == n) break;
				sum += max(0LL, a[i * M + j] - i);
			}
		}
		// cout << M << ' ' << sum << '\n';
		if (sum < m) L = M;
		else R = M;
	}
	if (R == n + 1) cout << -1 << '\n';
	else cout << R << '\n';
}
