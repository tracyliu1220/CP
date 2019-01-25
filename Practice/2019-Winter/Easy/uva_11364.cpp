#include <bits/stdc++.h>
using namespace std;

const int INF = 2000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T; while (T --) {
		int n, tmp, Max = -1, Min = INF; cin >> n;
		while (n --) {
			cin >> tmp;
			Max = max(Max, tmp);
			Min = min(Min, tmp);
		}
		cout << 2 * (Max - Min) << '\n';
	}
}
