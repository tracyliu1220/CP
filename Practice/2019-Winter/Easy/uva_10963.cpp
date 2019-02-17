#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int state = 0;
	int T; cin >> T; while (T --) {
		int n; cin >> n;
		int a, b;
		cin >> a >> b;
		int diff = a - b;
		int legal = 1;
		for (int i = 1; i < n; i ++) {
			cin >> a >> b;
			if (a - b != diff) legal = 0;
		}
		if (state) {
			cout << '\n';
		}
		state = 1;
		if (legal) cout << "yes\n";
		else cout << "no\n";
	}
}
