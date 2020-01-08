#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
int w[1005];
int l[1005];
int dp[7000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n && n) {
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i ++) {
            cin >> w[i] >> l[i];
        }

        dp[0] = 0;
        for (int i = n - 1; i >= 0; i --) {
            for (int j = l[i] + w[i]; j >= w[i]; j --) {
                dp[j] = max(dp[j], dp[j - w[i]] + 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < 7000; i ++) {
            ans = max(ans, dp[i]);
        }
        
        cout << ans << '\n';
    }
}
