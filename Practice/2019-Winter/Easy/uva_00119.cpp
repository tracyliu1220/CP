#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
vector<string> name;
int own[20];

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int state = 0;
	int n; while (cin >> n) {
		m.clear(); name.clear();
		memset(own, 0, sizeof(own));
		string str;
		for (int i = 0; i < n; i ++) {
			cin >> str;
			m[str] = i;
			name.push_back(str);
		}
		int x, a;
		for (int i = 0; i < n; i ++) {
			cin >> str;
			int idx = m[str];
			cin >> x >> a;
			if (x && a) {
				x -= x % a;
				own[idx] -= x;
				x /= a;
			}
			for (int i = 0; i < a; i ++) {
				cin >> str;
				if (x && a) own[m[str]] += x;
			}
		}
		if (state) cout << '\n';
		state = 1;
		for (int i = 0; i < n; i ++) {
			cout << name[i] << ' ' << own[i] << '\n'; 
		}
	}
}
