#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T; while (T --) {
		int n, m; cin >> n >> m;
		int Max1 = -1, Max2 = -1;
		int tmp;
		while (n --) {
			cin >> tmp;
			Max1 = max(Max1, tmp);
		}
		while (m --) {
			cin >> tmp;
			Max2 = max(Max2, tmp);
		}
		if (Max1 < Max2)
			cout << "MechaGodzilla\n";
		else
			cout << "Godzilla\n";
	}
}
