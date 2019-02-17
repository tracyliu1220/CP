#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int tmp, cnt = 0;
	while (n --) {
		cin >> tmp;
		if (tmp < 0) cnt ++;
	}
	cout << cnt << '\n';
}
