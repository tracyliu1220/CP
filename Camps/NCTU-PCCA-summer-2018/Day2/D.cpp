#include <bits/stdc++.h>
using namespace std;
#define MAX 200005

int in1[MAX], in2[MAX], out[MAX];
int vis[MAX] = {0};
int t = 0, t_out = 0;

vector<vector<int>> v;

void DFS(int current) {
	vis[current] = 1;
	in1[current] = t;
	in2[t ++] = current;

	for (int i = 0; i < v[current].size(); i ++) {
		if (!vis[v[current][i]]) {
			DFS(v[current][i]);
		}
	}
	out[current] = t_out ++;
}

int main() {
	int n, q;
	cin >> n >> q;

	v.resize(n);

	int parent;
	for (int i = 1; i < n; i ++) {
		cin >> parent;
		parent --;
		v[parent].push_back(i);
	}	

	DFS(0);

	int com, pri;
	while (q --) {
		cin >> com >> pri;
		com --;

		int tar = in2[in1[com] + pri - 1];

		if (in1[com] + pri - 1 > n - 1 || out[tar] > out[com])
			cout << -1 << endl;
		else
			cout << tar + 1 << endl;
	}
}

