#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	string s1, s2;
	cin >> s1 >> s2;

	int legal = 1;

	if (n % 2) {
		for (int i = 0; i < s1.size(); i ++) {
			if (!(s1[i] ^ s2[i]))
				legal = 0;
		}
	} else { 
		if (s1 != s2) legal = 0;
	}
	
	if (legal) cout << "Deletion succeeded\n";
	else cout << "Deletion failed\n";
}
