//UVa442
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v(26);
stack<pair<int, int>> st;

int main() {

	cin >> n;
	char tar;

	for (int i = 0; i < n; i ++) {
		cin >> tar;
		cin >> v[(int)(tar - 'A')].first >> v[(int)(tar - 'A')].second;
	}

	string s;
	pair<int, int> first, second;
	int cur;

	while (cin >> s) {

		if ('A' <= s[0] && s[0] <= 'Z') {
			cout << 0 << endl;
			continue;
		}

		int ans = 0;
		int flag = 1;
		
		for (int i = 0; i < s.size(); i ++) {
			if ('A' <= s[i] && s[i] <= 'Z') {
				cur = (int)(s[i] - 'A');
				st.push(make_pair(v[cur].first, v[cur].second));
			}
			else if (s[i] == ')') {
				second = st.top(); st.pop();
				first = st.top(); st.pop();
				if (first.second != second.first) {
					flag = 0; break;
				}
				st.push(make_pair(first.first, second.second));
				ans += first.first * first.second * second.second;
			}
		}

		if (flag) cout << ans << endl;
		else cout << "error" << endl;

	}

}
