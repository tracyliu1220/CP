#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL tea[1005];
LL top[1005];
const LL INF = 0x3f3f3f3f3f3f3f3f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> tea[i];
	cin >> m;
	for (int i = 0; i < m; i ++)
		cin >> top[i];

	LL Min = INF;
	int t, tmp;
	for (int i = 0; i < n; i ++) {
		cin >> t;
		while (t --) {
			cin >> tmp; tmp --;
			Min = min(Min, tea[i] + top[tmp]);
		}
	}
	LL money; cin >> money;
	cout << max(0LL, money / Min - 1) << '\n';

}
