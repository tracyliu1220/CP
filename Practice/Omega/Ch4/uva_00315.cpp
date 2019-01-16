#include <bits/stdc++.h>
using namespace std;

int n;

int G[105][105];
int dfn[105];
int low[105];
int vis[105];

void dfs(int u) {
	int child = 0;
	int cnt = 0;

	dfn[u] = low[u] = ++cnt;

	stack<int> st; st.push(u);

	while (st.size()) {
		int cur = st.top(); st.pop();
		if (!vis[cur]) {
			child ++;
			p[cur] = u;


		}
	}
}

int main() {

	while (cin >> n && n) { //1 base!!
		
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		string str;
		
		while (getline(cin, str) && str[0] != '0') {
			stringstream ss(str);
			int a, b;
			ss >> a;
			while (ss >> b) {
				G[a][b] = G[b][a] = 1;
			}
		}

	}


}
