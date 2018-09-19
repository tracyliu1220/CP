#include <bits/stdc++.h>
using namespace std;

int const INF = 0x3f3f3f3f;

int n;
int c[5000];
int dp[5000];

int main() {

	int cases;
	cin >> cases;

	while (cases --) {
		cin >> n;
		memset(dp, INF, sizeof(dp));
		for (int i = 0; i < n; i ++) {
			cin >> c[n + i];
			c[n - i - 1] = c[n + i];
		}

		int Ans = -1;
		for (int i = 0; i < 2 * n; i ++) {
			int *tar = lower_bound(dp, dp + 2 * n, c[i]);
			*tar = c[i];
			Ans = max(Ans, (int)(tar - dp));

		//	for (int j = 0; j < 2 * n; j ++) 
		//		if (dp[j] == INF) cout << "I ";
		//		else cout << dp[j] << ' ';
		//	cout << endl;
		}
		
		cout << ++Ans << '\n';

	}

}
