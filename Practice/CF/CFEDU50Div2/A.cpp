#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	LL n, k;
	cin >> n >> k;
	if (k % n == 0) cout << k / n << endl;
	else cout << k / n + 1 << endl;

}
