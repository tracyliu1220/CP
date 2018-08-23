#include <bits/stdc++.h>
using namespace std;

int n, avg = 0, flag = 1, root;
vector<int> ans;

struct lamp {
	int value;
	vector<int> child;
};

vector<lamp> L;

int DFS(int id) {
	int sum = L[id].value;
	for (int i = 0; i < L[id].child.size(); i ++) {
		sum += DFS(L[id].child[i]);
	}

	if (sum == avg) {
		if (id != root)
			ans.push_back(id);
		return 0;
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	L.resize(n + 1);
	int p, t;

	for (int i = 1; i < n + 1; i ++) {
		cin >> p >> t;
		if (p) L[p].child.push_back(i);
		else root = i;
		L[i].value = t;
		avg += t;
	}

	if (avg % 3 != 0) flag = 0;
	avg /= 3;

	DFS(root);

	if (flag && ans.size() >= 2)
		cout << ans[0] << " " << ans[1] << endl;
	else cout << -1 << endl;
}
