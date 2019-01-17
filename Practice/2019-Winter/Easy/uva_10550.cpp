#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, d;
	while (cin >> a >> b >> c >> d && (a || b || c || d)) {
		int ans = 1080;
		ans += 9 * ((a - b + 40) % 40);
		ans += 9 * ((c - b + 40) % 40);
		ans += 9 * ((c - d + 40) % 40);
		cout << ans << '\n';
	}
}
