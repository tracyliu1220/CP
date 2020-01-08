#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> paper;

double ans = 0;
int k;

void solve(int idx) {
	if (idx == n) return;
	if (k == 0) return;
	int reduce = min(paper[idx], k);
	k -= reduce;
	if (k != 0) ans += k * pow(2, -(idx * 2 + 1) / 4.0);
	k *= 2;
	solve(idx + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	paper.resize(n);
	for (int i = 1; i < n; i ++) {
		cin >> paper[i];
	}
	k = 2;
	solve(1);

	if (k)
		cout << "impossible\n";
	else
		cout << ans << '\n';

}
