#include <bits/stdc++.h>
using namespace std;
#define MAX 10005
#define F first
#define S second
typedef pair<int, int> pii;

vector<pii> G[MAX];
int d[MAX];
const int INF = 0x3f3f3f3f;

int main() {
	int ans = 0, Min = INF;
	int T = 2;

	int n, t, m;
	while (T --) {
		cin >> n >> t >> m;
		for (int i = 0; i < n; i ++)
			G[i].clear();
		
		int tar;
		vector<int> target;
		for (int i = 0; i < t; i ++) {
			cin >> tar; tar --;
			target.push_back(tar);
		}

		int u, v, c;
		for (int i = 0; i < m; i ++) {
			cin >> u >> v >> c; u --; v --;
			G[u].push_back(pii(v, c));
			G[v].push_back(pii(u, c));
		}

		for (int i = 0; i < t; i ++) {
			int s = target[i];
			memset(d, INF, sizeof(d));
			d[s] = 0;

			priority_queue<pii, vector<pii>, greater<pii>> q;
			q.push(pii(0, s));

			int cur, dist, localmax = 0;
			while(q.size()) {
				cur = q.top().S; dist = q.top().F; q.pop();
				if (dist > d[cur]) continue;
				for (int i = 0; i < G[cur].size(); i ++) {
					pii nxt = G[cur][i];
					if (d[nxt.F] > d[cur] + nxt.S) {
						d[nxt.F] = d[cur] + nxt.S;
						q.push(pii(d[nxt.F], nxt.F));
						localmax = max(localmax, d[nxt.F]);
					}
				}
			}

			Min = min(Min, localmax);
		}


		ans += Min;
	}

	cout << ans + 1000 << '\n';


}
