#include <bits/stdc++.h>
using namespace std;

int n, m, k, a;
int day[1000005] = {0};
const int days = 1000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i ++) {
		cin >> a;
		day[a] = 1;
	}

	int lim = days - m + 2;
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < m; i ++) {
		if (sum == k - 1 && day[i]) {
			cnt ++;
			day[i] = 0;
		}
		sum += day[i];
	}
	for (int i = 1; i < lim; i ++) {
		int add = day[i + m - 1] - day[i - 1];
		if (sum + add >= k) {
			day[i + m - 1] = 0;
			cnt ++;
		}
		sum += day[i + m - 1] - day[i - 1];
	}
	cout << cnt << '\n';
}
