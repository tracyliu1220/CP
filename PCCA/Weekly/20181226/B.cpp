#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, T; cin >> T;
    while (T --) {
        cin >> n;
        int cur, Max = -1, Min = 100;
        while (n --) {
            cin >> cur;
            Max = max(Max, cur);
            Min = min(Min, cur);
        }
        cout << 2 * (Max - Min) << '\n';
    }
}
