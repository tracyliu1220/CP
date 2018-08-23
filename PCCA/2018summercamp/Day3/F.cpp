#include <bits/stdc++.h>
using namespace std;

int graph[55][55] = {0};
int pre[10];
bool vis[55] = {0};
int n, m, x;
vector<int> ans;

bool BFS(int s, int t) {
	queue<int> que;
	memset(pre, -1, sizeof(pre));
	memset(vis, false, sizeof(vis));
	pre[s] = s;
	vis[s] = true;
	que.push(s);

	int current;
	while (!que.empty()) {
		current = que.front();
		que.pop();

		for (int i = 1; i <= n; i ++) {
			if (graph[current][i] > 0 && !vis[i]) {
				pre[i] = current;
				vis[i] = true;
				if (i == t) return true;
				que.push(i);
			}
		}
	}
	return false;
}

int EK(int s, int t) {
	int maxflow = 0, d;
	while (BFS(s, t)) {
		d = INT_MAX;
		for (int i = t; i != s; i = pre[i])
			d = min(d, graph[pre[i]][i]);
		for (int i = t; i != s; i = pre[i]) {
			graph[pre[i]][i] -= d;
			graph[i][pre[i]] += d;
		}
		maxflow += d;
		ans.push_back(d);
	}
	return maxflow;
}

int main() {
	cin >> n >> m >> x;
	int a, b;
	for (int i = 0; i < m; i ++) {
		cin >> a >> b;
		cin >> graph[a][b];
	}

	int maxflow = EK(1, n);
	int A = x / maxflow;
	int bears = x % maxflow;

	vector<double> v(ans.size());
	for (int i = 0; i < v.size(); i ++) {
		v[i] = A * ans[i];
	}


	for (int i = 0; i < bears; i ++) {
		int Maxidx = 0;
		for (int j = 0; j < v.size(); j ++) {
			if (ans[j] / (v[j] + 1.0) > ans[Maxidx] / (v[Maxidx] + 1.0))
				Maxidx = j;
		}
		v[Maxidx] ++;
	}

	int Ans = 0;
	for (int i = 0; i < v.size(); i ++) {
		if(v[i] && ans[i] / (double)v[i] < ans[Ans] / (double)v[Ans]) Ans = i;
	}
	printf("%.8f\n", ans[Ans] / v[Ans] * x);
}
