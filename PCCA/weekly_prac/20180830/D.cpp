//read:		15:40
//start:	15:41	
//submit:	15:45
#include <bits/stdc++.h>
using namespace std;

map<int, int> dp;

int F(int r) {
	if (dp.count(r)) return dp[r];
	
	if (r == 1) return 1;
	if (r == 2) return 2;

	return dp[r] = F(r - 1) + F(r - 2);
}

int main() {

	int n;
	
	while (cin >> n && n)
		cout << F(n) << endl;

}
