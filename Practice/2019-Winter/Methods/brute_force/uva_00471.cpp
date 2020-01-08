#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int num[10];
const LL MAX = 9876543210;

int check(LL n) {
	memset(num, 0, sizeof(num));
	if (n > MAX) return 0;
	while (n) {
		if (num[n % 10]) return 0;
		num[n % 10] = 1;
		n /= 10;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	int T; cin >> T; while (T --) {
		LL n; cin >> n;
		LL s1, s2;
		for (LL s2 = 1; s2 < MAX; s2 ++) {
			if (check(s2)) {
				s1 = n * s2;
				if (s1 > MAX) break;
				if (check(s1)) {
					cout << s1 << " / " << s2 << " = " << n << '\n';
				}
			}
		}
		if (T) cout << '\n';
	}
}
