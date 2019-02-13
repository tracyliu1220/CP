#include <bits/stdc++.h>
using namespace std;

struct Com {
	int y, a, b;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<Com> v;
	int cnt = 1;

	int n; while (cin >> n && n) {
		cout << "Case #" << cnt++ << ":\n";
		int y, a, b;
		v.clear();
		for (int i = 0; i < n; i ++) {
			cin >> y >> a >> b;
			v.push_back( {y, a, b} );
		}
		int cur = v[0].y;
		int found = 0;
		while (cur < 10000) {
			int legal = 1;
			for (int i = 1; i < n; i ++) {
				if (cur < v[i].y || (cur - v[i].y) % (v[i].b - v[i].a) != 0) {
					legal = 0;
					break;
				}
			}
			if (legal) {
				cout << "The actual year is " << cur << ".\n";
				found = 1;
				break;
			}
			cur += v[0].b - v[0].a;
		}
		if (!found) cout << "Unknown bugs detected.\n";
		cout << '\n';
	}
}
