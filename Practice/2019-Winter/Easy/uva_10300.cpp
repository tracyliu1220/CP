#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T; while (T --) {
		int n; cin >> n;
		int a, b, c;
		int sum = 0;
		for (int i = 0; i < n; i ++) {
			cin >> a >> b >> c;
			sum += a * c;
		}
		cout << sum << '\n';
	}
}
