#include <bits/stdc++.h>
using namespace std;

bool adj[9][9];
int depth[9];

void DFS(int x, int px) {
	for (int y = 0; y < 9; y ++) {
		if (adj[x][y] && y != px) {
			depth[y] = depth[x] + 1;
			DFS(y, x);
		}
	}
}

void tree_depth(int root) {
	depth[root] = 0;
	DFS(root, root);
	for (int i = 0; i < 9; i ++)
		cout << "depth of " << i << ": " << depth[i] << endl;
}

int main() {

}
