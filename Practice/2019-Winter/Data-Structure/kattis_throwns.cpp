#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	stack<int> state;
	state.push(0);

	string str;
	int tar;

	while (m --) {
		cin >> str;
		if (str[0] == 'u') {
			int x; cin >> x;
			while (x --)
				state.pop();
		} else {
			stringstream ss;
			ss << str;
			ss >> tar;
			int nxt = state.top() + tar;
			while (nxt < 0) nxt += n;
			nxt %= n;
			state.push(nxt);
		}
	}

	cout << state.top() << '\n';
}
