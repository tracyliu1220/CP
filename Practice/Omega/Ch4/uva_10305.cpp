#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt[105];
deque<int> g[105];
int vis[105];
int total;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> m) {

		if (n == 0 && m == 0) break;
		
		memset(cnt, 0, sizeof(cnt));
		memset(vis, 0, sizeof(vis));
		total = n;

		int a, b;
		for (int i = 0; i < m; i ++) {
			cin >> a >> b;
			g[a].push_back(b);
			cnt[b] ++;
		}

		for (int i = 1; i <= n; i ++) {
			if (!cnt[i] && !vis[i]) {
				cout << i << (total == 1 ? '\n':' ');
				for (int j = 0; j < g[i].size(); j ++)
					cnt[g[i][j]] --;
				g[i].clear();
				vis[i] = 1;
				total --;
			}
			
			if (!total) break;
			else if (i == n) i = 0;
		}



	}

}
