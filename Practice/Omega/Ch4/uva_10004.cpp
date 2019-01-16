#include <bits/stdc++.h>
using namespace std;
#define N 205

int n;
int e[N][N];
int visit[N];
int color[N];

int BFS(int idx) {
	
	memset(visit, 0, sizeof(visit));
	memset(color, 0, sizeof(color));
	queue<int> q;
	q.push(idx);
	visit[idx] = 1;

	int current;
	while (!q.empty()) {
		current = q.front(); q.pop();

		for (int i = 0; i < n; i ++) {
			if (e[current][i]) {
				if (visit[i]) {
					if (color[current] == color[i]) return 0;
				} else {
					color[i] = 1 - color[current];
					visit[i] = 1;
					q.push(i);
				}
			}
		}

	}
	return 1;
}

int main() {
	
	while (cin >> n && n) {
		int l;
		cin >> l;
		
		memset(e, 0, sizeof(e));

		int a, b;
		for (int i = 0; i < l; i ++) {
			cin >> a >> b;
			if (a != b) e[a][b] = e[b][a] = 1;
		}


		if (BFS(0)) cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;
	}

}
