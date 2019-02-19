#include <bits/stdc++.h>
using namespace std;

int C[25];
int state[25];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, c;
	int t = 1;
	while (cin >> n >> m >> c && (n || m || c)) {
		memset(C, 0, sizeof(C));
		memset(state, 0, sizeof(state));

		for (int i = 1; i <= n; i ++)
			cin >> C[i];

		int cur = 0;
		int Max = 0;
		int legal = 1;
		int tmp;
		while (m --) {
			cin >> tmp;
			if (state[tmp]) {
				cur -= C[tmp];
				state[tmp] = 0;
			} else {
				cur += C[tmp];
				state[tmp] = 1;
			}
			Max = max(Max, cur);
			if (Max > c) legal = 0;
		}
	
		cout << "Sequence " << t << '\n';
		if (legal) cout << "Fuse was not blown.\nMaximal power consumption was " << Max << " amperes.\n";
		else cout << "Fuse was blown.\n";
		t ++;
		cout << '\n';
	}
}
