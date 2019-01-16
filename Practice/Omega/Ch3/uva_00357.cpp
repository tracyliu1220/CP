#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int coin[5] = {50, 25, 10, 5, 1};
LL dp[30005];

int main() {

	int tar;

	while (cin >> tar) {
		memset(dp, 0, sizeof(dp));
		
		dp[0] = 1;

		for (int c = 0; c < 5; c ++) {
			for (int i = coin[c]; i <= tar; i ++) {
				dp[i] += dp[i - coin[c]];
			}
		}
		
		if (dp[tar] == 1)
			cout << "There is only 1 way to produce " << tar << " cents change.\n";
		else
			cout << "There are " << dp[tar] << " ways to produce " << tar << " cents change.\n";
	
	}

}
