#include <bits/stdc++.h>
using namespace std;

char C[4] = {'A', 'C', 'G', 'T'};
int N, K;
vector<string> ans;

void solve(int idx, string str, int n, int k) {
	if (idx == n) {
		ans.push_back(str);
		return;
	}
	string tmp;
	for (int i = 0; i < 4; i ++) {
		tmp = str;
		if (tmp[idx] == C[i]) {
			solve(idx + 1, tmp, n, k);
		} else if (str[idx] != C[i] && k > 0) {
			tmp[idx] = C[i];
			solve(idx + 1, tmp, n, k - 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T; cin >> T; while (T --) {
		cin >> N >> K;
		string s; cin >> s;
		ans.clear();
		solve(0, s, N, K);
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i ++)
			cout << ans[i] << '\n';
	}	
}
