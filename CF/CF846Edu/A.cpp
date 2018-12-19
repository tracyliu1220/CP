#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[200];
    int one = 0, zero = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i]) one ++;
    }

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] == 0) zero ++;
        ans = max(ans, one + zero);
        if (a[i] == 1) one --;
    }

    cout << ans << '\n';
}
