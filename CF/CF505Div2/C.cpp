#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int n = s.size();

	s = s + s;

	int Max = 0;
	int sum = 1;

	for (int i = 1; i < s.size() ; i ++) {
		if (s[i] != s[i - 1]) sum ++;
		else {
			Max = max(Max, sum);
			sum = 1;
		}
	}

	Max = max(Max, sum);
	if (Max > n) Max = n;

	cout << Max << endl;

}
