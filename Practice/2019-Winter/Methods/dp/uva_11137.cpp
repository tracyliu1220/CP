#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[10005] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 1;
    for (int i = 1; i <= 21; i ++) {
        for (int j = i*i*i; j < 10000; j ++)
            dp[j] += dp[j - i*i*i];
    }

    int x;
    while (cin >> x) {
        cout << dp[x] << '\n';
    }
}
