#include <bits/stdc++.h>
using namespace std;

int to_e(int p) {
	int e = 0;
	e += min(max(0, p / 2), 100); p -= 2 * 100;
	e += min(max(0, p / 3), 9900); p -= 3 * 9900;
	e += min(max(0, p / 5), 990000); p -= 5 * 990000;
	e += max(0, p / 7);
	return e;
}

int to_p(int e) {
	int p = 0;
	p += min(max(0, e * 2), 2 * 100); e -= 100;
	p += min(max(0, e * 3), 3 * 9900); e -= 9900;
	p += min(max(0, e * 5), 5 * 990000); e -= 990000;
	p += max(0, e * 7);
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int A, B; while (cin >> A >> B && (A || B)) {
		int total = to_e(A);
		int L = 0, R = total + 1, M;
		int ans = 0;
		while (R - L > 1) {
			M = (R + L) / 2;
			int diff = to_p(total - M) - to_p(M);
			if (diff >= B) L = M;
			else R = M;
		}
		cout << to_p(L) << '\n';
	}

}
