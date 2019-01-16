#include <bits/stdc++.h>
using namespace std;

map<int, int> dp;
vector<int> S;
int sg[10005];

int DFS(int cur) {
	cout << cur << endl;
	if (cur == 0) return 0;
	if (dp.count(cur)) return dp[cur];
	memset(sg, -1, sizeof(sg));
	int flag = 0;
	for (int i = 0; i < S.size(); i ++) {
		if (S[i] <= cur) {
			sg[DFS(cur - S[i])] = 0;
			flag = 1;
		}
	}
	cout << "flag = " << flag << endl;
	if (!flag) return 0;
	int ans = 0;
	for (int i = 0; i < 10001; i ++)
		if (sg[i]) {ans = i; break;}
	return dp[cur] = ans; 
}

int main() {
	int k = 0;

	while (cin >> k && k) {
		S.resize(k);
		for (int i = 0; i < k; i ++) 
			cin >> S[i];
		
		int m;
		cin >> m;

		for (int i = 0; i < m; i ++) {
			int l;
			cin >> l;
			
			int XOR = 0;

			for (int j = 0; j < l; j ++) {
				int cur;
				cin >> cur;
				cout << "before DFS" << endl;
				XOR ^= DFS(cur);

			}
			if (!XOR) cout << "L";
			else cout << "W";
		}
		cout << endl;
		dp.clear();
		S.clear();
	}
}
