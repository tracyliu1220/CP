#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> _front, _right;
vector<int> checkf, checkr;
vector<vector<int> > check;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T; cin >> T; while (T --) {
		cin >> n;
		_front.clear(); _front.resize(n);
		_right.clear(); _right.resize(n);
		checkf.clear(); checkf.resize(n);
		checkr.clear(); checkr.resize(n);
		check.clear(); check.resize(n);
		for (int i = 0; i < n; i ++)
			check[i].resize(n);

		for (int i = 0; i < n; i ++) cin >> _front[i];
		for (int i = 0; i < n; i ++) cin >> _right[i];

		int lower = 0, upper = 0;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				if (_front[i] == _right[j] && !checkr[j]) {
					lower += _front[i];
					check[i][j] = 1;
					checkf[i] = checkr[j] = 1;
					break;
				}
			}
		}

		for (int i = 0; i < n; i ++) {
			if (!checkf[i]) lower += _front[i];
			if (!checkr[i]) lower += _right[i];
		}
		
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
					upper += min(_front[i], _right[j]);
			}
		}

		cout << "Matty needs at least " << lower << " blocks, and can add at most " << upper - lower << " extra blocks.\n";
			
	}	
}
