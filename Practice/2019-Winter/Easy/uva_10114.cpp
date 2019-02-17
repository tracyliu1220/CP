#include <bits/stdc++.h>
using namespace std;

double dep[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int month, m, n;
	double dpay, mpay, v, car, r;
	while (cin >> month >> dpay >> v >> n && month > 0) {
		memset(dep, 0, sizeof(dep));
		for (int i = 0; i < n; i ++) {
			cin >> m >> r;
			dep[m] = r;
		}
		car = v + dpay;
		mpay = v / month;
		for (m = 0; m < month; m ++) {
			if (dep[m]) r = dep[m];
			car *= (1.0 - r);
			if (v < car) break;
			v -= mpay;
		}
		if (m == 1) cout << "1 month\n";
		else cout << m << " months\n";
	}
}
