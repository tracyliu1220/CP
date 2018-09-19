#include <bits/stdc++.h>
using namespace std;

int f[105], b[105];
int dp[12000];

int main() {
	
	int B, n;
	while (cin >> B >> n) {
		
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; i ++) {
			cin >> b[i] >> f[i];
			//dp[i] = f[i];
		}

		for (int i = 0; i < n; i ++) 
			for (int j = B + 200; j >= b[i]; j --) {
				if(!dp[j - b[i]] && j != b[i]) continue;
				dp[j] = max(dp[j], dp[j - b[i]] + f[i]);
			}
	
		int ans = 0;
		for (int i = 0; i <= B + 200; i ++)
			if ((i > 2000 && i <= B + 200) || i <= B)
				ans = max(ans, dp[i]);
		cout << ans << '\n';
	}
}
