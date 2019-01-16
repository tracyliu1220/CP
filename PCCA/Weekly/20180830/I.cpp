#include <bits/stdc++.h>
using namespace std;

int m[20][20] = {0};

int F(int l, int r) {
	if (m[l][r]) return m[l][r];
	
	if (l == 1 && r == 1 || l == 0 && r == 1 || l == 1 && r == 0) return 1;

	int L = 0, R = 0;
	int ll = l - 1, rr = r - 1;

	while (ll >= 0) {
		L += F(ll, l - ll - 1);
		ll --;
	}

	while (rr >= 0) {
		R += F(rr, r - rr - 1);
		rr --;
	}

	if (l == 0 || l == 1) L = 1;
	if (r == 0 || r == 1) R = 1;

	return m[l][r] = m[r][l] = L * R;

}

int main() {

	int n;
	cin >> n;
	cout << F(n, 0) << endl;
	while (cin >> n) {
		cout << '\n' << F(n, 0) << endl;
	}

}
