#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAX 50

LL n, k, M, m;
LL t[MAX];
LL sum = 0;

int main() {
    cin >> n >> k >> M;
    for (int i = 0; i < k; i ++) {
        cin >> t[i];
        sum += t[i];
    }

	sort(t, t + k);

    LL cur, ans = 0;
    for (int i = 0; i < n + 1 && M - sum * i >= 0; i ++) {
        m = M - sum * i;
        cur = (k + 1) * i;
        //cout << "before= " << cur << '\n';
        LL tar;
        for (int j = 0; j < k; j ++) {
            tar = min(m / t[j], n - i);
            cur += tar;
            m -= t[j] * tar;
        }
        //cout << "cur= " << cur << '\n';
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}
