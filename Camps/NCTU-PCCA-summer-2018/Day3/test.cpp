#include <bits/stdc++.h>
using namespace std;

int cap[105][105] = {0}, graph[105][105] = {0}, rgraph[105][105] = {0};
int pre[105];
bool vis[105] = {0};
int n;

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
			if (graph[current][i] > 0  && !vis[i] && rgraph[current][i] + rgraph[i][current] <= cap[current][i]) {
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
			rgraph[pre[i]][i] += d;
			// graph[i][pre[i]] -= d;
		}
		maxflow += d;
	}
	return maxflow;
}

int main() {
	int cases = 0;
	while (1) {

		memset(cap, 0, sizeof(cap));
		memset(graph, 0, sizeof(graph));
		memset(rgraph, 0, sizeof(rgraph));

		cin >> n;
		if (!n) break;
		int s, t, c;
		cin >> s >> t >> c;
		
		int a, b, wid;
		for (int i = 0; i < c; i ++) {
			cin >> a >> b >> wid;	
			cap[a][b] += wid;
			cap[b][a] += wid;
			graph[a][b] += wid;
			graph[b][a] += wid;
		}
		cases ++;
		cout << "Network " << cases << endl;
		cout << "The bandwidth is " << EK(s, t) << "." << endl;
		cout << endl;
	}
}
