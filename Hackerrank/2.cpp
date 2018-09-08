#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;

struct node {
	int p;
	int a = 0;
};

node nodes[300005];
vector<vector<node> > aj[300005];

int find(int x) {
	int _x = x;
	while (_x != nodes[_x].p) _x = find(nodes[_x].p);
	return nodes[x].p = _x;
}

bool compare(node a, node b) {
	if (a.a < b.a) return true;
	else return false;
}

int main() {

	cin >> n >> m >> a >> b;

	for (int i = 0; i < n; i ++) 
		nodes[i].p = i;

	int u, v;
	for (int i = 0; i < m; i ++) {
		cin >> u >> v;
		int pu = find(u), pv = find(v);
		nodes[pv].p = pu;
	}
	
	node N;

	for (int i = 0; i < n; i ++) {
		int p = find(i);
		aj[p].push_back(nodes[i]);
	}

	int cnt = 0;
	int L, tar;
	vector<int>::iterator R;

	for (int i = 0; i < n; i ++) {
		if (!aj[i].size()) break;
		sort(aj[i].begin(), aj[i].end());
		L = aj[i].begin()->a * a;
		R = lower_bound(aj[i].begin(), aj[i].end(), L / b);
		if (R == aj[i].end()) continue;
		tar = (int)(R - aj[i].begin());
		cnt += tar + 1;
	}

	cout << cnt << endl;
}
