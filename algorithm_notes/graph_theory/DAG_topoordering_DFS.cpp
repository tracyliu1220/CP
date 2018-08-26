#include <bits/stdc++.h>
using namespace std;

bool adj[9][9];
int visit[9];
int order[9], n;

bool cycle;

void DFS(int s) {
	if (visit[s] == 1) {cycle = true; return;}
	if (visit[s] == 2) return;

	visit[s] = 1;
	for (int t = 0; t < 9; t ++)
		if (adj[s][t]) DFS(t);
	visit[s] = 2;

	order[n--] = s;
}

void topological_ordering() {
	// init
	for (int i = 0; i < 9; i ++) visit[i] = 0;
	cycle = false;
	n = 9 - 1;

	for (int s = 0; s < 9; s ++)
		if (!v[s]) DFS(s);

	if (cycle) cout << "cycle.";
	else
		for (int i = 0; i < 9; i ++) cout << order[i];

	cout << endl;
}

int main() {

}
