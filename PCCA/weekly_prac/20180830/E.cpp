//read: 	16:15
//start:	16:18
//submit:	16:45
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(4, vector<int>(5000));

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;

	while (cases --) {
		
		int n;
		cin >> n;
		for (int i = 0; i < n; i ++)
			for (int k = 0; k < 4; k ++)
				cin >> v[k][i];

		unordered_map<int, int> m;
		int ans = 0;

		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++) {
				m[v[0][i] + v[1][j]] ++;
			}

		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++) {
				if (m.count(-(v[2][i] + v[3][j]))) 
					ans += m[-(v[2][i] + v[3][j])];
			}

		cout << ans << endl;
		if (cases) cout << endl;
		m.clear();
	}


}
