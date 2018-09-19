#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int dp[305][305];

int main() {
	
	int cases;
	cin >> cases;

	int m, S;

	while (cases --) {
		
		cin >> m >> S;

		memset(dp, INF, sizeof(dp));
		dp[0][0] = 0;

		int x, y;
		for (int i = 0; i < m; i ++) {
			cin >> x >> y;
			for (int j = x; j <= S; j ++)
				for (int k = y; k <= S; k ++)
					if(dp[j - x][k - y] != INF)
						dp[j][k] = min(dp[j][k], dp[j - x][k - y] + 1);
		}

		int diff;
		int ans = INF;

		for (int i = 0; i * i <= S * S; i ++) {
			diff = S * S - i * i;
			diff = sqrt(diff) + 1e-6;
			
			if (diff * diff + i * i != S * S) continue;
			
			ans = min(ans, dp[i][diff]);
		}

		if (ans == INF) cout << "not possible\n";
		else cout << ans << '\n';
	}

}
