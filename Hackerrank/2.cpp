#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;

/*
struct node {
	int p;
	int a = 0;
	bool operator<(node n1, node n2) {
		if (n1.a < n2.a) return true;
		else return false;
	}
};
*/

pair<int, int> nodes[300005]; //first:a, second:p
vector<int> aj[300005];

int find(int x) {
	int _x = x;
	while (_x != nodes[_x].second) _x = find(nodes[_x].second);
	return nodes[x].second = _x;
}

/*
bool compare(node a, node b) {
	if (a.a < b.a) return true;
	else return false;
}
*/

int main() {

	cin >> n >> m >> a >> b;

	for (int i = 0; i < n; i ++) 
		nodes[i].second = i;

	int u, v;
	for (int i = 0; i < m; i ++) {
		cin >> u >> v;
		u--; v--;
		int pu = find(u), pv = find(v);
		nodes[pv].second = pu;
		nodes[u].first ++;
		nodes[v].first ++;
	}

	for (int i = 0; i < n; i ++) {
		int p = find(i);
		int tmp = nodes[i].first;
		aj[p].push_back(tmp);
	}

	int cnt = 0;
	int L, tar;
	//vector<int>::iterator R;
	int R;

	for (int i = 0; i < n; i ++) {
		/*
		cout << "*" << aj[i].size() << endl;
		for (int j = 0; j < aj[i].size(); j ++)
			cout << aj[i][j] << " ";
		cout << endl;
		*/
		if (!aj[i].size()) continue;
		sort(aj[i].begin(), aj[i].end());

		L = *(aj[i].begin()) * a;
		R = *(aj[i].end() - 1) * b;

		for (int j = 1; j < aj[i].size(); j ++)
			if (L < aj[i][j] && aj[i][j] < R) cnt ++;
		//cout << "L = " << L << endl;
		//R = upper_bound(aj[i].begin(), aj[i].end(), );
		//if (R == aj[i].end()) continue;
		//tar = (int)(aj[i].end() - R);
		//cnt += tar + 1;
	}

	cout << cnt << endl;
}
