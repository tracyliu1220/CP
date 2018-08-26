#include <bits/stdc++.h>
using namespace std;
#define MAX 205

int n, m; //point, edge
int e[MAX][MAX];
int vis[MAX];
int color[MAX]; //0, 1, 2
int cnt[3];

int BFS(int idx) {
	vis[idx] = 1;
	color[idx] = 1;
	queue<int> q;
	q.push(idx);
	cnt[1] = 1;
	cnt[2] = 0;

	int flag = 0;
	for (int i = 0; i < n; i ++) {
		if (e[idx][i]) flag = 1;
	}
	if (!flag) return 2;

	int cur, clr;
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (int i = 0; i < n; i ++) {
			if (e[cur][i]) {
				if (!vis[i]) {
					vis[i] = 1;
					clr = 3 - color[cur];
					color[i] = clr;
					cnt[clr] ++;
					q.push(i);
				} else {
					if (color[cur] == color[i]) {
						// cout << cur << " " << i << endl;
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

int main() {
	int cases;
	cin >> cases;

	while (cases --) {
		cin >> n >> m;
		memset(e, 0, sizeof(e));
		memset(vis, 0, sizeof(vis));
		memset(color, 0, sizeof(color));

		int a, b;
		for (int i = 0; i < m; i ++) {
			cin >> a >> b;
			if(a != b) e[a][b] = e[b][a] = 1;
		}

		int ans = 0, flag = 1;
		for (int i = 0; i < n; i ++) {
			if (!vis[i]) {
				int tmp = BFS(i);
				if (tmp == 1) ans += min(cnt[1], cnt[2]);
				else if (tmp == 2) ans += 1;
				else {flag = 0;}
			}
		}

		if (flag) cout << ans << endl;
		else cout << -1 << endl;



	}
}
