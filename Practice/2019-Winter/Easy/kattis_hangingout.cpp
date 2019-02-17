#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, T; cin >> n >> T;
	int cur = 0;
	string state;
	int x;
	int cnt = 0;
	while (T --) {
		cin >> state >> x;
		if (state[0] == 'e') {
			if (cur + x <= n) {
				cur += x;
			} else cnt ++;
		} else {
			cur = max(0, cur - x);
		}
	}
	cout << cnt << '\n';
}
