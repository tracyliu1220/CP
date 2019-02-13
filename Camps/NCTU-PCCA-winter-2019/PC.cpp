#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define MOD 998244353
typedef long long LL;

int n, m;
vector<int> G[MAX];
int sz[MAX];
LL cost[MAX];

int dfs(int cur, int p) {
	sz[cur] = 1;
	for (int i = 0; i < G[cur].size(); i ++) {
		if (G[cur][i] != p)
			sz[cur] += dfs(G[cur][i], cur);
	}
	return sz[cur];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T; while (T --) {
		cin >> n >> m;
		
		// init	
		for (int i = 0; i < n; i ++) 
			G[i].clear();
			
		// graph
		int u, v;
		for (int i = 0; i < n - 1; i ++) {
			cin >> u >> v; u --; v --;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		// find size
		dfs(0, 0);
		for (int i = 0; i < n; i ++)
			sz[i] = sz[i] * (n - sz[i]);
		
		for (int i = 0; i < m; i ++)
			cin >> cost[i];

		sort(cost, cost + m);
		sort(sz, sz + n);
		reverse(cost, cost + m);

		// greedy
		LL ans = 0;
		for (int i = 0; i < m; i ++)
			ans += sz[i + 1] * cost[i] % MOD;	

		cout << ans << '\n';
	}
}
