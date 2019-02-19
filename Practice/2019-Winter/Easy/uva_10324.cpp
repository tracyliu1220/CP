#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	string str;
	while (cin >> str) {
		int n, a, b; cin >> n;
		cout << "Case " << t << ":\n";
		while (n --) {
			cin >> a >> b;
			int _a = min(a, b);
			int _b = max(a, b);
			int legal = 1;
			for (int i = _a + 1; i <= _b; i ++) {
				if (str[i] != str[i - 1]) legal = 0;
			}
			if (legal) cout << "Yes\n";
			else cout << "No\n";
		}
		t ++;
	}
}
