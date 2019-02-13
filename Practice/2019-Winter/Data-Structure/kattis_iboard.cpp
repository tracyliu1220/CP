#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	while (getline(cin, str)) {
		int cnt0 = 0, cnt1 = 0, cnt;
		for (int i = 0; i < str.size(); i ++) {
			int cur = (int)str[i];
			cnt = __builtin_popcount(cur);
			cnt0 += 7 - cnt;
			cnt1 += cnt;
		}
		if (cnt0 % 2 == 0 && cnt1 % 2 == 0)
			cout << "free\n";
		else
			cout << "trapped\n";
	}
}
