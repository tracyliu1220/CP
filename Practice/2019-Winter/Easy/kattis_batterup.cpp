#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int cnt = 0, sum = 0;
	int tmp;
	while (n --) {
		cin >> tmp;
		if (tmp == -1) continue;
		cnt ++;
		sum += tmp;
	}
	cout << fixed << setprecision(10) << sum / (cnt + 0.0) << '\n';
}
