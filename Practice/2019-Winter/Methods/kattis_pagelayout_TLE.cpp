#include <bits/stdc++.h>
using namespace std;

struct story {
	int w, h, x, y;
};

int G[1005][1005];
vector<story> v;
int n, ans = 0;

void solve(int idx, int sum) {
	ans = max(ans, sum);
	story cur = v[idx];
	for (int i = idx; i < n; i ++) {
		int legal = 1;
		for (int _x = cur.x; _x < cur.x + cur.w; _x ++) 
			for (int _y = cur.y; _y < cur.y + cur.h; _y ++) 
				if (G[_x][_y]) legal = 0;
		if (legal) {
			for (int _x = cur.x; _x < cur.x + cur.w; _x ++) 
				for (int _y = cur.y; _y < cur.y + cur.h; _y ++) 
					G[_x][_y] = 1;
			solve(i + 1, sum + cur.w * cur.h);
			for (int _x = cur.x; _x < cur.x + cur.w; _x ++) 
				for (int _y = cur.y; _y < cur.y + cur.h; _y ++) 
					G[_x][_y] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> n && n) {
		memset(G, 0, sizeof(G));
		v.clear(); v.resize(n);
		for (int i = 0; i < n; i ++) {
			cin >> v[i].w >> v[i].h >> v[i].x >> v[i].y;
		}
		ans = 0;
		solve(0, 0);
		cout << ans << '\n';
	}
}
