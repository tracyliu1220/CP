#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	while (cin >> n) {
		v.clear(); v.resize(n);
		for (int i = 0; i < n; i ++)
			cin >> v[i];

		sort(v.begin(), v.end());

		if (n % 2) {
			int cnt1 = (int)(upper_bound(v.begin(), v.end(), v[n / 2]) - lower_bound(v.begin(), v.end(), v[n / 2]));
			cout << v[n / 2] << ' ' << cnt1 << ' ' << 1 << '\n';
		} else {
			int cnt1 = (int)(upper_bound(v.begin(), v.end(), v[n / 2]) - lower_bound(v.begin(), v.end(), v[n / 2 - 1]));
			int cnt2 = v[n / 2] - v[n / 2 - 1] + 1;
			cout << v[n / 2 - 1] << ' ' << cnt1 << ' ' << cnt2 << '\n';
		}
	}	
}
