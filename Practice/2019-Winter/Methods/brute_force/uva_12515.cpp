#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int M, Q; cin >> M >> Q;
	vector<string> v;
	v.resize(M);
	for (int i = 0; i < M; i ++)
		cin >> v[i];

	string cur;
	while (Q --) {
		cin >> cur;
		int Min = INF;
		int idx = 0;
		for (int i = 0; i < M; i ++) {
			if (v[i].size() < cur.size()) continue;
			int lim = v[i].size() - cur.size() + 1;
			int local_min = INF;
			for (int j = 0; j < lim; j ++) {
				int cnt = 0;
				for (int k = 0; k < cur.size(); k ++) {
					if (cur[k] != v[i][j + k]) cnt ++;
				}
				local_min = min(local_min, cnt);
			}
			if (local_min < Min) {
				Min = local_min;
				idx = i;
			}
		}
		cout << idx + 1 << '\n';
	}
}
