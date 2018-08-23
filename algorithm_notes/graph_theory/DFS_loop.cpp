#include <bits/stdc++.h>
using namespace std;

bool adj[9][9]; //adjacency matrix
bool visit[9];

void BFS() {
	stack<int> q;
	for (int i = 0; i < 9; i ++) visit[i] = false;
	for (int k = 0; k < 9; k ++) {
		if (!visit[k]) {
			q.push(k);
			visit[k] = true;
			
			while (!q.empty()) {
				int i = q.front(); q.pop();

				for (int j = 0; j < 9; j ++) {
					if (adj[i][j] && !visit[j]) {
						q.push(j);
						visit[j] = true;
					}
				}
			}
		}
	}
}

int main() {

}
