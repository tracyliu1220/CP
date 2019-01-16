#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q; cin >> q;
	LL n, m, k;
	while (q --) {
		cin >> n >> m >> k;

		if (n > k || m > k) {
			cout << -1 << endl;
			continue;
		}

		int ans;
		
		if (k <= n + m) {
			int d = n + m - k;
			n -= d;
			m -= d;

			ans = (n / 2) * 2 + (m / 2) * 2 + d;
		} else {
			if ((n % 2) ^ (m % 2)) ans = k - 1;
			else if (n % 2 && m % 2) {
				if (k % 2) ans = k;
				else ans = k - 2;
			} else {
				if (k % 2) ans = k - 2;
				else ans = k;
			}
		}

		cout << ans << endl;

	}
}
