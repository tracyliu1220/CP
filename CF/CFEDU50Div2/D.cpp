#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int A[300005], B[300005];

	cin >> n;
	for (int i = 0; i < n; i ++) cin >> A[i];
	cin >> m;
	for (int i = 0; i < m; i ++) cin >> B[i];

	int a = 1, b = 1;
	int cnt = 0;

	LL sumA = A[0], sumB = B[0];

	while (a < n && b < m) {
		if (sumA == sumB) {
			cnt ++; sumA = A[a]; sumB = B[b];
			a++; b++;
		} else if (sumA < sumB) {
			sumA += A[a]; a++;
		} else {
			sumB += B[b]; b++;
		}

	}

	while (a < n) sumA += A[a++];
	while (b < m) sumB += B[b++];

	if (sumA == sumB) cnt++;
	else cnt = 0;

	if (cnt) cout << cnt << endl;
	else cout << -1 << endl;
}
