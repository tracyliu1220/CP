#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> candy[2]; // 0:square 1:not
const int INF = 0x3f3f3f3f;

int check(int x) {
	int _x = (int)sqrt(x);
	if (_x * _x == x) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, tmp, t; cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> tmp;
		t = (int)sqrt(tmp);
		if (t * t == tmp) {
			candy[0].push_back(tmp);
		} else {
			candy[1].push_back(tmp);
		}
	}

	if (candy[0].size() == candy[1].size()) {
		cout << 0 << '\n';
		return 0;
	}

	int r;
	if (candy[0].size() > n / 2) r = 0;
	if (candy[1].size() > n / 2) r = 1;

	vector<int> cost;
	if (r == 0) { //square to not square
		for (int i = 0; i < candy[0].size(); i ++) {
			int x = candy[0][i];
			int add1 = 0, add2 = 0;
			while (check(x + add1)) add1 ++;
			while (check(x - add2) && x - add2 >= 0) add2 ++;
			if (x <= 1) add2 = INF;
			cost.push_back(min(add1, add2));
		}
	} else {
		for (int i = 0; i < candy[1].size(); i ++) {
			int x = candy[1][i];
			int add1 = 0, add2 = 0;
			int _x = sqrt(x);
			add1 = x - _x * _x;
			add2 = (_x + 1) * (_x + 1) - x;
			cost.push_back(min(add1, add2));
		}
	}
	sort(cost.begin(), cost.end());
	LL sum = 0;
	for (int i = 0; i < candy[r].size() - n / 2; i ++)
		sum += cost[i];
	cout << sum << '\n';

}
