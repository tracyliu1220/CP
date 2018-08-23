#include <bits/stdc++.h>
using namespace std;

int main() {
	int cases;
	cin >> cases;

	while (cases --) {
		string s;
		cin >> s;

		int sum = 0;
		for (int i = 0; i < s.length(); i ++) {
			sum *= 10;
			sum += s[i] - '0';
			sum %= 6;
		}

		if (sum == 0) cout << "Nim" << endl;
		else cout << "Sam" << endl;

	}
}
