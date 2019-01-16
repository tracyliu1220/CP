#include <bits/stdc++.h>
using namespace std;

int main() {

	int p[26] = {0};

	int n;
	cin >> n;

	string s;
	cin >> s;

	int flag = 0;

	for (int i = 0; i < n; i ++) {
		p[s[i] - 'a'] ++;
	}

	for (int i = 0; i < 26; i ++)
		if (p[i] > 1) flag = 1;

	if (flag || n == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
}
