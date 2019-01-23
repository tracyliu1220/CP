#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;

	int T; cin >> T; while (T --) {
		cin >> m >> n;
		int ans_m = 0, ans_n = 0;
		m -= 2; n -= 2;
		if (m % 3) ans_m = 1;
		if (n % 3) ans_n = 1;
		
		ans_m += m / 3;
		ans_n += n / 3;

		cout << ans_m * ans_n << '\n';
	}

}
