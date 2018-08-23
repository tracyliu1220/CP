#include <bits/stdc++.h>
using namespace std;

bool adj[9][9];

int DFS(int x, int px) {
	int h = 0;
	for (int y = 0; y < 9; y ++)
		if (adj[x][y] && y != px) h = max(h, DFS(y, x) + 1);
	return h;
}

void tree_height(int root) {
	cout << DFS(root, root) << endl;
}

int main() {

}
