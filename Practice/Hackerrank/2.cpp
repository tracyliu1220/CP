#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
int num[20];
LL sum = 0;
LL avg;

int solve(LL a, LL b, LL c, int idx, int state) {

	if (idx == n && a == avg && b == avg && c == avg && state == 7)
		return 1;

	if (idx >= n)
		return 0;

	int A = solve(a + num[idx], b, c, idx + 1, (state | 1 << 0));
	int B = solve(a, b + num[idx], c, idx + 1, (state | 1 << 1));
	int C = solve(a, b, c + num[idx], idx + 1, (state | 1 << 2));

	return A + B + C;
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		cin >> num[i];
		sum += num[i];
	}

	if (sum % 3) {
		cout << 0 << endl;
		return 0;
	}

	avg = sum / 3;

	cout << solve(0, 0, 0, 0, 0) << endl;
}
