#include <bits/stdc++.h>
using namespace std;

int n, B, k;
int cnt[10];
struct order {
	int s, t, p;
	int e; //earn
};
vector<order> orders(25);
int ans = 0;

void solve(int idx, int sum) {
	ans = max(ans, sum);
	for (int i = idx; i < k; i ++) {
		order cur = orders[i];
		int legal = 1;
		for (int i = cur.s; i < cur.t; i ++)
			if (cnt[i] + cur.p > n) legal = 0;
		if (legal) {
			for (int i = cur.s; i < cur.t; i ++) 
				cnt[i] += cur.p;
			solve(i + 1, sum + cur.e);
			for (int i = cur.s; i < cur.t; i ++)
				cnt[i] -= cur.p;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> n >> B >> k && (n || B || k)) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < k; i ++) {
			cin >> orders[i].s >> orders[i].t >> orders[i].p;
			orders[i].e = (orders[i].t - orders[i].s) * orders[i].p;
		}
		ans = 0;
		solve(0, 0);
		cout << ans << '\n';
	}
}
