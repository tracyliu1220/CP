#include <bits/stdc++.h>
using namespace std;

bool adj[9][9];
bool visit[9];

void DFS(int i) {
	for (int j = 0; j < 9; j ++)
		if (adj[i][j] && !visit[j]) {
			visit[j] = true;
			DFS(j);
		}
}

void traversal() {
	for (int i = 0; i < 9; i ++)
		visit[i] = false;

	for (int i = 0; i < 9; i ++)
		if (!visit[i]) {
			visit[i] = true;
			DFS(i);
		}
}

int main() {

}
