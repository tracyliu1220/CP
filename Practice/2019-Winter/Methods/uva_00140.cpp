#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define F first
#define S second
#define MAX 1e9

vector<pii> E;
vector<int> exist;
map<pii, int> recordE;
map<int, int> rexist;
int pos[30];
const int INF = 0x3f3f3f3f;

int c_to_i(char ch) {
	return (int)(ch - 'A');
}

char i_to_c(int i) {
	return (char)('A' + i);
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string str;
	while (cin >> str && str != "#") {
		E.clear(); exist.clear();
		recordE.clear(); rexist.clear();
		for (int i = 0; i < str.size(); i ++) {
			int idx = c_to_i(str[i]);
			if ('A' <= str[i] && str[i] <= 'Z' && !rexist.count(idx)) {
				exist.push_back(idx);
				rexist[idx] = 1;
			}
		}

		for (int i = 0; i < str.size(); i ++) {
			int S = c_to_i(str[i]);
			i += 2;
			while (str[i] != ';' && i < str.size()) {
				int t = (int)(str[i] - 'A');
				int s = S;
				if (s > t) {
					int tmp = s;
					s = t;
					t = tmp;
				}
				pii tmp = {s, t};
				if (!recordE.count(tmp)) {
					E.push_back(tmp);
					recordE[tmp] = 1;
				}
				i ++;
			}
		}

		/*
		for (int i = 0; i < E.size(); i ++)
			cout << E[i].F << ' ' << E[i].S << '\n';

		for (int i = 0; i < exist.size(); i ++)
			cout << exist[i] << '\n';
		*/

		int n = exist.size();
		int m = E.size();
		sort(exist.begin(), exist.end());

		int ans = INF;
		vector<int> Ans(exist);

		do {
			for (int i = 0; i < n; i ++) {
				pos[exist[i]] = i;
			}
			int Max = 0;

			for (int i = 0; i < m; i ++) {
				Max = max(Max, abs(pos[E[i].F] - pos[E[i].S]));
			}
			if (Max < ans) {
				Ans.clear();
				for (int i = 0; i < n; i ++) {
					Ans.push_back(exist[i]);
				}
				ans = Max;
			}
		} while (next_permutation(exist.begin(), exist.end()));

		for (int i = 0; i < n; i ++)
			cout << i_to_c(Ans[i]) << ' ';
		cout << "-> ";
		cout << ans << '\n';
	}	
}
