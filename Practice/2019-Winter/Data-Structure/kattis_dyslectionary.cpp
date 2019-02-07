#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	vector<string> v;
	int len = 0;
	int state = 0;

	while (getline(cin, str)) {
		if (str.size() == 0) {
			for (int i = 0; i < v.size(); i ++) {
				int size = v[i].size();
				for (int j = 0; j < len - size; j ++) {
					v[i] = v[i] + ' ';
				}
			}
			sort(v.begin(), v.end());

			if (state) cout << '\n';
			state = 1;

			for (int i = 0; i < v.size(); i ++) {
				reverse(v[i].begin(), v[i].end());
				cout << v[i] << '\n';
			}
			v.clear();
			len = 0;
			continue;
		}
		reverse(str.begin(), str.end());
		v.push_back(str);
		len = max(len, (int)str.size());
	}	
	for (int i = 0; i < v.size(); i ++) {
		int size = v[i].size();
		for (int j = 0; j < len - size; j ++) {
			v[i] = v[i] + ' ';
		}
	}
	sort(v.begin(), v.end());

	if (state) cout << '\n';
	state = 1;

	for (int i = 0; i < v.size(); i ++) {
		reverse(v[i].begin(), v[i].end());
		cout << v[i] << '\n';
	}
	v.clear();
	len = 0;

}
