#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int P[30];
	int dp[1 << 20 + 1];
	//int dp[5000];
	
	int T; cin >> T; while (T --) {
		int n; cin >> n;
		int total = 0;
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; i ++) {
			cin >> P[i];
			total += P[i];
		}

		int tar = total / 2;
		for (int s = 0; s < (1 << n); s ++) {
			for (int i = 0; i < n; i ++) {
				if (s & (1 << i)) {
					dp[s] = dp[s & ~(1 << i)] + P[i];
				}
			}
		}

		int ans[30] = {0};
		for (int s = 0; s < (1 << n); s ++) {
			for (int i = 0; i < n; i ++) {
				if (!(s & (1 << i)) && dp[s] + P[i] > tar && dp[s] <= tar)
					ans[i] ++;
			}
		}

		for (int i = 0; i < n; i ++) {
			cout << "party " << i + 1 << " has power index " << ans[i] << '\n';
		}
		cout << '\n';
	}
}
