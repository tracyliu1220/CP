#include <bits/stdc++.h>
using namespace std;

int a[3];

int main() {
    int T; cin >> T; 
    for (int i = 1; i <= T; i ++) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        cout << "Case " << i << ": " << a[1] << '\n';
    }
}
