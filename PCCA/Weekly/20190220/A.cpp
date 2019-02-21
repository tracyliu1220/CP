#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T; while (T --) {
		LL n, a, b;
		cin >> n >> a >> b;
		if (a * 2 > b) { // 2
			cout << a * (n % 2) + b * (n / 2) << '\n';
		} else { // 1
			cout << a * n << '\n';
		}
	}
}
