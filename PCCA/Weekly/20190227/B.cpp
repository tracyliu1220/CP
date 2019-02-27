#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, A, B;
	cin >> n >> A >> B;

	int legal = 0;

	for (int i = 0; i * A <= n; i ++) {
		if ((n - i * A) % B == 0) {
			cout << "YES\n";
			cout << i << ' ' << (n - i * A) / B << '\n';
			legal = 1;
			break;
		}
	}

	if (!legal) cout << "NO\n";
}
