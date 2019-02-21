#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
typedef long long LL;

int c[MAX];
LL dp[4][MAX] = {0}; // front: odd even, back: odd even

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> c[i];

	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}

	dp[1][0] = c[0];
	if (n % 2) dp[3][n - 1] = c[n - 1];
	else dp[2][n - 1] = c[n - 1];
	for (int i = 1; i < n; i ++) { // odd
		dp[0][i] = dp[0][i - 1];
		if (i % 2) dp[0][i] += c[i];
	}
	for (int i = 1; i < n; i ++) { // even
		dp[1][i] = dp[1][i - 1];
		if (i % 2 == 0) dp[1][i] += c[i];
	}
	for (int i = n - 2; i >= 0; i --) { // odd
		dp[2][i] = dp[2][i + 1];
		if (i % 2) dp[2][i] += c[i];
	}
	for (int i = n - 2; i >= 0; i --) { // even
		dp[3][i] = dp[3][i + 1];
		if (i % 2 == 0) dp[3][i] += c[i];
	}

	/*
	for (int i = 0; i < 4; i ++) {
		for (int j = 0; j < n; j ++)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}
	*/

	int cnt = 0;
	for (int i = 1; i < n - 1; i ++) {
		if (dp[0][i - 1] + dp[3][i + 1] == dp[1][i - 1] + dp[2][i + 1]) {
			cnt ++;
		}
	}
	if (dp[0][n - 2] == dp[1][n - 2]) cnt ++;
	if (dp[2][1] == dp[3][1]) cnt ++;
	
	cout << cnt << '\n';
}
