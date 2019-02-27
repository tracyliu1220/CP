#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int t = n % 10;
	if (t > 5) {
		cout << n - t + 10 << '\n';
	} else {
		cout << n - t << '\n';
	}
}
