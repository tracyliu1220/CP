#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n) {
	if (n == 0) return m;
	else return gcd(n, m % n);
}

int lcm(int m, int n) {
	return m * n / gcd(m, n);
}

int main() {
	int n;
	cin >> n;

	int a[150005], b[150005];
	cin >> a[0] >> b[0];
	long long tar = lcm(a[0], b[0]);

	for (int i = 1; i < n; i ++) {
		cin >> a[i] >> b[i];
		long long l = lcm(a[i], b[i]);

		tar = gcd(tar, l);
	}

	for (int i = 0; i < n; i ++) {
		if (tar > a[i]) tar = a[i];
		if (tar > b[i]) tar = b[i];
	}

	if (tar == 1) cout << -1 << endl;
	else cout << tar << endl;
}
