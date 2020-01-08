#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define F first
#define S second

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k; while (cin >> k) {
		vector<pii> ans;

		for (int x = k + 1; x <= 2 * k; x ++) {
			int y = k * x / (x - k);
			if (x * y == k * (x + y))
				ans.push_back( {y, x} );
		}

		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i ++) {
			cout << "1/" << k << " = 1/" << ans[i].F << " + 1/" << ans[i].S << '\n';
		}
	}	
}
